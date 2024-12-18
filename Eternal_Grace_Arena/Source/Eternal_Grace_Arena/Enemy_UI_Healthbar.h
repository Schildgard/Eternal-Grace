// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Eternal_Grace_ProgressBar.h"
#include "Enemy_UI_Healthbar.generated.h"

/**
 * 
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API UEnemy_UI_Healthbar : public UEternal_Grace_ProgressBar
{
	GENERATED_BODY()
	public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UI, meta = (BindWidget))
	UProgressBar* Healthbar;
};
