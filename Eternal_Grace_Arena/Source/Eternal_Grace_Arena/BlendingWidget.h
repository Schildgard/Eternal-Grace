// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BlendingWidget.generated.h"

/**
 * 
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API UBlendingWidget : public UUserWidget
{
	GENERATED_BODY()
	//ANIMATED WIDGET DO DISAPPEAR AFTER BLENDING IN, IN OPPOSITE TO BLENDING WIDGETS
protected:
	//CREATE DELEGATE TO POINT AT FUNCTION TO PLAY WHEN ANIMATION STARTS
	FWidgetAnimationDynamicEvent StartDelegate;
	FWidgetAnimationDynamicEvent EndDelegate;
	virtual void NativeConstruct()override;
public:
	//TRANSIENT signalizes that the property only exists in runtime and endloads after playing
	UPROPERTY(meta = (BindWidgetAnim), Transient)
	UWidgetAnimation* BlendingAnimation;
	UPROPERTY(meta = (BindWidgetAnim), Transient)
	UWidgetAnimation* BlendOutAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	USoundBase* AnimationSound;
	

	UFUNCTION()
	void PlayAnimationSound();
	UFUNCTION()
	void BlendOut();


};
