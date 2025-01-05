// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
//#include "Eternal_Grace_ArenaCharacter.h"
#include "PlayerCharacter.h"
#include "Eternal_Grace_ProgressBar.h"
#include "Player_UI_Bars.h"
#include "CustomPlayerController.generated.h"

/**
 *
 */
class UBlendingWidget;
class UEternalGrace_GameInstance;
UCLASS()
class ETERNAL_GRACE_ARENA_API ACustomPlayerController : public APlayerController
{
	GENERATED_BODY()
	ACustomPlayerController();

public:
	//PLAYER HUD
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User Interface", meta = (AllowPrivateAccess))
	TSubclassOf<UPlayer_UI_Bars> HUDWidgetClass;
	UPROPERTY()
	UPlayer_UI_Bars* HUDWidget;
	UPROPERTY()
	APlayerCharacter* PlayerCharacter;

	//DEATH HANDLING
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User Interface", meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> YouDiedScreenClass;
	UPROPERTY()
	UBlendingWidget* YouDiedWidget;
	UFUNCTION()
	void ShowYouDiedScreen();
	UFUNCTION()
	void HideYouDiedScreen();
	UFUNCTION()
	void HandlePlayerDeath();



 protected:
	//REFERENCE TO CURRENT GAMEINSTANCE
	UPROPERTY()
	UEternalGrace_GameInstance* ActiveGameInstance;

	virtual void BeginPlay()override;
	virtual void Tick(float DeltaSeconds)override;

	UFUNCTION()
	void ReloadLevel();



};
