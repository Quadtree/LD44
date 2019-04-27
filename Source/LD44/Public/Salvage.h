#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Actor.h"
#include "Salvage.generated.h"

UCLASS()
class LD44_API ASalvage : public AActor
{
	GENERATED_BODY()
private:
	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetHealthBonus, BlueprintSetter=SetHealthBonus)
	float HealthBonus;

	UPROPERTY(SaveGame, VisibleAnywhere, BlueprintGetter=GetCollisionComp, BlueprintSetter=SetCollisionComp)
	class USphereComponent* CollisionComp;

public:
	ASalvage();

	UFUNCTION(BlueprintCallable)
	void OnHit(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	float GetHealthBonus();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetHealthBonus(float value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	class USphereComponent* GetCollisionComp();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetCollisionComp(class USphereComponent* value);

};
