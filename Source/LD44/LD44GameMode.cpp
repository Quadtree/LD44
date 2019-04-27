// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "LD44GameMode.h"
#include "LD44HUD.h"
#include "LD44Character.h"
#include "UObject/ConstructorHelpers.h"

ALD44GameMode::ALD44GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ALD44HUD::StaticClass();
}
