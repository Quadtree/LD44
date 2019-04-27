// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "LD44Character.h"
#include "LD44Character.ac.h"

extends(ACharacter)

prop(USkeletalMeshComponent* Mesh1P)
prop(USkeletalMeshComponent* FP_Gun)
prop(USceneComponent* FP_MuzzleLocation)
prop(USkeletalMeshComponent* VR_Gun)
prop(USceneComponent* VR_MuzzleLocation)
prop(UCameraComponent* FirstPersonCameraComponent)
prop(UMotionControllerComponent* R_MotionController)
prop(UMotionControllerComponent* L_MotionController)
prop(float BaseTurnRate)
prop(float BaseLookUpRate)
prop(FVector GunOffset)
prop(TSubclassOf<class ALD44Projectile> ProjectileClass)
prop(TSubclassOf<class ALD44Projectile> AltProjectileClass)
prop(USoundBase* FireSound)
prop(UAnimMontage* FireAnimation)
prop(bare private uint32 bUsingMotionControllers)
prop(bool IsPrimaryFiring)
prop(bool IsAltFiring)
prop(float PrimaryFireCharge)
prop(float AltFireCharge)
prop(float PrimaryFireShotDelay)
prop(float AltFireShotDelay)
prop(float PrimaryFireEnergyCost)
prop(float AltFireEnergyCost)
prop(float Health)
prop(float Energy)

prop(int32 UpgradeLevelPrimaryFire)
prop(int32 UpgradeLevelAltFire)
prop(int32 UpgradeLevelEnergyRegeneration)
prop(int32 UpgradeLevelArmor)
prop(int32 UpgradeLevelJumping)
prop(int32 UpgradeLevelMovementSpeed)

prop(float PrimaryFireBaseDamage)
prop(float PrimaryFireUpgradeDamage)
prop(float AltFireBaseDamage)
prop(float AltFireUpgradeDamage)

prop(float EnergyRegenerationBase)
prop(float EnergyRegenerationUpgrade)

prop(float ArmorUpgradeAmount)

prop(float JumpingBase)
prop(float JumpingUpgrade)

prop(float MovementSpeedBase)
prop(float MovementSpeedUpgrade)

prop(float UpgradeCost)

DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);

//////////////////////////////////////////////////////////////////////////
// ALD44Character

fun::ALD44Character()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->RelativeLocation = FVector(-39.56f, 1.75f, 64.f); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->RelativeRotation = FRotator(1.9f, -19.19f, 5.2f);
	Mesh1P->RelativeLocation = FVector(-0.5f, -4.4f, -155.7f);

	// Create a gun mesh component
	FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
	FP_Gun->SetOnlyOwnerSee(true);			// only the owning player will see this mesh
	FP_Gun->bCastDynamicShadow = false;
	FP_Gun->CastShadow = false;
	// FP_Gun->SetupAttachment(Mesh1P, TEXT("GripPoint"));
	FP_Gun->SetupAttachment(RootComponent);

	FP_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	FP_MuzzleLocation->SetupAttachment(FP_Gun);
	FP_MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 0.0f, 10.0f);

	// Note: The ProjectileClass and the skeletal mesh/anim blueprints for Mesh1P, FP_Gun, and VR_Gun 
	// are set in the derived blueprint asset named MyCharacter to avoid direct content references in C++.

	// Create VR Controllers.
	R_MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("R_MotionController"));
	R_MotionController->MotionSource = FXRMotionControllerBase::RightHandSourceId;
	R_MotionController->SetupAttachment(RootComponent);
	L_MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("L_MotionController"));
	L_MotionController->SetupAttachment(RootComponent);

	// Create a gun and attach it to the right-hand VR controller.
	// Create a gun mesh component
	VR_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("VR_Gun"));
	VR_Gun->SetOnlyOwnerSee(true);			// only the owning player will see this mesh
	VR_Gun->bCastDynamicShadow = false;
	VR_Gun->CastShadow = false;
	VR_Gun->SetupAttachment(R_MotionController);
	VR_Gun->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	VR_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("VR_MuzzleLocation"));
	VR_MuzzleLocation->SetupAttachment(VR_Gun);
	VR_MuzzleLocation->SetRelativeLocation(FVector(0.000004, 53.999992, 10.000000));
	VR_MuzzleLocation->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));		// Counteract the rotation of the VR gun model.

	// Uncomment the following line to turn motion controllers on by default:
	//bUsingMotionControllers = true;
}

