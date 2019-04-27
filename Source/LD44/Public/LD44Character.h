#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Character.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "LD44.h"
#include "Engine/EngineTypes.h"
#include "Engine/EngineBaseTypes.h"
#include "LD44Character.generated.h"

UCLASS()
class LD44_API ALD44Character : public ACharacter
{
	GENERATED_BODY()
private:
	UPROPERTY(SaveGame, VisibleAnywhere, BlueprintGetter=GetMesh1P, BlueprintSetter=SetMesh1P)
	class USkeletalMeshComponent* Mesh1P;

	UPROPERTY(SaveGame, VisibleAnywhere, BlueprintGetter=GetFP_Gun, BlueprintSetter=SetFP_Gun)
	class USkeletalMeshComponent* FP_Gun;

	UPROPERTY(SaveGame, VisibleAnywhere, BlueprintGetter=GetFP_MuzzleLocation, BlueprintSetter=SetFP_MuzzleLocation)
	class USceneComponent* FP_MuzzleLocation;

	UPROPERTY(SaveGame, VisibleAnywhere, BlueprintGetter=GetVR_Gun, BlueprintSetter=SetVR_Gun)
	class USkeletalMeshComponent* VR_Gun;

	UPROPERTY(SaveGame, VisibleAnywhere, BlueprintGetter=GetVR_MuzzleLocation, BlueprintSetter=SetVR_MuzzleLocation)
	class USceneComponent* VR_MuzzleLocation;

	UPROPERTY(SaveGame, VisibleAnywhere, BlueprintGetter=GetFirstPersonCameraComponent, BlueprintSetter=SetFirstPersonCameraComponent)
	class UCameraComponent* FirstPersonCameraComponent;

	UPROPERTY(SaveGame, VisibleAnywhere, BlueprintGetter=GetR_MotionController, BlueprintSetter=SetR_MotionController)
	class UMotionControllerComponent* R_MotionController;

	UPROPERTY(SaveGame, VisibleAnywhere, BlueprintGetter=GetL_MotionController, BlueprintSetter=SetL_MotionController)
	class UMotionControllerComponent* L_MotionController;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetBaseTurnRate, BlueprintSetter=SetBaseTurnRate)
	float BaseTurnRate;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetBaseLookUpRate, BlueprintSetter=SetBaseLookUpRate)
	float BaseLookUpRate;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetGunOffset, BlueprintSetter=SetGunOffset)
	FVector GunOffset;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetProjectileClass, BlueprintSetter=SetProjectileClass)
	TSubclassOf<class ALD44Projectile> ProjectileClass;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetAltProjectileClass, BlueprintSetter=SetAltProjectileClass)
	TSubclassOf<class ALD44Projectile> AltProjectileClass;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetFireSound, BlueprintSetter=SetFireSound)
	class USoundBase* FireSound;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetFireAnimation, BlueprintSetter=SetFireAnimation)
	class UAnimMontage* FireAnimation;

	uint32 bUsingMotionControllers;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetIsPrimaryFiring, BlueprintSetter=SetIsPrimaryFiring)
	bool IsPrimaryFiring;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetIsAltFiring, BlueprintSetter=SetIsAltFiring)
	bool IsAltFiring;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetPrimaryFireCharge, BlueprintSetter=SetPrimaryFireCharge)
	float PrimaryFireCharge;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetAltFireCharge, BlueprintSetter=SetAltFireCharge)
	float AltFireCharge;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetPrimaryFireShotDelay, BlueprintSetter=SetPrimaryFireShotDelay)
	float PrimaryFireShotDelay;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetAltFireShotDelay, BlueprintSetter=SetAltFireShotDelay)
	float AltFireShotDelay;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetPrimaryFireEnergyCost, BlueprintSetter=SetPrimaryFireEnergyCost)
	float PrimaryFireEnergyCost;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetAltFireEnergyCost, BlueprintSetter=SetAltFireEnergyCost)
	float AltFireEnergyCost;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetHealth, BlueprintSetter=SetHealth)
	float Health;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintGetter=GetEnergy, BlueprintSetter=SetEnergy)
	float Energy;

	UFUNCTION()
	bool DoFire(FString gunTag, const TSubclassOf<AActor>& projectileClassArg, float energyCost);

