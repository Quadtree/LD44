
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

#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Public/Salvage.h"
#include "Components/PrimitiveComponent.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "Public/LD44Character.h"
