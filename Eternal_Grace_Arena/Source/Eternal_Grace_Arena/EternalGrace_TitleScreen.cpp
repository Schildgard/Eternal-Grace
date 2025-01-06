// Fill out your copyright notice in the Description page of Project Settings.


#include "EternalGrace_TitleScreen.h"
#include "EternalGrace_GameInstance.h"
#include "Kismet/GameplayStatics.h"

void UEternalGrace_TitleScreen::NativeConstruct()
{
	StartGameButton->OnClicked.AddDynamic(this, &UEternalGrace_TitleScreen::StartGame);
	if(TitleMusic)
	{
		UGameplayStatics::PlaySound2D(GetWorld(),TitleMusic);
	}
}

void UEternalGrace_TitleScreen::StartGame()
{
	UGameInstance* CurrentInstance = UGameplayStatics::GetGameInstance(GetWorld());
	if (CurrentInstance)
	{
		UEternalGrace_GameInstance* CustomInstance = Cast<UEternalGrace_GameInstance>(CurrentInstance);
		if (CustomInstance)
		{
			UGameplayStatics::OpenLevel(GetWorld(), CustomInstance->GetMainWorldName());
		}
		else UE_LOG(LogTemp, Error, TEXT("TitleScreen Could not Get Custom-GameInstance"))
	}
	else UE_LOG(LogTemp, Error, TEXT("TitleScreen Could not Get GameInstance"))
}
