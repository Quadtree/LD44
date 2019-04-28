
#ifdef fun
    #undef fun
#endif

#define mods(...)
#define im(...)
#define blueprintEvent(...)
#define prop(...)
#define extends(...)
#define classMods(...)
#define fun         ALD44Projectile
USphereComponent* ALD44Projectile::GetCollisionComp(){ return CollisionComp; }
void ALD44Projectile::SetCollisionComp(USphereComponent* value){ CollisionComp = value; }
UProjectileMovementComponent* ALD44Projectile::GetProjectileMovement(){ return ProjectileMovement; }
void ALD44Projectile::SetProjectileMovement(UProjectileMovementComponent* value){ ProjectileMovement = value; }
float ALD44Projectile::GetDamageOnHit(){ return DamageOnHit; }
void ALD44Projectile::SetDamageOnHit(float value){ DamageOnHit = value; }
FLinearColor ALD44Projectile::GetTintColor(){ return TintColor; }
float ALD44Projectile::GetBlastRadius(){ return BlastRadius; }
void ALD44Projectile::SetBlastRadius(float value){ BlastRadius = value; }

#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/NoExportTypes.h"
#include "Public/LD44Projectile.h"
#include "Engine/EngineTypes.h"
#include "Components/PrimitiveComponent.h"
#include "WorldCollision.h"
