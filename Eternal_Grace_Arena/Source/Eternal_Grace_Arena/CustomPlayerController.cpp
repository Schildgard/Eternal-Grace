// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerController.h"

ACustomPlayerController::ACustomPlayerController()
{
	HUDWidgetClass = nullptr;
	HUDWidget = nullptr;

}
void ACustomPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if(HUDWidgetClass != nullptr)
	{
		HUDWidget = CreateWidget<UUserWidget>(this, HUDWidgetClass);
		HUDWidget->AddToViewport();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("HUDWidgetClass or HudWidget could not be found"))
	}
}
;
