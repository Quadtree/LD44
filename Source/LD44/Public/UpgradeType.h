#pragma once
#include "EngineMinimal.h"

UENUM(BlueprintType)
enum class EUpgradeType : uint8
{
	UT_PrimaryFire,
	UT_AltFire,
	UT_EnergyRegeneration,
	UT_Armor,
	UT_Jumping,
	UT_MovementSpeed,
	UT_Max,
};
