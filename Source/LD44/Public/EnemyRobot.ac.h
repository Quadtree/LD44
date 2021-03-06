
#ifdef fun
    #undef fun
#endif

#define mods(...)
#define im(...)
#define blueprintEvent(...)
#define prop(...)
#define extends(...)
#define classMods(...)
#define fun         AEnemyRobot
float AEnemyRobot::GetAttackDamage(){ return AttackDamage; }
void AEnemyRobot::SetAttackDamage(float value){ AttackDamage = value; }
float AEnemyRobot::GetAttackCharge(){ return AttackCharge; }
void AEnemyRobot::SetAttackCharge(float value){ AttackCharge = value; }
float AEnemyRobot::GetAttackDelay(){ return AttackDelay; }
void AEnemyRobot::SetAttackDelay(float value){ AttackDelay = value; }
float AEnemyRobot::GetNonProjectileAttackRange(){ return NonProjectileAttackRange; }
void AEnemyRobot::SetNonProjectileAttackRange(float value){ NonProjectileAttackRange = value; }
TSubclassOf<ALD44Projectile> AEnemyRobot::GetAttackProjectile(){ return AttackProjectile; }
void AEnemyRobot::SetAttackProjectile(TSubclassOf<ALD44Projectile> value){ AttackProjectile = value; }
float AEnemyRobot::GetAggro(){ return Aggro; }
void AEnemyRobot::SetAggro(float value){ Aggro = value; }
float AEnemyRobot::GetLineTestCharge(){ return LineTestCharge; }
void AEnemyRobot::SetLineTestCharge(float value){ LineTestCharge = value; }
bool AEnemyRobot::GetAttacking(){ return Attacking; }
void AEnemyRobot::SetAttacking(bool value){ Attacking = value; }
float AEnemyRobot::GetHealth(){ return Health; }
void AEnemyRobot::SetHealth(float value){ Health = value; }
TSubclassOf<ASalvage> AEnemyRobot::GetSalvageClass(){ return SalvageClass; }
void AEnemyRobot::SetSalvageClass(TSubclassOf<ASalvage> value){ SalvageClass = value; }
int32 AEnemyRobot::GetSalvageQuantity(){ return SalvageQuantity; }
void AEnemyRobot::SetSalvageQuantity(int32 value){ SalvageQuantity = value; }
float AEnemyRobot::GetAutoAggroTime(){ return AutoAggroTime; }
void AEnemyRobot::SetAutoAggroTime(float value){ AutoAggroTime = value; }

#include "LD44.h"
#include "GameFramework/Character.h"
#include "Templates/SubclassOf.h"
#include "Public/LD44Projectile.h"
#include "Public/Salvage.h"
#include "UObject/NoExportTypes.h"
#include "Public/LD44Character.h"
#include "EngineUtils.h"
#include "CollisionQueryParams.h"
#include "Engine/EngineTypes.h"
#include "AIController.h"
#include "Components/SceneComponent.h"
#include "Engine/World.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Actor.h"
#include "Math/UnrealMathUtility.h"
#include "Components/PrimitiveComponent.h"
#include "Public/EnemyRobot.h"
