// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "EternalGrace_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API UEternalGrace_GameInstance : public UGameInstance
{
	GENERATED_BODY()

	//PLAYER INFORMATIONS THAT ARE TO KEEP THROUGH MAPTRAVEL
protected:
	UPROPERTY(BlueprintReadWrite, Category = "Player Stats")
	float CurrentHealth = 1000.0f;
public:
	UFUNCTION()
	void UploadHealthInfo(float HealthFromPlayer);
	UFUNCTION()
	float GetHealthInfo();
	UFUNCTION()
	void ResetHealthInformation();


	UFUNCTION()
	void OnMapEnter(UWorld* LoadedWorld);

	UFUNCTION()
	void OnMapLeave();
};
