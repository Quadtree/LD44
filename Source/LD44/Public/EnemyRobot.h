#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Character.h"
#include "LD44.h"
#include "Engine/EngineTypes.h"
#include "EnemyRobot.generated.h"

UCLASS()
class LD44_API AEnemyRobot : public ACharacter
{
	GENERATED_BODY()
private:
	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetAttackDamage, BlueprintSetter=SetAttackDamage)
	float AttackDamage;

	float AttackCharge;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetAttackDelay, BlueprintSetter=SetAttackDelay)
	float AttackDelay;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetNonProjectileAttackRange, BlueprintSetter=SetNonProjectileAttackRange)
	float NonProjectileAttackRange;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetAttackProjectile, BlueprintSetter=SetAttackProjectile)
	TSubclassOf<ALD44Projectile> AttackProjectile;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetAggro, BlueprintSetter=SetAggro)
	float Aggro;

	float LineTestCharge;

	bool Attacking;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetHealth, BlueprintSetter=SetHealth)
	float Health;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetSalvageClass, BlueprintSetter=SetSalvageClass)
	TSubclassOf<ASalvage> SalvageClass;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetSalvageQuantity, BlueprintSetter=SetSalvageQuantity)
	int32 SalvageQuantity;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetAutoAggroTime, BlueprintSetter=SetAutoAggroTime)
	float AutoAggroTime;

public:
	void Tick(float deltaTime) override;

	float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;

	UFUNCTION(BlueprintGetter, BlueprintPure)
	float GetAttackDamage();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetAttackDamage(float value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	float GetAttackCharge();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetAttackCharge(float value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	float GetAttackDelay();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetAttackDelay(float value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	float GetNonProjectileAttackRange();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetNonProjectileAttackRange(float value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	TSubclassOf<ALD44Projectile>  GetAttackProjectile();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetAttackProjectile(TSubclassOf<ALD44Projectile> value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	float GetAggro();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetAggro(float value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	float GetLineTestCharge();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetLineTestCharge(float value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	bool GetAttacking();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetAttacking(bool value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	float GetHealth();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetHealth(float value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	TSubclassOf<ASalvage>  GetSalvageClass();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetSalvageClass(TSubclassOf<ASalvage> value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	int32 GetSalvageQuantity();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetSalvageQuantity(int32 value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	float GetAutoAggroTime();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetAutoAggroTime(float value);

};
