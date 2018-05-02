// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "ProovingGroundsGameMode.h"
#include "ProovingGroundsHUD.h"
#include "ProovingGroundsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProovingGroundsGameMode::AProovingGroundsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AProovingGroundsHUD::StaticClass();
}
