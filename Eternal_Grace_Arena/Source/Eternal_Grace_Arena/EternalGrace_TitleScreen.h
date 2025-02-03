// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "EternalGrace_TitleScreen.generated.h"

/**
 * 
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API UEternalGrace_TitleScreen : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct()override;

protected:
	UPROPERTY(meta = (BindWidget), Transient)
	UPanelWidget* MainPanel;
	UPROPERTY(meta = (BindWidgetOptional), Transient)
	UButton* StartGameButton;
	UPROPERTY(meta = (BindWidget), Transient)
	UImage* BackgroundImage;
	UPROPERTY(meta = (BindWidget), Transient)
	UTextBlock* TitleText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess),Transient)
	USoundBase* TitleMusic;

	UPROPERTY(meta=(BindWidgetAnimOptional), Transient)
	UWidgetAnimation* ScrollAnimation;

//	UPROPERTY()
//	UEternalGrace_GameInstance* ActivGameInstance;

	UFUNCTION()
	void StartGame();
		
};
