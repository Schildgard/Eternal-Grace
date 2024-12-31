// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerController.h"
#include "HealthComponent.h"
#include "StaminaComponent.h"
#include "BlendingWidget.h"

ACustomPlayerController::ACustomPlayerController()
{
	PlayerCharacter = nullptr;
	HUDWidgetClass = nullptr;
	HUDWidget = nullptr;
	YouDiedScreenClass = nullptr;
	YouDiedWidget = nullptr;
}
void ACustomPlayerController::ShowYouDiedScreen()
{
	if(YouDiedScreenClass)
	{
		YouDiedWidget = CreateWidget<UBlendingWidget>(this, YouDiedScreenClass);
		if(YouDiedWidget)
		{
			YouDiedWidget->AddToViewport();
			if(YouDiedWidget->BlendingAnimation)
			{
				YouDiedWidget->PlayAnimation(YouDiedWidget->BlendingAnimation);
			}
			//DEACTIVATE INPUT
			FInputModeUIOnly InputMode;
			SetInputMode(InputMode);
		}
	}
}
void ACustomPlayerController::HideYouDiedScreen()
{
	if(YouDiedWidget)
	{
		YouDiedWidget->RemoveFromViewport();
		//REACTIVATE INPUT
		FInputModeGameOnly InputMode;
		SetInputMode(InputMode);
	}
	
}
void ACustomPlayerController::HandlePlayerDeath()
{
	UE_LOG(LogTemp,Warning, TEXT("Player Death"))
	ShowYouDiedScreen();
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

	PlayerCharacter = Cast<APlayerCharacter>(AcknowledgedPawn);

	if(PlayerCharacter)
	{
		PlayerCharacter->HealthComponent->OnPlayerDied.AddDynamic(this, &ACustomPlayerController::HandlePlayerDeath);
	}

};

void ACustomPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	HUDWidget->UpdateProgressBar(HUDWidget->Healthbar,PlayerCharacter->HealthComponent->MaxHealth, PlayerCharacter->HealthComponent->CurrentHealth);
	HUDWidget->UpdateProgressBar(HUDWidget->Staminabar, PlayerCharacter->StaminaComponent->MaxStamina, PlayerCharacter->StaminaComponent->CurrentStamina);
}
