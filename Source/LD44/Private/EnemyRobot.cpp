#include "EnemyRobot.h"
#include "EnemyRobot.ac.h"

#include "DrawDebugHelpers.h"

extends(ACharacter)

prop(float AttackDamage)
prop(bare float AttackCharge)
prop(float AttackDelay)
prop(float NonProjectileAttackRange)
prop(TSubclassOf<ALD44Projectile> AttackProjectile)
prop(float Aggro)
prop(bare float LineTestCharge)
prop(bare bool Attacking)
prop(float Health)

prop(TSubclassOf<ASalvage> SalvageClass)
prop(int32 SalvageQuantity)

prop(float AutoAggroTime)

blueprintEvent(DestroyedByDamage)

void fun::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	AttackCharge += deltaTime;
	LineTestCharge += deltaTime;
	Aggro -= deltaTime;

	if (LineTestCharge >= 1)
	{
		Attacking = false;
		LineTestCharge = 0;
		FVector playerPos;
		ALD44Character* player = nullptr;

		for (TActorIterator<ALD44Character> i(GetWorld()); i; ++i)
		{
			playerPos = i->GetActorLocation();
			player = *i;
		}

		if (player)
		{
			FCollisionQueryParams params;
			params.AddIgnoredActor(this);
			params.AddIgnoredActor(player);

			if (FVector::Dist(GetActorLocation(), playerPos) < 3000 && !GetWorld()->LineTraceTestByChannel(GetActorLocation(), playerPos, ECollisionChannel::ECC_Visibility))
			{
				// we can see the player
				Attacking = true;
				Aggro = 4;
				if (AttackProjectile)
				{
					// if we're a ranged attacker, STOP when we can see them
					if (auto ai = Cast<AAIController>(GetController()))
					{
						if (FVector::Dist(GetActorLocation(), playerPos) < 2000)
						{
							ai->StopMovement();
						}
						else
						{
							ai->MoveToActor(player);
						}
					}
				}
				else
				{
					if (auto ai = Cast<AAIController>(GetController()))
					{
						ai->MoveToActor(player);
					}
				}
			}
			else
			{
				if (Aggro > 0)
				{
					if (auto ai = Cast<AAIController>(GetController()))
					{
						ai->MoveToActor(player);
					}
				}
			}
		}
	}

	if (Attacking)
	{
		FVector playerPos;
		ALD44Character* player = nullptr;

		for (TActorIterator<ALD44Character> i(GetWorld()); i; ++i)
		{
			playerPos = i->GetActorLocation();
			player = *i;
		}

		for (auto a : GetComponentsByTag(USceneComponent::StaticClass(), "TurretYaw"))
		{
			if (auto a2 = Cast<USceneComponent>(a))
			{
				auto rot = (playerPos - a2->GetComponentLocation()).Rotation();
				//UE_LOG(LogTemp, Display, TEXT("%s"), *rot.ToString());
				rot.Pitch = 0;
				rot.Roll = 0;
				a2->SetWorldLocationAndRotation(
					a2->GetComponentLocation(),
					rot
				);
			}
		}

		for (auto a : GetComponentsByTag(USceneComponent::StaticClass(), "Turret"))
		{
			if (auto a2 = Cast<USceneComponent>(a))
			{
				a2->SetWorldLocationAndRotation(
					a2->GetComponentLocation(),
					(playerPos - a2->GetComponentLocation()).Rotation()
				);
			}
		}

		if (AttackProjectile && player)
		{
			if (auto ai = Cast<AAIController>(GetController()))
			{
				ai->SetControlRotation((player->GetActorLocation() - this->GetActorLocation()).Rotation());
			}

			if (AttackCharge >= AttackDelay)
			{
				AttackCharge = 0;

				FVector spawnPoint = GetActorLocation();

				for (auto a : GetComponentsByTag(USceneComponent::StaticClass(), "Gun"))
				{
					spawnPoint = Cast<USceneComponent>(a)->GetComponentLocation();
					break;
				}

				FActorSpawnParameters params;
				params.Instigator = this;

				UE_LOG(LogTemp, Display, TEXT("%s"), *(playerPos - spawnPoint).Rotation().ToString());

				DrawDebugLine(GetWorld(), spawnPoint, spawnPoint, FColor::Red, false, 1.f);

				auto prj = GetWorld()->SpawnActor<ALD44Projectile>(AttackProjectile, spawnPoint, (playerPos - spawnPoint).GetSafeNormal().Rotation(), params);
				if (prj)
				{
					prj->SetDamageOnHit(AttackDamage);
				}
			}
		}
		else if (player && !GetWorld()->LineTraceTestByChannel(GetActorLocation(), playerPos, ECollisionChannel::ECC_Visibility) && FVector::Dist(GetActorLocation(), playerPos) <= NonProjectileAttackRange)
		{
			if (AttackCharge >= AttackDelay)
			{
				AttackCharge = 0;

				player->TakeDamage(AttackDamage, FDamageEvent(), GetController(), this);
			}
		}
	}

	if (AutoAggroTime > 0)
	{
		AutoAggroTime -= deltaTime;
		if (AutoAggroTime <= 0)
		{
			Aggro = 100000;
		}
	}
}

float fun::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	Health -= DamageAmount;

	if (Health <= 0)
	{
		UE_LOG(LogTemp, Display, TEXT("Enemy %s has died"), *GetName());
		
		for (int32 i = 0; i < SalvageQuantity; ++i)
		{
			FVector pt = FMath::RandPointInBox(GetComponentsBoundingBox());

			FActorSpawnParameters params;
			params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

			auto s = GetWorld()->SpawnActor<ASalvage>(SalvageClass, pt, FRotator::ZeroRotator, params);
			if (s)
			{
				FVector dir = (pt - GetActorLocation()).GetSafeNormal();

				if (auto root = Cast<UPrimitiveComponent>(s->GetRootComponent()))
				{
					root->AddImpulse(dir * 100, NAME_None, true);
					root->AddAngularImpulse(FVector(FMath::FRandRange(-100, 100), FMath::FRandRange(-100, 100), FMath::FRandRange(-100, 100)), NAME_None, true);
				}
			}
		}

		DestroyedByDamage();

		Destroy();
	}

	for (TActorIterator<AEnemyRobot> i(GetWorld()); i; ++i)
	{
		if (FVector::Dist(i->GetActorLocation(), GetActorLocation()) < 1500)
		{
			i->Aggro = 10;
		}
	}

	return DamageAmount;
}