// Copyright Epic Games, Inc. All Rights Reserved.

#include "ESAME_IlariaSergiGameMode.h"
#include "ESAME_IlariaSergiCharacter.h"
#include "UObject/ConstructorHelpers.h"

AESAME_IlariaSergiGameMode::AESAME_IlariaSergiGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
