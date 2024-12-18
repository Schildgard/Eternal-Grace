// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "CustomPlayerController.generated.h"

/**
 *
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API ACustomPlayerController : public APlayerController
{
	GENERATED_BODY()
	ACustomPlayerController();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User Interface", meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> HUDWidgetClass;

	UPROPERTY()
	UUserWidget* HUDWidget;

protected:

	virtual void BeginPlay()override;


};
