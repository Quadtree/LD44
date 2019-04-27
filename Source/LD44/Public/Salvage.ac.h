
#ifdef fun
    #undef fun
#endif

#define mods(...)
#define im(...)
#define blueprintEvent(...)
#define prop(...)
#define extends(...)
#define classMods(...)
#define fun         ASalvage
float ASalvage::GetHealthBonus(){ return HealthBonus; }
void ASalvage::SetHealthBonus(float value){ HealthBonus = value; }
USphereComponent* ASalvage::GetCollisionComp(){ return CollisionComp; }
void ASalvage::SetCollisionComp(USphereComponent* value){ CollisionComp = value; }
UStaticMeshComponent* ASalvage::GetMesh(){ return Mesh; }
void ASalvage::SetMesh(UStaticMeshComponent* value){ Mesh = value; }

#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Public/Salvage.h"
#include "Engine/EngineTypes.h"
#include "Components/PrimitiveComponent.h"
#include "Public/LD44Character.h"
