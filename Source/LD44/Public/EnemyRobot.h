#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Character.h"
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
	TSubclassOf<AActor> AttackProjectile;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetAggro, BlueprintSetter=SetAggro)
	float Aggro;

	float LineTestCharge;

	bool Attacking;

public:
	void Tick(float deltaTime) override;

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
	TSubclassOf<AActor>  GetAttackProjectile();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetAttackProjectile(TSubclassOf<AActor> value);

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

};
