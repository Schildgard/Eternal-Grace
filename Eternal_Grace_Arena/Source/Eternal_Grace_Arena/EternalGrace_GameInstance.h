// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "EternalGrace_GameInstance.generated.h"

/**
 *
 */
 //WORLD UPDATE MEANS WHEN SOMETHING HAPPENES THAT CHANGES THINGS IN THE WORLD, LIKE DEFEATING A BOSS WHICH CHANGES oBJECTSTATES 
class UBlendingWidget;
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWorldUpdate);

UCLASS()
class ETERNAL_GRACE_ARENA_API UEternalGrace_GameInstance : public UGameInstance
{
	GENERATED_BODY()

	UEternalGrace_GameInstance();
	//PLAYER INFORMATIONS THAT ARE TO KEEP THROUGH MAPTRAVEL
protected:
	UPROPERTY(BlueprintReadWrite, Category = "Player Stats")
	float CurrentHealth = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	FName MainWorldName;

	UPROPERTY()
	bool WinCondition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	TMap<FName, bool> WinConditionDependencies;


//	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
//	TSubclassOf<UUserWidget> LoadingScreenClass;
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
//	UBlendingWidget* LoadingScreen;



public:
	FOnWorldUpdate OnObjectStateChange;
	UFUNCTION()
	void UploadHealthInfo(float HealthFromPlayer);
	UFUNCTION()
	float GetHealthInfo();
	UFUNCTION()
	void ResetHealthInformation();

	// MAP TRAVELLING
	UFUNCTION()
	void OnMapEnter(UWorld* LoadedWorld);
	UFUNCTION()
	void OnMapLeave();

	//KEEPING TRACK OF WORLD STATE
	UPROPERTY()
	TMap<FName, bool> ObjectStates;

	UFUNCTION()
	void SetObjectState(FName ObjectID, bool NewValue);

	UFUNCTION()
	void ReturnToMainLevel();
	UFUNCTION()
	FName GetMainWorldName();

	UFUNCTION()
	void CheckWinConditionChange();
};
