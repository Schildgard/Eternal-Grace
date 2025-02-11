// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimatedWidget.h"
#include "Components/TextBlock.h"
#include "DialogueWidget.generated.h"

/**
 * 
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API UDialogueWidget : public UAnimatedWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* DisplayText;

public:
	UFUNCTION()
	void UpdateDialogueText(FText InputText);

	UFUNCTION()
	FText GetDisplayText();
};
