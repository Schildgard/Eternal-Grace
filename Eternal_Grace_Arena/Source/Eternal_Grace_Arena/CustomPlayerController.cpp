// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerController.h"
#include "HealthComponent.h"
#include "StaminaComponent.h"
#include "BlendingWidget.h"
#include "Kismet/GameplayStatics.h"
//#include "GameFramework/PlayerState.h"
#include "EternalGrace_PlayerState.h"

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
	//CHECK IF YOU DIED SCREEN CLASS WAS ASSIGNED IN EDITOR
	if (YouDiedScreenClass)
	{
		//CREATE OBJECT OF YOU DIED SCREEN CLASS
		YouDiedWidget = CreateWidget<UBlendingWidget>(this, YouDiedScreenClass);
		if (YouDiedWidget)
		{
			//ACTIVATE YOU DIED SCREEN TO VIEWPORT
			YouDiedWidget->AddToViewport();
			if (YouDiedWidget->BlendingAnimation)
			{
				//ACTIVATE BLEND IN ANIMATION
				YouDiedWidget->PlayAnimation(YouDiedWidget->BlendingAnimation);
				//BIND LEVEL RELOAD TO YOU DIED SCREEN
				FWidgetAnimationDynamicEvent Reload;
				Reload.BindDynamic(this, &ACustomPlayerController::ReloadLevel);
				YouDiedWidget->BindToAnimationFinished(YouDiedWidget->BlendOutAnimation, Reload);
				//MAKE BLEND OUT ASYNCHRON OR SOMETHING????
			}
			//DEACTIVATE INPUT
			FInputModeUIOnly InputMode;
			SetInputMode(InputMode);
		}
	}
}
void ACustomPlayerController::HideYouDiedScreen()
{
	//PROBABLY UNNECCESSARY
	if (YouDiedWidget)
	{
		YouDiedWidget->RemoveFromViewport();
		//REACTIVATE INPUT
		FInputModeGameOnly InputMode;
		SetInputMode(InputMode);
	}

}
void ACustomPlayerController::HandlePlayerDeath()
{
	UE_LOG(LogTemp, Warning, TEXT("Player Death"))
		ShowYouDiedScreen();
}
void ACustomPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (HUDWidgetClass != nullptr)
	{
		HUDWidget = CreateWidget<UPlayer_UI_Bars>(this, HUDWidgetClass);
		HUDWidget->AddToViewport();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("HUDWidgetClass or HudWidget could not be found"))
	}

	PlayerCharacter = Cast<APlayerCharacter>(AcknowledgedPawn);

	if (PlayerCharacter)
	{
		PlayerCharacter->HealthComponent->OnPlayerDied.AddDynamic(this, &ACustomPlayerController::HandlePlayerDeath);
	}
	UE_LOG(LogTemp, Error, TEXT("load controller"))
};

void ACustomPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (HUDWidget)
	{
		HUDWidget->UpdateProgressBar(HUDWidget->Healthbar, PlayerCharacter->HealthComponent->MaxHealth, PlayerCharacter->HealthComponent->CurrentHealth);
		HUDWidget->UpdateProgressBar(HUDWidget->Staminabar, PlayerCharacter->StaminaComponent->MaxStamina, PlayerCharacter->StaminaComponent->CurrentStamina);
	}
}

void ACustomPlayerController::ReloadLevel()
{
	FName CurrentLevelName = FName(*GetWorld()->GetMapName());

	UGameplayStatics::OpenLevel(this, CurrentLevelName);

	//REACTIVATE INPUT
	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
}

void ACustomPlayerController::OnMapLeave()
{
	//SAVE VALUES TO PLAYER STATE
	if (PlayerCharacter)
	{
		APlayerState* ActivePlayerState = GetPlayerState<APlayerState>();
				if (ActivePlayerState)
				{
					AEternalGrace_PlayerState* CustomPlayerState = Cast<AEternalGrace_PlayerState>(ActivePlayerState);
					if (CustomPlayerState)
					{
						CustomPlayerState->SetPlayerHealth(PlayerCharacter->HealthComponent->CurrentHealth);
						UE_LOG(LogTemp, Warning, TEXT("Transmitted Player Health to PlayerState. %f"),CustomPlayerState->GetPlayerHealth())
		
					}
				}
	}
}
void ACustomPlayerController::OnMapEnter2()
{
	UE_LOG(LogTemp, Warning, TEXT("OnMapEnter"))
	//LOAD VALUES FROM PLAYER STATE
	if (PlayerCharacter)
	{
		APlayerState* ActivePlayerState = GetPlayerState<APlayerState>();
		if (ActivePlayerState)
		{
			AEternalGrace_PlayerState* CustomPlayerState = Cast<AEternalGrace_PlayerState>(ActivePlayerState);
			if (CustomPlayerState)
			{
				PlayerCharacter->HealthComponent->CurrentHealth = CustomPlayerState->GetPlayerHealth();
				UE_LOG(LogTemp, Warning, TEXT("Transmitted PlayerState Health to Player. %f"),CustomPlayerState->GetPlayerHealth())

			}
		}
	}
}