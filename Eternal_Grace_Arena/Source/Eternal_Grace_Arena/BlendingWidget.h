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

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	UWidgetAnimation* BlendingAnimation;
	
};
