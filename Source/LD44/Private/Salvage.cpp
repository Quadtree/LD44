#include "Salvage.h"
#include "Salvage.ac.h"

extends(AActor)

prop(float HealthBonus)
prop(USphereComponent* CollisionComp)

fun::ASalvage()
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->OnComponentHit.AddDynamic(this, &fun::OnHit);		// set up a notification for when this component hits something blocking
}

void fun::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (auto pc = Cast<ALD44Character>(OtherActor))
	{
		pc->SetHealth(pc->GetHealth() + HealthBonus);
		HealthBonus = 0;
		Destroy();
	}
}