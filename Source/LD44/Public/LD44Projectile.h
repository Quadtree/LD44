#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
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

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetTintColor, BlueprintSetter=SetTintColor)
	FLinearColor TintColor;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetBlastRadius, BlueprintSetter=SetBlastRadius)
	float BlastRadius;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetFireSound, BlueprintSetter=SetFireSound)
	class USoundBase* FireSound;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetHitSound, BlueprintSetter=SetHitSound)
	class USoundBase* HitSound;

public:
	UFUNCTION(BlueprintImplementableEvent)
	void ColorChanged();

	ALD44Projectile();

	void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void OnHit(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION(BlueprintCallable)
	void SetTintColor(FLinearColor value);

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

	UFUNCTION(BlueprintGetter, BlueprintPure)
	FLinearColor GetTintColor();

	UFUNCTION(BlueprintGetter, BlueprintPure)
	float GetBlastRadius();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetBlastRadius(float value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	class USoundBase* GetFireSound();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetFireSound(class USoundBase* value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	class USoundBase* GetHitSound();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetHitSound(class USoundBase* value);

};
