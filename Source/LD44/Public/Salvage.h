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

	UPROPERTY(SaveGame, VisibleAnywhere, BlueprintGetter=GetMesh, BlueprintSetter=SetMesh)
	class UStaticMeshComponent* Mesh;

public:
	ASalvage();

	UFUNCTION(BlueprintCallable)
	void OnHit(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	float GetHealthBonus();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetHealthBonus(float value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	class USphereComponent* GetCollisionComp();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetCollisionComp(class USphereComponent* value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	class UStaticMeshComponent* GetMesh();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetMesh(class UStaticMeshComponent* value);

};
