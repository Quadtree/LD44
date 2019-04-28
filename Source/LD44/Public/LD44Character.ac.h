
#ifdef fun
    #undef fun
#endif

#define mods(...)
#define im(...)
#define blueprintEvent(...)
#define prop(...)
#define extends(...)
#define classMods(...)
#define fun         ALD44Character
USkeletalMeshComponent* ALD44Character::GetMesh1P(){ return Mesh1P; }
void ALD44Character::SetMesh1P(USkeletalMeshComponent* value){ Mesh1P = value; }
USkeletalMeshComponent* ALD44Character::GetFP_Gun(){ return FP_Gun; }
void ALD44Character::SetFP_Gun(USkeletalMeshComponent* value){ FP_Gun = value; }
USceneComponent* ALD44Character::GetFP_MuzzleLocation(){ return FP_MuzzleLocation; }
void ALD44Character::SetFP_MuzzleLocation(USceneComponent* value){ FP_MuzzleLocation = value; }
USkeletalMeshComponent* ALD44Character::GetVR_Gun(){ return VR_Gun; }
void ALD44Character::SetVR_Gun(USkeletalMeshComponent* value){ VR_Gun = value; }
USceneComponent* ALD44Character::GetVR_MuzzleLocation(){ return VR_MuzzleLocation; }
void ALD44Character::SetVR_MuzzleLocation(USceneComponent* value){ VR_MuzzleLocation = value; }
UCameraComponent* ALD44Character::GetFirstPersonCameraComponent(){ return FirstPersonCameraComponent; }
void ALD44Character::SetFirstPersonCameraComponent(UCameraComponent* value){ FirstPersonCameraComponent = value; }
UMotionControllerComponent* ALD44Character::GetR_MotionController(){ return R_MotionController; }
void ALD44Character::SetR_MotionController(UMotionControllerComponent* value){ R_MotionController = value; }
UMotionControllerComponent* ALD44Character::GetL_MotionController(){ return L_MotionController; }
void ALD44Character::SetL_MotionController(UMotionControllerComponent* value){ L_MotionController = value; }
float ALD44Character::GetBaseTurnRate(){ return BaseTurnRate; }
void ALD44Character::SetBaseTurnRate(float value){ BaseTurnRate = value; }
float ALD44Character::GetBaseLookUpRate(){ return BaseLookUpRate; }
void ALD44Character::SetBaseLookUpRate(float value){ BaseLookUpRate = value; }
FVector ALD44Character::GetGunOffset(){ return GunOffset; }
void ALD44Character::SetGunOffset(FVector value){ GunOffset = value; }
TSubclassOf<class ALD44Projectile> ALD44Character::GetProjectileClass(){ return ProjectileClass; }
void ALD44Character::SetProjectileClass(TSubclassOf<class ALD44Projectile> value){ ProjectileClass = value; }
TSubclassOf<class ALD44Projectile> ALD44Character::GetAltProjectileClass(){ return AltProjectileClass; }
void ALD44Character::SetAltProjectileClass(TSubclassOf<class ALD44Projectile> value){ AltProjectileClass = value; }
USoundBase* ALD44Character::GetFireSound(){ return FireSound; }
void ALD44Character::SetFireSound(USoundBase* value){ FireSound = value; }
UAnimMontage* ALD44Character::GetFireAnimation(){ return FireAnimation; }
void ALD44Character::SetFireAnimation(UAnimMontage* value){ FireAnimation = value; }
bool ALD44Character::GetIsPrimaryFiring(){ return IsPrimaryFiring; }
void ALD44Character::SetIsPrimaryFiring(bool value){ IsPrimaryFiring = value; }
bool ALD44Character::GetIsAltFiring(){ return IsAltFiring; }
void ALD44Character::SetIsAltFiring(bool value){ IsAltFiring = value; }
float ALD44Character::GetPrimaryFireCharge(){ return PrimaryFireCharge; }
void ALD44Character::SetPrimaryFireCharge(float value){ PrimaryFireCharge = value; }
float ALD44Character::GetAltFireCharge(){ return AltFireCharge; }
void ALD44Character::SetAltFireCharge(float value){ AltFireCharge = value; }
float ALD44Character::GetPrimaryFireShotDelay(){ return PrimaryFireShotDelay; }
void ALD44Character::SetPrimaryFireShotDelay(float value){ PrimaryFireShotDelay = value; }
float ALD44Character::GetAltFireShotDelay(){ return AltFireShotDelay; }
void ALD44Character::SetAltFireShotDelay(float value){ AltFireShotDelay = value; }
float ALD44Character::GetPrimaryFireEnergyCost(){ return PrimaryFireEnergyCost; }
void ALD44Character::SetPrimaryFireEnergyCost(float value){ PrimaryFireEnergyCost = value; }
float ALD44Character::GetAltFireEnergyCost(){ return AltFireEnergyCost; }
void ALD44Character::SetAltFireEnergyCost(float value){ AltFireEnergyCost = value; }
float ALD44Character::GetHealth(){ return Health; }
float ALD44Character::GetEnergy(){ return Energy; }
void ALD44Character::SetEnergy(float value){ Energy = value; }
int32 ALD44Character::GetUpgradeLevelPrimaryFire(){ return UpgradeLevelPrimaryFire; }
void ALD44Character::SetUpgradeLevelPrimaryFire(int32 value){ UpgradeLevelPrimaryFire = value; }
int32 ALD44Character::GetUpgradeLevelAltFire(){ return UpgradeLevelAltFire; }
void ALD44Character::SetUpgradeLevelAltFire(int32 value){ UpgradeLevelAltFire = value; }
int32 ALD44Character::GetUpgradeLevelEnergyRegeneration(){ return UpgradeLevelEnergyRegeneration; }
void ALD44Character::SetUpgradeLevelEnergyRegeneration(int32 value){ UpgradeLevelEnergyRegeneration = value; }
int32 ALD44Character::GetUpgradeLevelArmor(){ return UpgradeLevelArmor; }
void ALD44Character::SetUpgradeLevelArmor(int32 value){ UpgradeLevelArmor = value; }
int32 ALD44Character::GetUpgradeLevelJumping(){ return UpgradeLevelJumping; }
void ALD44Character::SetUpgradeLevelJumping(int32 value){ UpgradeLevelJumping = value; }
int32 ALD44Character::GetUpgradeLevelMovementSpeed(){ return UpgradeLevelMovementSpeed; }
void ALD44Character::SetUpgradeLevelMovementSpeed(int32 value){ UpgradeLevelMovementSpeed = value; }
float ALD44Character::GetPrimaryFireBaseDamage(){ return PrimaryFireBaseDamage; }
void ALD44Character::SetPrimaryFireBaseDamage(float value){ PrimaryFireBaseDamage = value; }
float ALD44Character::GetPrimaryFireUpgradeDamage(){ return PrimaryFireUpgradeDamage; }
void ALD44Character::SetPrimaryFireUpgradeDamage(float value){ PrimaryFireUpgradeDamage = value; }
float ALD44Character::GetAltFireBaseDamage(){ return AltFireBaseDamage; }
void ALD44Character::SetAltFireBaseDamage(float value){ AltFireBaseDamage = value; }
float ALD44Character::GetAltFireUpgradeDamage(){ return AltFireUpgradeDamage; }
void ALD44Character::SetAltFireUpgradeDamage(float value){ AltFireUpgradeDamage = value; }
float ALD44Character::GetEnergyRegenerationBase(){ return EnergyRegenerationBase; }
void ALD44Character::SetEnergyRegenerationBase(float value){ EnergyRegenerationBase = value; }
float ALD44Character::GetEnergyRegenerationUpgrade(){ return EnergyRegenerationUpgrade; }
void ALD44Character::SetEnergyRegenerationUpgrade(float value){ EnergyRegenerationUpgrade = value; }
float ALD44Character::GetArmorUpgradeAmount(){ return ArmorUpgradeAmount; }
void ALD44Character::SetArmorUpgradeAmount(float value){ ArmorUpgradeAmount = value; }
float ALD44Character::GetJumpingBase(){ return JumpingBase; }
void ALD44Character::SetJumpingBase(float value){ JumpingBase = value; }
float ALD44Character::GetJumpingUpgrade(){ return JumpingUpgrade; }
void ALD44Character::SetJumpingUpgrade(float value){ JumpingUpgrade = value; }
float ALD44Character::GetMovementSpeedBase(){ return MovementSpeedBase; }
void ALD44Character::SetMovementSpeedBase(float value){ MovementSpeedBase = value; }
float ALD44Character::GetMovementSpeedUpgrade(){ return MovementSpeedUpgrade; }
void ALD44Character::SetMovementSpeedUpgrade(float value){ MovementSpeedUpgrade = value; }
float ALD44Character::GetUpgradeCost(){ return UpgradeCost; }
void ALD44Character::SetUpgradeCost(float value){ UpgradeCost = value; }
int32 ALD44Character::GetMaxUpgradeLevel(){ return MaxUpgradeLevel; }
void ALD44Character::SetMaxUpgradeLevel(int32 value){ MaxUpgradeLevel = value; }

#include "LD44.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Camera/CameraComponent.h"
#include "MotionControllerComponent.h"
#include "UObject/NoExportTypes.h"
#include "Templates/SubclassOf.h"
#include "Public/LD44Projectile.h"
#include "Sound/SoundBase.h"
#include "Animation/AnimMontage.h"
#include "Public/LD44Character.h"
#include "XRMotionControllerBase.h"
#include "Engine/EngineTypes.h"
#include "Components/InputComponent.h"
#include "GameFramework/Pawn.h"
#include "Public/UpgradeType.h"
#include "Math/UnrealMathUtility.h"
#include "Containers/UnrealString.h"
#include "GameFramework/Actor.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "GameFramework/InputSettings.h"
#include "Engine/EngineBaseTypes.h"
#include "GameFramework/Controller.h"
#include "Public/LD44GameMode.h"
#include "Kismet/GameplayStatics.h"
