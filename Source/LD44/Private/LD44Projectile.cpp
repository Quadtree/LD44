// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "LD44Projectile.h"
#include "LD44Projectile.ac.h"

extends(AActor)

prop(USphereComponent* CollisionComp)
prop(UProjectileMovementComponent* ProjectileMovement)
prop(float DamageOnHit)
prop(FLinearColor TintColor)
prop(float BlastRadius)

prop(USoundBase* FireSound)
prop(USoundBase* HitSound)

prop(bool SpeedSeen)

blueprintEvent(ColorChanged)

fun::ALD44Projectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &ALD44Projectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;

	PrimaryActorTick.bCanEverTick = true;
}

void fun::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	//UE_LOG(LogTemp, Display, TEXT("%s"), *FString::SanitizeFloat(CollisionComp->GetPhysicsLinearVelocity().Size()));

	//ProjectileMovement->Get
	
	//if (CollisionComp->GetPhysicsLinearVelocity().Size() < 10 && SpeedSeen) Detonate();
	//SpeedSeen = true;
}

void fun::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::PlaySound2D(this, FireSound);
}

void fun::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor == GetInstigator()) return;

	// Only add impulse and destroy projectile if we hit a physics
	/*if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 500.0f, GetActorLocation());

		Destroy();
	}*/

	if (BlastRadius <= 0)
	{
		if (OtherActor)
		{
			FPointDamageEvent pt;
			pt.Damage = DamageOnHit;
			pt.ShotDirection = GetActorRotation().RotateVector(FVector(1, 0, 0));

			OtherActor->TakeDamage(DamageOnHit, pt, GetInstigatorController(), this);
		}
	}
}

void fun::Detonate()
{
	if (BlastRadius > 0)
	{
		TArray<FOverlapResult> res;
		GetWorld()->OverlapMultiByChannel(res, GetActorLocation(), FQuat::Identity, ECollisionChannel::ECC_WorldDynamic, FCollisionShape::MakeSphere(BlastRadius));

		for (auto a : res)
		{
			if (a.Actor.Get())
			{
				a.Actor->TakeDamage(DamageOnHit, FDamageEvent(), GetInstigatorController(), this);
			}
		}
	}

	Destroy();
	UGameplayStatics::PlaySound2D(this, HitSound);
}

void fun::SetTintColor(FLinearColor value)
{
	TintColor = value;
	ColorChanged();
}