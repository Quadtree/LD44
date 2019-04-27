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
prop(TMap<FString, TSubclassOf<AEnemyRobot>> LastCheckpointEnemyType)

prop(TMap<EUpgradeType, int32> LastCheckpointPlayerUpgrades)
prop(float LastCheckpointPlayerHealth)
prop(float LastCheckpointPlayerEnergy)
prop(FVector LastCheckpointPlayerPosition)
prop(FRotator LastCheckpointPlayerControlRotation)
prop(TSubclassOf<ALD44Character> LastCheckpointPlayerSubclass)

fun::ALD44GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ALD44HUD::StaticClass();

	PrimaryActorTick.bCanEverTick = true;
}

void fun::PlayerWins()
{
	if (!PlayerHasWon)
	{
		UE_LOG(LogTemp, Display, TEXT("Player has won"));
		PlayerHasWon = true;
		UGameplayStatics::SetGamePaused(this, true);
	}
}

void fun::PlayerHasDied()
{

}

void fun::Checkpoint()
{
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
			LastCheckpointPlayerUpgrades[(EUpgradeType)i] = pc->GetUpgradeLevel((EUpgradeType)i);
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
			LastCheckpointEnemyLocations[i->GetName()] = i->GetActorLocation();
			LastCheckpointEnemyHealth[i->GetName()] = i->GetHealth();
			LastCheckpointEnemyType[i->GetName()] = i->GetClass();
		}

		LastCheckpointTime = LevelTime;
	}
	
}

void fun::RestoreCheckpoint()
{
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
		pc->GetController()->SetControlRotation(LastCheckpointPlayerControlRotation);
	}

	for (auto name : LastCheckpointEnemyType)
	{
		auto en = GetWorld()->SpawnActor<AEnemyRobot>(name.Value, LastCheckpointEnemyLocations[name.Key], FRotator::ZeroRotator);
		en->SetHealth(LastCheckpointEnemyHealth[name.Key]);
	}
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
}