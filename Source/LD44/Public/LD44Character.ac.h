
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

#include "LD44.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Camera/CameraComponent.h"
#include "MotionControllerComponent.h"
#include "UObject/NoExportTypes.h"
#include "Templates/SubclassOf.h"
#include "Private/LD44Projectile.h"
#include "Sound/SoundBase.h"
#include "Animation/AnimMontage.h"
#include "Public/LD44Character.h"
#include "XRMotionControllerBase.h"
#include "Engine/EngineTypes.h"
#include "Components/InputComponent.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Animation/AnimInstance.h"
#include "Containers/UnrealString.h"
#include "GameFramework/Actor.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "GameFramework/InputSettings.h"
#include "Engine/EngineBaseTypes.h"
