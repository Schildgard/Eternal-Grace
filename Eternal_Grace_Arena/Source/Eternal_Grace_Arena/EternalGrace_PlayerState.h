// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "EternalGrace_PlayerState.generated.h"

/**
 * 
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API AEternalGrace_PlayerState : public APlayerState
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, Category = "Player Stats")
	float CurrentHealth = 1000.0f;

public:
	UFUNCTION()
	void SetPlayerHealth(float HealthFromPlayer);
	UFUNCTION()
	float GetPlayerHealth();


};