public:
	ALD44Character();

	void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);

	UFUNCTION(BlueprintCallable)
	void PrimaryFireAxis(float axisValue);

	UFUNCTION(BlueprintCallable)
	void AltFireAxis(float axisValue);

	void Tick(float deltaTime) override;

	UFUNCTION(BlueprintCallable)
	void OnFire();

	UFUNCTION(BlueprintCallable)
	void OnAltFire();

	UFUNCTION(BlueprintCallable)
	void OnResetVR();

	UFUNCTION(BlueprintCallable)
	void MoveForward(float Value);

	UFUNCTION(BlueprintCallable)
	void MoveRight(float Value);

	UFUNCTION(BlueprintCallable)
	void TurnAtRate(float Rate);

	UFUNCTION(BlueprintCallable)
	void LookUpAtRate(float Rate);

	UFUNCTION(BlueprintCallable)
	bool EnableTouchscreenMovement(class UInputComponent* PlayerInputComponent);

	float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;

	UFUNCTION(BlueprintGetter, BlueprintPure)
	class USkeletalMeshComponent* GetMesh1P();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetMesh1P(class USkeletalMeshComponent* value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	class USkeletalMeshComponent* GetFP_Gun();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetFP_Gun(class USkeletalMeshComponent* value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	class USceneComponent* GetFP_MuzzleLocation();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetFP_MuzzleLocation(class USceneComponent* value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	class USkeletalMeshComponent* GetVR_Gun();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetVR_Gun(class USkeletalMeshComponent* value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	class USceneComponent* GetVR_MuzzleLocation();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetVR_MuzzleLocation(class USceneComponent* value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	class UCameraComponent* GetFirstPersonCameraComponent();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetFirstPersonCameraComponent(class UCameraComponent* value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	class UMotionControllerComponent* GetR_MotionController();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetR_MotionController(class UMotionControllerComponent* value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	class UMotionControllerComponent* GetL_MotionController();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetL_MotionController(class UMotionControllerComponent* value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	float GetBaseTurnRate();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetBaseTurnRate(float value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	float GetBaseLookUpRate();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetBaseLookUpRate(float value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	FVector GetGunOffset();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetGunOffset(FVector value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	TSubclassOf<class ALD44Projectile>  GetProjectileClass();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetProjectileClass(TSubclassOf<class ALD44Projectile> value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	TSubclassOf<class ALD44Projectile>  GetAltProjectileClass();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetAltProjectileClass(TSubclassOf<class ALD44Projectile> value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	class USoundBase* GetFireSound();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetFireSound(class USoundBase* value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	class UAnimMontage* GetFireAnimation();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetFireAnimation(class UAnimMontage* value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	bool GetIsPrimaryFiring();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetIsPrimaryFiring(bool value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	bool GetIsAltFiring();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetIsAltFiring(bool value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	float GetPrimaryFireCharge();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetPrimaryFireCharge(float value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	float GetAltFireCharge();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetAltFireCharge(float value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	float GetPrimaryFireShotDelay();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetPrimaryFireShotDelay(float value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	float GetAltFireShotDelay();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetAltFireShotDelay(float value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	float GetPrimaryFireEnergyCost();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetPrimaryFireEnergyCost(float value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	float GetAltFireEnergyCost();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetAltFireEnergyCost(float value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	float GetHealth();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetHealth(float value);

	UFUNCTION(BlueprintGetter, BlueprintPure)
	float GetEnergy();

	UFUNCTION(BlueprintSetter, BlueprintCallable)
	void SetEnergy(float value);

};
