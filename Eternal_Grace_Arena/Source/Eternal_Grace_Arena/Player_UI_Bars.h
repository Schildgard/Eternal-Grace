// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Eternal_Grace_ProgressBar.h"
#include "Player_UI_Bars.generated.h"

/**
 * 
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API UPlayer_UI_Bars : public UEternal_Grace_ProgressBar
{
	GENERATED_BODY()

	public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UI, meta = (BindWidget))
	UProgressBar* Healthbar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UI, meta = (BindWidget))
	UProgressBar* Staminabar;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UI, meta = (BindWidget))
	//UProgressBar* Pressurebar;
	
};
