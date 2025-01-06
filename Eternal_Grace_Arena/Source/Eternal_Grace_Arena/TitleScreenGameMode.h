// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EternalGrace_TitleScreen.h"
#include "TitleScreenGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API ATitleScreenGameMode : public AGameModeBase
{
	GENERATED_BODY()

	
protected:
virtual void BeginPlay()override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> TitleScreenClass;

	UPROPERTY()
	UEternalGrace_TitleScreen* TitleScreenObject;
};
