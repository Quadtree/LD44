#pragma once

#include "EngineMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "LD44.h"
#include "Public/UpgradeType.h"
#include "Templates/SharedPointerInternals.h"
#include "Engine/EngineTypes.h"
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

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetLastCheckpointTime, BlueprintSetter=SetLastCheckpointTime)
	float LastCheckpointTime;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetPlayerHasWon, BlueprintSetter=SetPlayerHasWon)
	bool PlayerHasWon;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetLastCheckpointEnemyLocations, BlueprintSetter=SetLastCheckpointEnemyLocations)
	TMap<FString, FVector> LastCheckpointEnemyLocations;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetLastCheckpointEnemyHealth, BlueprintSetter=SetLastCheckpointEnemyHealth)
	TMap<FString, float> LastCheckpointEnemyHealth;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetLastCheckpointEnemyAggro, BlueprintSetter=SetLastCheckpointEnemyAggro)
	TMap<FString, float> LastCheckpointEnemyAggro;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetLastCheckpointEnemyAutoAggro, BlueprintSetter=SetLastCheckpointEnemyAutoAggro)
	TMap<FString, float> LastCheckpointEnemyAutoAggro;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetLastCheckpointEnemyType, BlueprintSetter=SetLastCheckpointEnemyType)
	TMap<FString, TSubclassOf<AEnemyRobot>> LastCheckpointEnemyType;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetLastCheckpointPlayerUpgrades, BlueprintSetter=SetLastCheckpointPlayerUpgrades)
	TMap<EUpgradeType, int32> LastCheckpointPlayerUpgrades;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetLastCheckpointPlayerHealth, BlueprintSetter=SetLastCheckpointPlayerHealth)
	float LastCheckpointPlayerHealth;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetLastCheckpointPlayerEnergy, BlueprintSetter=SetLastCheckpointPlayerEnergy)
	float LastCheckpointPlayerEnergy;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetLastCheckpointPlayerPosition, BlueprintSetter=SetLastCheckpointPlayerPosition)
	FVector LastCheckpointPlayerPosition;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetLastCheckpointPlayerControlRotation, BlueprintSetter=SetLastCheckpointPlayerControlRotation)
	FRotator LastCheckpointPlayerControlRotation;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetLastCheckpointPlayerSubclass, BlueprintSetter=SetLastCheckpointPlayerSubclass)
	TSubclassOf<ALD44Character> LastCheckpointPlayerSubclass;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetHighScoresRows, BlueprintSetter=SetHighScoresRows)
	TArray<class UHighScoresRow*> HighScoresRows;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetAutoCheckpointTime, BlueprintSetter=SetAutoCheckpointTime)
	float AutoCheckpointTime;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetAutoCheckpointCharge, BlueprintSetter=SetAutoCheckpointCharge)
	float AutoCheckpointCharge;

public:
	ALD44GameMode();

	void HighScoresReceived(TSharedPtr<class IHttpRequest> req, TSharedPtr<class IHttpResponse, ESPMode::ThreadSafe> resp, bool success);

	UFUNCTION(BlueprintCallable)
	void PlayerWins();

	UFUNCTION(BlueprintCallable)
	void PlayerHasDied();

	UFUNCTION(BlueprintCallable)
	void Checkpoint();

	UFUNCTION(BlueprintCallable)
	void RestoreCheckpoint();

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
	float GetLastCheckpointTime();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetLastCheckpointTime(float value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	bool GetPlayerHasWon();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetPlayerHasWon(bool value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	TMap<FString, FVector> GetLastCheckpointEnemyLocations();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetLastCheckpointEnemyLocations(TMap<FString, FVector> value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	TMap<FString, float> GetLastCheckpointEnemyHealth();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetLastCheckpointEnemyHealth(TMap<FString, float> value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	TMap<FString, float> GetLastCheckpointEnemyAggro();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetLastCheckpointEnemyAggro(TMap<FString, float> value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	TMap<FString, float> GetLastCheckpointEnemyAutoAggro();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetLastCheckpointEnemyAutoAggro(TMap<FString, float> value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	TMap<FString, TSubclassOf<AEnemyRobot>>  GetLastCheckpointEnemyType();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetLastCheckpointEnemyType(TMap<FString, TSubclassOf<AEnemyRobot>> value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	TMap<EUpgradeType, int32> GetLastCheckpointPlayerUpgrades();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetLastCheckpointPlayerUpgrades(TMap<EUpgradeType, int32> value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	float GetLastCheckpointPlayerHealth();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetLastCheckpointPlayerHealth(float value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	float GetLastCheckpointPlayerEnergy();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetLastCheckpointPlayerEnergy(float value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	FVector GetLastCheckpointPlayerPosition();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetLastCheckpointPlayerPosition(FVector value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	FRotator GetLastCheckpointPlayerControlRotation();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetLastCheckpointPlayerControlRotation(FRotator value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	TSubclassOf<ALD44Character>  GetLastCheckpointPlayerSubclass();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetLastCheckpointPlayerSubclass(TSubclassOf<ALD44Character> value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	TArray<class UHighScoresRow*>  GetHighScoresRows();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetHighScoresRows(TArray<class UHighScoresRow*> value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	float GetAutoCheckpointTime();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetAutoCheckpointTime(float value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	float GetAutoCheckpointCharge();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetAutoCheckpointCharge(float value);

};