void fun::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Attach gun mesh component to Skeleton, doing it here because the skeleton is not yet created in the constructor
	FP_Gun->AttachToComponent(Mesh1P, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));

	// Show or hide the two versions of the gun based on whether or not we're using motion controllers.
	if (bUsingMotionControllers)
	{
		VR_Gun->SetHiddenInGame(false, true);
		Mesh1P->SetHiddenInGame(true, true);
	}
	else
	{
		VR_Gun->SetHiddenInGame(true, true);
		Mesh1P->SetHiddenInGame(false, true);
	}
}

//////////////////////////////////////////////////////////////////////////
// Input

void fun::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	check(PlayerInputComponent);

	// Bind jump events
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	// Bind fire event
	PlayerInputComponent->BindAxis("Fire", this, &ALD44Character::PrimaryFireAxis);
	PlayerInputComponent->BindAxis("AltFire", this, &ALD44Character::AltFireAxis);

	// Enable touchscreen input
	EnableTouchscreenMovement(PlayerInputComponent);

	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &ALD44Character::OnResetVR);

	// Bind movement events
	PlayerInputComponent->BindAxis("MoveForward", this, &ALD44Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ALD44Character::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ALD44Character::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ALD44Character::LookUpAtRate);

	PlayerInputComponent->BindAction("UpgradePrimaryFire", IE_Pressed, this, &fun::UpgradePrimaryFire);
	PlayerInputComponent->BindAction("UpgradeAltFire", IE_Pressed, this, &fun::UpgradeAltFire);
	PlayerInputComponent->BindAction("UpgradeEnergyRegeneration", IE_Pressed, this, &fun::UpgradeEnergyRegeneration);
	PlayerInputComponent->BindAction("UpgradeArmor", IE_Pressed, this, &fun::UpgradeArmor);
	PlayerInputComponent->BindAction("UpgradeJumping", IE_Pressed, this, &fun::UpgradeJumping);
	PlayerInputComponent->BindAction("UpgradeMovementSpeed", IE_Pressed, this, &fun::UpgradeMovementSpeed);
}

void fun::UpgradePrimaryFire()
{
	if (Health >= UpgradeCost)
	{
		UpgradeLevelPrimaryFire++;
		Health -= UpgradeCost;
	}
}

void fun::UpgradeAltFire()
{
	if (Health >= UpgradeCost)
	{
		UpgradeLevelAltFire++;
		Health -= UpgradeCost;
	}
}

void fun::UpgradeEnergyRegeneration()
{
	if (Health >= UpgradeCost)
	{
		UpgradeLevelEnergyRegeneration++;
		Health -= UpgradeCost;
	}
}

void fun::UpgradeArmor()
{
	if (Health >= UpgradeCost)
	{
		UpgradeLevelArmor++;
		Health -= UpgradeCost;
	}
}

void fun::UpgradeJumping()
{
	if (Health >= UpgradeCost)
	{
		UpgradeLevelJumping++;
		Health -= UpgradeCost;
	}
}

void fun::UpgradeMovementSpeed()
{
	if (Health >= UpgradeCost)
	{
		UpgradeLevelMovementSpeed++;
		Health -= UpgradeCost;
	}
}

int32 fun::GetUpgradeLevel(EUpgradeType type)
{
	switch (type)
	{
	case EUpgradeType::UT_PrimaryFire: return UpgradeLevelPrimaryFire;
	case EUpgradeType::UT_AltFire: return UpgradeLevelAltFire;
	case EUpgradeType::UT_EnergyRegeneration: return UpgradeLevelEnergyRegeneration;
	case EUpgradeType::UT_Armor: return UpgradeLevelArmor;
	case EUpgradeType::UT_Jumping: return UpgradeLevelJumping;
	case EUpgradeType::UT_MovementSpeed: return UpgradeLevelMovementSpeed;
	}

	return -1;
}

