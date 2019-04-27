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

prop(TMap<FString, FString> LastCheckpointData)
prop(TArray<FString> LastCheckpointActors)

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

}

void fun::RestoreCheckpoint()
{

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