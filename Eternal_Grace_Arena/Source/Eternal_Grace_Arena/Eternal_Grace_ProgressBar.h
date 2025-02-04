// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Eternal_Grace_ProgressBar.generated.h"

/**
 * 
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API UEternal_Grace_ProgressBar : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual void UpdateProgressBar(UProgressBar* Progressbar, float MaxValue, float CurrentValue);
	
	
};
