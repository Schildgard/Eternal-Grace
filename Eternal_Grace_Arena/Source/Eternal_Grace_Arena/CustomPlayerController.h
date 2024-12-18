// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "Eternal_Grace_ProgressBar.h"
#include "CustomPlayerController.generated.h"

/**
 *
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API ACustomPlayerController : public APlayerController
{
	GENERATED_BODY()
	ACustomPlayerController();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User Interface", meta = (AllowPrivateAccess))
	TSubclassOf<UEternal_Grace_ProgressBar> HUDWidgetClass;

	UPROPERTY()
	UEternal_Grace_ProgressBar* HUDWidget;

	UPROPERTY()
	AEternal_Grace_ArenaCharacter* PlayerCharacter;

 protected:

	virtual void BeginPlay()override;
	virtual void Tick(float DeltaSeconds)override;


};
