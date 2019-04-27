#include "Salvage.h"
#include "Salvage.ac.h"

extends(AActor)

prop(float HealthBonus)
prop(USphereComponent* CollisionComp)
prop(UStaticMeshComponent* Mesh)

fun::ASalvage()
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &fun::OnHit);		// set up a notification for when this component hits something blocking

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	CollisionComp->AttachToComponent(Mesh, FAttachmentTransformRules::KeepRelativeTransform);

	RootComponent = Mesh;
}

void fun::OnHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (auto pc = Cast<ALD44Character>(OtherActor))
	{
		pc->SetHealth(pc->GetHealth() + HealthBonus);
		HealthBonus = 0;
		Destroy();
	}
}