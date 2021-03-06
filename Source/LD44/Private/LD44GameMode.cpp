// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "LD44GameMode.h"
#include "LD44GameMode.ac.h"

extends(AGameModeBase)

prop(bool Respawning)
prop(float RespawnTimeLeft)

prop(bool PlayerWinsIfAllEnemiesDestroyed)

prop(float LevelTime)

prop(float LastCheckpointTime)

// flag to tell blueprints that the player has won the level
prop(bool PlayerHasWon)

prop(TMap<FString, FVector> LastCheckpointEnemyLocations)
prop(TMap<FString, float> LastCheckpointEnemyHealth)
prop(TMap<FString, float> LastCheckpointEnemyAggro)
prop(TMap<FString, float> LastCheckpointEnemyAutoAggro)
prop(TMap<FString, TSubclassOf<AEnemyRobot>> LastCheckpointEnemyType)

prop(TMap<EUpgradeType, int32> LastCheckpointPlayerUpgrades)
prop(float LastCheckpointPlayerHealth)
prop(float LastCheckpointPlayerEnergy)
prop(FVector LastCheckpointPlayerPosition)
prop(FRotator LastCheckpointPlayerControlRotation)
prop(TSubclassOf<ALD44Character> LastCheckpointPlayerSubclass)

prop(TArray<class UHighScoresRow*> HighScoresRows)

prop(float AutoCheckpointTime)
prop(float AutoCheckpointCharge)

prop(FText OpeningText)
prop(FText WinningText)
prop(FString NextLevel)

fun::ALD44GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ALD44HUD::StaticClass();

	PrimaryActorTick.bCanEverTick = true;
}

mods(bare) void fun::HighScoresReceived(TSharedPtr<class IHttpRequest> req, TSharedPtr<class IHttpResponse, ESPMode::ThreadSafe> resp, bool success)
{
	UE_LOG(LogTemp, Display, TEXT("Got HTTP response: %s"), *resp->GetContentAsString());

	TArray<TSharedPtr<FJsonValue>> obj;
	TSharedRef<TJsonReader<>> reader = TJsonReaderFactory<>::Create(resp->GetContentAsString());

	HighScoresRows.Empty();

	if (FJsonSerializer::Deserialize(reader, obj))
	{
		for (auto a : obj)
		{
			if (auto jo = a->AsObject())
			{
				auto io = NewObject<UHighScoresRow>();
				io->SetTime(jo->GetNumberField("TimeToFinish"));
				io->SetIsMe(jo->GetBoolField("IsMyScore"));
				io->SetHealth(jo->GetNumberField("Health"));

				TMap<EUpgradeType, int32> upgradeLevels;

				for (int32 i = 0; i < (int)EUpgradeType::UT_Max; ++i)
				{
					FString key = "Upg" + FString::FromInt(i);
					upgradeLevels.Add((EUpgradeType) i, jo->GetIntegerField(key));
				}

				io->SetUpgradeLevels(upgradeLevels);

				HighScoresRows.Add(io);
			}
		}
	}
}

void fun::PlayerWins()
{
	if (!PlayerHasWon)
	{
		ALD44Character* pc = nullptr;

		for (TActorIterator<ALD44Character> i(GetWorld()); i; ++i)
		{
			pc = *i;
			break;
		}

		if (pc)
		{
			UE_LOG(LogTemp, Display, TEXT("Player has won"));
			PlayerHasWon = true;
			UGameplayStatics::SetGamePaused(this, true);

			auto req = FHttpModule::Get().CreateRequest();

			req->OnProcessRequestComplete().BindUObject(this, &fun::HighScoresReceived);
			//req->SetURL("https://sigma.quadtree.info/dyn/lighttpd/ld/ld44/highscores.php");
			req->SetURL("https://quadtree.info/ld/ld44/highscores.php");
			req->SetVerb("POST");
			req->SetHeader("Content-Type", "application/x-www-form-urlencoded");
			req->SetContentAsString(
				"t=" + FString::SanitizeFloat(LevelTime) +
				"&l=" + UGameplayStatics::GetCurrentLevelName(this) +
				"&h=" + FString::SanitizeFloat(pc->GetHealth()) +
				"&u0=" + FString::FromInt(pc->GetUpgradeLevel((EUpgradeType) 0)) +
				"&u1=" + FString::FromInt(pc->GetUpgradeLevel((EUpgradeType) 1)) +
				"&u2=" + FString::FromInt(pc->GetUpgradeLevel((EUpgradeType) 2)) +
				"&u3=" + FString::FromInt(pc->GetUpgradeLevel((EUpgradeType) 3)) +
				"&u4=" + FString::FromInt(pc->GetUpgradeLevel((EUpgradeType) 4)) +
				"&u5=" + FString::FromInt(pc->GetUpgradeLevel((EUpgradeType) 5)) +
				"&u6=" + FString::FromInt(pc->GetUpgradeLevel((EUpgradeType) 6)) +
				"&u7=" + FString::FromInt(pc->GetUpgradeLevel((EUpgradeType) 7)) +
				"&u8=" + FString::FromInt(pc->GetUpgradeLevel((EUpgradeType) 8)) +
				"&u9=" + FString::FromInt(pc->GetUpgradeLevel((EUpgradeType) 9))
			);
			req->ProcessRequest();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Can't upload high score, player does not exist"));
		}
	}
}

