// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "InputAction.h"
#include "PlayerCharacter.h"
#include "Eternal_Grace_ProgressBar.h"
#include "Player_UI_Bars.h"
#include "CustomPlayerController.generated.h"

/**
 *
 */
class UBlendingWidget;
class UEternalGrace_GameInstance;
class ULockOnSystem;
class AEternal_Grace_ArenaCharacter;
class UPostProcessComponent;
UCLASS()
class ETERNAL_GRACE_ARENA_API ACustomPlayerController : public APlayerController
{
	GENERATED_BODY()
	ACustomPlayerController();

public:
	//PLAYER HUD
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User Interface", meta = (AllowPrivateAccess))
	TSubclassOf<UPlayer_UI_Bars> HUDWidgetClass;
	UPROPERTY()
	UPlayer_UI_Bars* HUDWidget;

	UPROPERTY()
	APlayerCharacter* PlayerCharacter;

	//DEATH HANDLING
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User Interface", meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> YouDiedScreenClass;
	UPROPERTY()
	UBlendingWidget* YouDiedWidget;


	UFUNCTION()
	void ShowYouDiedScreen();
	UFUNCTION()
	void HideYouDiedScreen();
	UFUNCTION()
	void HandlePlayerDeath();




protected:
	//LOCKON SYSTEM
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LockOn, meta = (AllowPrivateAccess))
	ULockOnSystem* LockOnSystem;
	UPROPERTY()
	UEternalGrace_GameInstance* ActiveGameInstance;

	UFUNCTION()
	AEternal_Grace_ArenaCharacter* FindNearestTarget();
	UFUNCTION()
	virtual TArray<AActor*> ScanForTargets();

	//LOCKON PROPERTIES
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LockOn, meta = (AllowPrivateAccess))
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess))
	UInputAction* ToggleLockOnAction;



 protected:
	 virtual void SetupInputComponent() override;
	virtual void BeginPlay()override;
	virtual void Tick(float DeltaSeconds)override;

	virtual void AddYawInput(float Val) override;
	virtual void AddRollInput(float Val) override;
	virtual void AddPitchInput(float Val) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera", meta = (AllowPrivateAccess))
	float Sensitivity;

	UFUNCTION()
	void ReloadLevel();


public:
	UFUNCTION()
	ULockOnSystem* GetLockOnSystem();
	UFUNCTION(BlueprintCallable, Category = "LockOn")
	void ToggleLockOn();
};
