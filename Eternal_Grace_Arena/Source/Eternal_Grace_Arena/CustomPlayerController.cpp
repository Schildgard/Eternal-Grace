// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerController.h"
#include "HealthComponent.h"
#include "StaminaComponent.h"
#include "BlendingWidget.h"
#include "Kismet/GameplayStatics.h"
#include "EternalGrace_GameInstance.h"

ACustomPlayerController::ACustomPlayerController()
{
	PlayerCharacter = nullptr;
	HUDWidgetClass = nullptr;
	HUDWidget = nullptr;
	YouDiedScreenClass = nullptr;
	YouDiedWidget = nullptr;
	ActiveGameInstance = nullptr;
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
	ShowYouDiedScreen();
}
void ACustomPlayerController::BeginPlay()
{
	Super::BeginPlay();
	//CREATE AND SHOW PLAYER HUD
	if (HUDWidgetClass != nullptr)
	{
		HUDWidget = CreateWidget<UPlayer_UI_Bars>(this, HUDWidgetClass);
		HUDWidget->AddToViewport();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("CustomPlayer Controller could not find HUDWidgetClass or HudWidget"))
	}
	PlayerCharacter = Cast<APlayerCharacter>(AcknowledgedPawn);
	if (PlayerCharacter)
	{
		//SUBSCRIBE DEATH HANDLING TO ON DIE EVENT
		PlayerCharacter->HealthComponent->OnCharacterDeath.AddDynamic(this, &ACustomPlayerController::HandlePlayerDeath);
		//SUBSCRIBE RESET HEALTH INFORMATION TO DIE EVENT 
		ActiveGameInstance = Cast<UEternalGrace_GameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
		if (ActiveGameInstance)
		{
			PlayerCharacter->HealthComponent->OnCharacterDeath.AddDynamic(ActiveGameInstance, &UEternalGrace_GameInstance::ResetHealthInformation);
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("CustomPlayer Controller could not Cast to Player Class"))
	}
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
	ActiveGameInstance->ReturnToMainLevel();

	//REACTIVATE INPUT
	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
}