void fun::SetUpgradeLevel(EUpgradeType type, int32 level)
{
	switch (type)
	{
	case EUpgradeType::UT_PrimaryFire: UpgradeLevelPrimaryFire = level; return;
	case EUpgradeType::UT_AltFire: UpgradeLevelAltFire = level; return;
	case EUpgradeType::UT_EnergyRegeneration: UpgradeLevelEnergyRegeneration = level; return;
	case EUpgradeType::UT_Armor: UpgradeLevelArmor = level; return;
	case EUpgradeType::UT_Jumping: UpgradeLevelJumping = level; return;
	case EUpgradeType::UT_MovementSpeed: UpgradeLevelMovementSpeed = level; return;
	}
}

void fun::PrimaryFireAxis(float axisValue)
{
	SetIsPrimaryFiring(axisValue > 0.5f);
}

void fun::AltFireAxis(float axisValue)
{
	SetIsAltFiring(axisValue > 0.5f);
}

void fun::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	PrimaryFireCharge += deltaTime;
	AltFireCharge += deltaTime;

	Energy = FMath::Clamp(Energy + deltaTime * (EnergyRegenerationBase + EnergyRegenerationUpgrade * UpgradeLevelEnergyRegeneration), 0.f, 100.f);

	GetCharacterMovement()->JumpZVelocity = JumpingBase + JumpingUpgrade * UpgradeLevelJumping;
	GetCharacterMovement()->MaxWalkSpeed = MovementSpeedBase + MovementSpeedUpgrade * UpgradeLevelMovementSpeed;

	if (IsPrimaryFiring && PrimaryFireCharge >= PrimaryFireShotDelay) OnFire();
	if (IsAltFiring && AltFireCharge >= AltFireShotDelay) OnAltFire();
}

void fun::OnFire()
{
	if (DoFire("LeftGun", ProjectileClass, PrimaryFireEnergyCost, PrimaryFireBaseDamage + PrimaryFireUpgradeDamage * UpgradeLevelPrimaryFire))
		PrimaryFireCharge = 0;
}

void fun::OnAltFire()
{
	if (DoFire("RightGun", AltProjectileClass, AltFireEnergyCost, AltFireBaseDamage + AltFireUpgradeDamage * UpgradeLevelAltFire))
		AltFireCharge = 0;
}

mods(private) bool fun::DoFire(FString gunTag, const TSubclassOf<AActor>& projectileClassArg, float energyCost, float damage)
{
	if (Energy >= energyCost)
	{
		Energy -= energyCost;
		if (projectileClassArg)
		{
			auto comps = GetComponentsByTag(USceneComponent::StaticClass(), *gunTag);
			if (comps.Num())
			{
				auto sc = Cast<USceneComponent>(comps[0]);
				FVector spawnPos = sc->GetComponentLocation();

				GetWorld()->SpawnActor<AActor>(projectileClassArg, spawnPos, GetControlRotation());
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Can't find gun with tag %s"), *gunTag);
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No projectile class!"));
		}

		return true;
	}

	return false;
}

void fun::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void fun::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void fun::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void fun::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void fun::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

bool fun::EnableTouchscreenMovement(class UInputComponent* PlayerInputComponent)
{
	if (FPlatformMisc::SupportsTouchInput() || GetDefault<UInputSettings>()->bUseMouseForTouch)
	{
		//PlayerInputComponent->BindTouch(EInputEvent::IE_Pressed, this, &fun::BeginTouch);
		//PlayerInputComponent->BindTouch(EInputEvent::IE_Released, this, &fun::EndTouch);

		//Commenting this out to be more consistent with FPS BP template.
		//PlayerInputComponent->BindTouch(EInputEvent::IE_Repeat, this, &ALD44Character::TouchUpdate);
		return true;
	}
	
	return false;
}

float fun::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	DamageAmount *= FMath::Pow(1.f - ArmorUpgradeAmount, UpgradeLevelArmor);

	Health -= DamageAmount;

	if (Health <= 0)
	{
		UE_LOG(LogTemp, Display, TEXT("Player has died"));

		Cast<ALD44GameMode>(UGameplayStatics::GetGameMode(this))->PlayerHasDied();

		Destroy();
	}

	return DamageAmount;
}

void fun::SetHealth(float value)
{
	this->Health = FMath::Clamp(value, 0.f, 200.f);
}