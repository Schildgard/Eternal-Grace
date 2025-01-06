// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleScreenGameMode.h"
#include "Kismet/GameplayStatics.h"

void ATitleScreenGameMode::BeginPlay()
{
	if (TitleScreenClass)
	{
		APlayerController* CurrentController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		if (CurrentController)
		{
			TitleScreenObject = CreateWidget<UEternalGrace_TitleScreen>(CurrentController, TitleScreenClass);
			if (TitleScreenObject)
			{
				TitleScreenObject->AddToViewport();
			}UE_LOG(LogTemp, Error, TEXT("Failed to Create TitleScreen Object"))
		}
	}
	else UE_LOG(LogTemp, Error, TEXT("No TitleScreen Class Assigned"))
}
