// Copyright Epic Games, Inc. All Rights Reserved.

#include "Eternal_Grace_ArenaGameMode.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEternal_Grace_ArenaGameMode::AEternal_Grace_ArenaGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
