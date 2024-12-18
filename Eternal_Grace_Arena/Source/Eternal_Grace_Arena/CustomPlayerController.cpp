// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerController.h"
#include "HealthComponent.h"

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
		HUDWidget = CreateWidget<UPlayer_UI_Bars>(this, HUDWidgetClass);
		HUDWidget->AddToViewport();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("HUDWidgetClass or HudWidget could not be found"))
	}

	PlayerCharacter = Cast<AEternal_Grace_ArenaCharacter>(AcknowledgedPawn);

};

void ACustomPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	HUDWidget->UpdateProgressBar(HUDWidget->Healthbar,PlayerCharacter->HealthComponent->MaxHealth, PlayerCharacter->HealthComponent->CurrentHealth);
}
