#include "EnemyRobot.h"
#include "EnemyRobot.ac.h"

extends(ACharacter)

prop(float AttackDamage)
prop(bare float AttackCharge)
prop(float AttackDelay)
prop(float NonProjectileAttackRange)
prop(TSubclassOf<AActor> AttackProjectile)
prop(float Aggro)
prop(bare float LineTestCharge)
prop(bare bool Attacking)

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

			if (!GetWorld()->LineTraceTestByChannel(GetActorLocation(), playerPos, ECollisionChannel::ECC_Visibility))
			{
				// we can see the player
				Attacking = true;
				Aggro = 4;
				if (AttackProjectile)
				{
					// if we're a ranged attacker, STOP when we can see them
					if (auto ai = Cast<AAIController>(GetController()))
					{
						ai->StopMovement();
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

		if (AttackProjectile)
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

				GetWorld()->SpawnActor<AActor>(AttackProjectile, spawnPoint, GetControlRotation());
			}
		}
	}
}