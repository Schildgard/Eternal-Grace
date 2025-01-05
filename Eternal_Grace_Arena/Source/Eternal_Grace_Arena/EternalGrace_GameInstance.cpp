// Fill out your copyright notice in the Description page of Project Settings.


#include "EternalGrace_GameInstance.h"
#include "CustomPlayerController.h"
#include "PlayerCharacter.h"
#include "EternalGrace_PlayerState.h"
#include "Kismet/GameplayStatics.h"
#include "HealthComponent.h"

void UEternalGrace_GameInstance::SetPlayerHealth(float HealthFromPlayer)
{
	CurrentHealth = HealthFromPlayer;
}

float UEternalGrace_GameInstance::GetPlayerHealth()
{
	return CurrentHealth;
}

void UEternalGrace_GameInstance::OnMapEnter(UWorld* LoadedWorld)
{
	UE_LOG(LogTemp, Error, TEXT("GameInstance: Enter Map"))

		APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	//SAVE VALUES TO PLAYER STATE
	if (PlayerCharacter)
	{
		PlayerCharacter->HealthComponent->CurrentHealth = GetPlayerHealth();
		UE_LOG(LogTemp, Warning, TEXT("Transmitted Health to Player. %f"), CurrentHealth)
	}
	else UE_LOG(LogTemp, Error, TEXT("GameInstance: Failed to Cast Player On Map Enter Function"))
}

void UEternalGrace_GameInstance::OnMapLeave()
{
	UE_LOG(LogTemp, Error, TEXT("GameInstance: Leave Map"))
	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	//SAVE VALUES TO PLAYER STATE
	if (PlayerCharacter)
	{
		SetPlayerHealth(PlayerCharacter->HealthComponent->CurrentHealth);
		UE_LOG(LogTemp, Warning, TEXT("Transmitted Health to PlayerState. %f"), CurrentHealth)
	}
	else 
		UE_LOG(LogTemp, Error, TEXT("GameInstance: Failed to Cast Player On Map Leave Function"))
}
