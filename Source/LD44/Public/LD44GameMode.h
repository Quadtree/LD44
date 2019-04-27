#pragma once

#include "EngineMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LD44.h"
#include "LD44GameMode.generated.h"

UCLASS()
class LD44_API ALD44GameMode : public AGameModeBase
{
	GENERATED_BODY()
private:
	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetRespawning, BlueprintSetter=SetRespawning)
	bool Respawning;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetRespawnTimeLeft, BlueprintSetter=SetRespawnTimeLeft)
	float RespawnTimeLeft;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetPlayerWinsIfAllEnemiesDestroyed, BlueprintSetter=SetPlayerWinsIfAllEnemiesDestroyed)
	bool PlayerWinsIfAllEnemiesDestroyed;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetLevelTime, BlueprintSetter=SetLevelTime)
	float LevelTime;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetPlayerHasWon, BlueprintSetter=SetPlayerHasWon)
	bool PlayerHasWon;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetLastCheckpointData, BlueprintSetter=SetLastCheckpointData)
	TMap<FString, FString> LastCheckpointData;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetLastCheckpointActors, BlueprintSetter=SetLastCheckpointActors)
	TArray<FString> LastCheckpointActors;

public:
	ALD44GameMode();

	UFUNCTION(BlueprintCallable)
	void PlayerWins();

	void Tick(float deltaTime) override;

	UFUNCTION(BlueprintGetter, BlueprintPure)
	bool GetRespawning();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetRespawning(bool value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	float GetRespawnTimeLeft();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetRespawnTimeLeft(float value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	bool GetPlayerWinsIfAllEnemiesDestroyed();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetPlayerWinsIfAllEnemiesDestroyed(bool value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	float GetLevelTime();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetLevelTime(float value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	bool GetPlayerHasWon();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetPlayerHasWon(bool value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	TMap<FString, FString> GetLastCheckpointData();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetLastCheckpointData(TMap<FString, FString> value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	TArray<FString> GetLastCheckpointActors();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetLastCheckpointActors(TArray<FString> value);

};
