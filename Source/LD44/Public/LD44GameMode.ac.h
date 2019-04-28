
#ifdef fun
    #undef fun
#endif

#define mods(...)
#define im(...)
#define blueprintEvent(...)
#define prop(...)
#define extends(...)
#define classMods(...)
#define fun         ALD44GameMode
bool ALD44GameMode::GetRespawning(){ return Respawning; }
void ALD44GameMode::SetRespawning(bool value){ Respawning = value; }
float ALD44GameMode::GetRespawnTimeLeft(){ return RespawnTimeLeft; }
void ALD44GameMode::SetRespawnTimeLeft(float value){ RespawnTimeLeft = value; }
bool ALD44GameMode::GetPlayerWinsIfAllEnemiesDestroyed(){ return PlayerWinsIfAllEnemiesDestroyed; }
void ALD44GameMode::SetPlayerWinsIfAllEnemiesDestroyed(bool value){ PlayerWinsIfAllEnemiesDestroyed = value; }
float ALD44GameMode::GetLevelTime(){ return LevelTime; }
void ALD44GameMode::SetLevelTime(float value){ LevelTime = value; }
float ALD44GameMode::GetLastCheckpointTime(){ return LastCheckpointTime; }
void ALD44GameMode::SetLastCheckpointTime(float value){ LastCheckpointTime = value; }
bool ALD44GameMode::GetPlayerHasWon(){ return PlayerHasWon; }
void ALD44GameMode::SetPlayerHasWon(bool value){ PlayerHasWon = value; }
TMap<FString, FVector> ALD44GameMode::GetLastCheckpointEnemyLocations(){ return LastCheckpointEnemyLocations; }
void ALD44GameMode::SetLastCheckpointEnemyLocations(TMap<FString, FVector> value){ LastCheckpointEnemyLocations = value; }
TMap<FString, float> ALD44GameMode::GetLastCheckpointEnemyHealth(){ return LastCheckpointEnemyHealth; }
void ALD44GameMode::SetLastCheckpointEnemyHealth(TMap<FString, float> value){ LastCheckpointEnemyHealth = value; }
TMap<FString, float> ALD44GameMode::GetLastCheckpointEnemyAggro(){ return LastCheckpointEnemyAggro; }
void ALD44GameMode::SetLastCheckpointEnemyAggro(TMap<FString, float> value){ LastCheckpointEnemyAggro = value; }
TMap<FString, float> ALD44GameMode::GetLastCheckpointEnemyAutoAggro(){ return LastCheckpointEnemyAutoAggro; }
void ALD44GameMode::SetLastCheckpointEnemyAutoAggro(TMap<FString, float> value){ LastCheckpointEnemyAutoAggro = value; }
TMap<FString, TSubclassOf<AEnemyRobot>> ALD44GameMode::GetLastCheckpointEnemyType(){ return LastCheckpointEnemyType; }
void ALD44GameMode::SetLastCheckpointEnemyType(TMap<FString, TSubclassOf<AEnemyRobot>> value){ LastCheckpointEnemyType = value; }
TMap<EUpgradeType, int32> ALD44GameMode::GetLastCheckpointPlayerUpgrades(){ return LastCheckpointPlayerUpgrades; }
void ALD44GameMode::SetLastCheckpointPlayerUpgrades(TMap<EUpgradeType, int32> value){ LastCheckpointPlayerUpgrades = value; }
float ALD44GameMode::GetLastCheckpointPlayerHealth(){ return LastCheckpointPlayerHealth; }
void ALD44GameMode::SetLastCheckpointPlayerHealth(float value){ LastCheckpointPlayerHealth = value; }
float ALD44GameMode::GetLastCheckpointPlayerEnergy(){ return LastCheckpointPlayerEnergy; }
void ALD44GameMode::SetLastCheckpointPlayerEnergy(float value){ LastCheckpointPlayerEnergy = value; }
FVector ALD44GameMode::GetLastCheckpointPlayerPosition(){ return LastCheckpointPlayerPosition; }
void ALD44GameMode::SetLastCheckpointPlayerPosition(FVector value){ LastCheckpointPlayerPosition = value; }
FRotator ALD44GameMode::GetLastCheckpointPlayerControlRotation(){ return LastCheckpointPlayerControlRotation; }
void ALD44GameMode::SetLastCheckpointPlayerControlRotation(FRotator value){ LastCheckpointPlayerControlRotation = value; }
TSubclassOf<ALD44Character> ALD44GameMode::GetLastCheckpointPlayerSubclass(){ return LastCheckpointPlayerSubclass; }
void ALD44GameMode::SetLastCheckpointPlayerSubclass(TSubclassOf<ALD44Character> value){ LastCheckpointPlayerSubclass = value; }
TArray<class UHighScoresRow*> ALD44GameMode::GetHighScoresRows(){ return HighScoresRows; }
void ALD44GameMode::SetHighScoresRows(TArray<class UHighScoresRow*> value){ HighScoresRows = value; }
float ALD44GameMode::GetAutoCheckpointTime(){ return AutoCheckpointTime; }
void ALD44GameMode::SetAutoCheckpointTime(float value){ AutoCheckpointTime = value; }
float ALD44GameMode::GetAutoCheckpointCharge(){ return AutoCheckpointCharge; }
void ALD44GameMode::SetAutoCheckpointCharge(float value){ AutoCheckpointCharge = value; }

#include "LD44.h"
#include "GameFramework/GameModeBase.h"
#include "Containers/UnrealString.h"
#include "UObject/NoExportTypes.h"
#include "Templates/SubclassOf.h"
#include "Public/EnemyRobot.h"
#include "Public/UpgradeType.h"
#include "Public/LD44Character.h"
#include "Public/HighScoresRow.h"
#include "Public/LD44GameMode.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/Pawn.h"
#include "Private/LD44HUD.h"
#include "Templates/SharedPointer.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "Templates/SharedPointerInternals.h"
#include "Dom/JsonValue.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"
#include "HttpModule.h"
#include "Public/LD44Projectile.h"
#include "Public/Salvage.h"
#include "Engine/World.h"
#include "Engine/EngineTypes.h"
#include "GameFramework/PlayerController.h"