void fun::PlayerHasDied()
{
	Respawning = true;
	RespawnTimeLeft = 2;
}

void fun::Checkpoint()
{
	UE_LOG(LogTemp, Display, TEXT("Checkpoint!"));

	ALD44Character* pc = nullptr;

	for (TActorIterator<ALD44Character> i(GetWorld()); i; ++i)
	{
		pc = *i;
		break;
	}

	if (pc)
	{
		for (int32 i = 0; i < (int32) EUpgradeType::UT_Max; ++i)
		{
			LastCheckpointPlayerUpgrades.Add((EUpgradeType) i, pc->GetUpgradeLevel((EUpgradeType) i));
		}

		LastCheckpointPlayerHealth = pc->GetHealth();
		LastCheckpointPlayerEnergy = pc->GetEnergy();
		LastCheckpointPlayerPosition = pc->GetActorLocation();
		LastCheckpointPlayerControlRotation = pc->GetControlRotation();
		LastCheckpointPlayerSubclass = pc->GetClass();

		LastCheckpointEnemyLocations.Empty();
		LastCheckpointEnemyHealth.Empty();
		LastCheckpointEnemyType.Empty();

		for (TActorIterator<AEnemyRobot> i(GetWorld()); i; ++i)
		{
			LastCheckpointEnemyLocations.Add(i->GetName(), i->GetActorLocation());
			LastCheckpointEnemyHealth.Add(i->GetName(), i->GetHealth());
			LastCheckpointEnemyAggro.Add(i->GetName(), i->GetAggro());
			LastCheckpointEnemyAutoAggro.Add(i->GetName(), i->GetAutoAggroTime());
			LastCheckpointEnemyType.Add(i->GetName(), i->GetClass());
		}

		LastCheckpointTime = LevelTime;
	}
	
	AutoCheckpointCharge = 0;
}

void fun::RestoreCheckpoint()
{
	UE_LOG(LogTemp, Display, TEXT("Restoring checkpoint"));

	for (TActorIterator<ALD44Character> i(GetWorld()); i; ++i)
	{
		i->Destroy();
	}

	for (TActorIterator<AEnemyRobot> i(GetWorld()); i; ++i)
	{
		i->Destroy();
	}

	for (TActorIterator<ALD44Projectile> i(GetWorld()); i; ++i)
	{
		i->Destroy();
	}

	for (TActorIterator<ASalvage> i(GetWorld()); i; ++i)
	{
		i->Destroy();
	}

	for (TActorIterator<AActor> i(GetWorld()); i; ++i)
	{
		if (i->FindComponentByClass<UParticleSystemComponent>()) i->Destroy();
	}

	FActorSpawnParameters params;
	params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	auto pc = GetWorld()->SpawnActor<ALD44Character>(LastCheckpointPlayerSubclass, LastCheckpointPlayerPosition, FRotator::ZeroRotator);
	if (pc)
	{
		for (int32 i = 0; i < (int32) EUpgradeType::UT_Max; ++i)
		{
			pc->SetUpgradeLevel((EUpgradeType) i, LastCheckpointPlayerUpgrades[(EUpgradeType) i]);
		}

		pc->SetHealth(LastCheckpointPlayerHealth);
		pc->SetEnergy(LastCheckpointPlayerEnergy);

		for (TActorIterator<APlayerController> i(GetWorld()); i; ++i)
		{
			i->Possess(pc);
			break;
		}

		if (pc->GetController())
		{
			pc->GetController()->SetControlRotation(LastCheckpointPlayerControlRotation);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Player doesn't seem to have a controller?"));
		}
	}

	for (auto name : LastCheckpointEnemyType)
	{
		auto en = GetWorld()->SpawnActor<AEnemyRobot>(name.Value, LastCheckpointEnemyLocations[name.Key], FRotator::ZeroRotator);
		if (en)
		{
			en->SpawnDefaultController();
			en->SetHealth(LastCheckpointEnemyHealth[name.Key]);
			en->SetAggro(LastCheckpointEnemyAggro[name.Key]);
			en->SetAutoAggroTime(LastCheckpointEnemyAutoAggro[name.Key]);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Enemy failed to spawn during checkpoint reload"));
		}
	}

	AutoCheckpointCharge = 0;
}

void fun::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	LevelTime += deltaTime;

	if (PlayerWinsIfAllEnemiesDestroyed)
	{
		int32 enemiesLeft = 0;

		for (TActorIterator<AEnemyRobot> i(GetWorld()); i; ++i)
		{
			++enemiesLeft;
		}

		if (enemiesLeft == 0)
		{
			PlayerWins();
		}
	}

	if (Respawning)
	{
		RespawnTimeLeft -= deltaTime;
		if (RespawnTimeLeft <= 0)
		{
			Respawning = false;
			RestoreCheckpoint();
		}
	}

	if (!LastCheckpointPlayerSubclass)
	{
		Checkpoint();
	}

	if (AutoCheckpointTime > 0)
	{
		AutoCheckpointCharge += deltaTime;
		if (AutoCheckpointCharge > AutoCheckpointTime)
		{
			Checkpoint();
		}
	}
}