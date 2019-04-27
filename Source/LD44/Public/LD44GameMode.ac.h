
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
bool ALD44GameMode::GetPlayerHasWon(){ return PlayerHasWon; }
void ALD44GameMode::SetPlayerHasWon(bool value){ PlayerHasWon = value; }
TMap<FString, FString> ALD44GameMode::GetLastCheckpointData(){ return LastCheckpointData; }
void ALD44GameMode::SetLastCheckpointData(TMap<FString, FString> value){ LastCheckpointData = value; }
TArray<FString> ALD44GameMode::GetLastCheckpointActors(){ return LastCheckpointActors; }
void ALD44GameMode::SetLastCheckpointActors(TArray<FString> value){ LastCheckpointActors = value; }

#include "LD44.h"
#include "GameFramework/GameModeBase.h"
#include "Containers/UnrealString.h"
#include "Public/LD44GameMode.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/Pawn.h"
#include "Private/LD44HUD.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"
#include "Public/EnemyRobot.h"
