#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Actor.h"
#include "LD44Projectile.generated.h"

UCLASS()
class LD44_API ALD44Projectile : public AActor
{
	GENERATED_BODY()
private:
	UPROPERTY(SaveGame, VisibleAnywhere, BlueprintGetter=GetCollisionComp, BlueprintSetter=SetCollisionComp)
	class USphereComponent* CollisionComp;

	UPROPERTY(SaveGame, VisibleAnywhere, BlueprintGetter=GetProjectileMovement, BlueprintSetter=SetProjectileMovement)
	class UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetDamageOnHit, BlueprintSetter=SetDamageOnHit)
	float DamageOnHit;

public:
	ALD44Projectile();

	UFUNCTION(BlueprintCallable)
	void OnHit(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	class USphereComponent* GetCollisionComp();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetCollisionComp(class USphereComponent* value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	class UProjectileMovementComponent* GetProjectileMovement();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetProjectileMovement(class UProjectileMovementComponent* value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	float GetDamageOnHit();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetDamageOnHit(float value);

};
