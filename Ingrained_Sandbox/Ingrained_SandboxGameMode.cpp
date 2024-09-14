// Copyright Epic Games, Inc. All Rights Reserved.

#include "Ingrained_SandboxGameMode.h"
#include "Ingrained_SandboxCharacter.h"
#include "UObject/ConstructorHelpers.h"

AIngrained_SandboxGameMode::AIngrained_SandboxGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
