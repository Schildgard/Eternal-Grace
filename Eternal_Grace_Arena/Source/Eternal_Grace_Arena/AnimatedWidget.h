// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AnimatedWidget.generated.h"

/**
 * 
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API UAnimatedWidget : public UUserWidget
{
	GENERATED_BODY()
	
	//ANIMATED WIDGET DO NOT DISAPPEAR AFTER BLENDING IN, IN OPPOSITE TO BLENDING WIDGETS
protected:
	virtual void NativeConstruct()override;
	FWidgetAnimationDynamicEvent EndDelegate;

	UPROPERTY(meta = (BindWidgetAnim), Transient)
	UWidgetAnimation* BlendingAnimation;
	UPROPERTY(meta = (BindWidgetAnim), Transient)
	UWidgetAnimation* BlendOutAnimation;

public:
	UFUNCTION()
	void BlendOut();
	UFUNCTION()
	UWidgetAnimation* GetBlendInAnimation();
	UFUNCTION()
	UWidgetAnimation* GetBlendOutAnimation();
};
