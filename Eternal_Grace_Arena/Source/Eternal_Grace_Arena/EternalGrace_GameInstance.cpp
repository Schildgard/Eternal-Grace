// Fill out your copyright notice in the Description page of Project Settings.


#include "EternalGrace_GameInstance.h"
#include "CustomPlayerController.h"
#include "PlayerCharacter.h"
#include "EternalGrace_PlayerState.h"
#include "Kismet/GameplayStatics.h"
#include "HealthComponent.h"

void UEternalGrace_GameInstance::UploadHealthInfo(float HealthFromPlayer)
{
	CurrentHealth = HealthFromPlayer;
}

float UEternalGrace_GameInstance::GetHealthInfo()
{
	return CurrentHealth;
}

void UEternalGrace_GameInstance::ResetHealthInformation()
{
	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if(PlayerCharacter)
	{
		CurrentHealth = PlayerCharacter->HealthComponent->MaxHealth;
	}
	else
		UE_LOG(LogTemp, Error, TEXT("GameInstance: Failed to Cast Player On HealthInfoReset"))
}

void UEternalGrace_GameInstance::OnMapEnter(UWorld* LoadedWorld)
{
		APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	//SAVE VALUES TO PLAYER STATE
	if (PlayerCharacter)
	{
		PlayerCharacter->HealthComponent->CurrentHealth = GetHealthInfo();
	//	UE_LOG(LogTemp, Warning, TEXT("Transmitted Health to Player. %f"), CurrentHealth)
	}
	else UE_LOG(LogTemp, Error, TEXT("GameInstance: Failed to Cast Player On Map Enter Function"))
}

void UEternalGrace_GameInstance::OnMapLeave()
{
	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	//SAVE VALUES TO PLAYER STATE
	if (PlayerCharacter)
	{
		UploadHealthInfo(PlayerCharacter->HealthComponent->CurrentHealth);
//		UE_LOG(LogTemp, Warning, TEXT("Transmitted Health to PlayerState. %f"), CurrentHealth)
	}
	else 
		UE_LOG(LogTemp, Error, TEXT("GameInstance: Failed to Cast Player On Map Leave Function"))
}
