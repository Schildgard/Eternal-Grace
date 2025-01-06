// Fill out your copyright notice in the Description page of Project Settings.


#include "EternalGrace_TitleScreen.h"
#include "EternalGrace_GameInstance.h"
#include "Kismet/GameplayStatics.h"

void UEternalGrace_TitleScreen::NativeConstruct()
{
	//BackgroundImage->SetDesiredSizeOverride(FVector2D(1920.0f, 1080.0f));

	StartGameButton->OnClicked.AddDynamic(this, &UEternalGrace_TitleScreen::StartGame);

}

void UEternalGrace_TitleScreen::StartGame()
{
	UGameInstance* CurrentInstance = UGameplayStatics::GetGameInstance(GetWorld());

	if (CurrentInstance)
	{
		UEternalGrace_GameInstance* CustomInstance = Cast<UEternalGrace_GameInstance>(CurrentInstance);
		if (CustomInstance)
		{
			UGameplayStatics::OpenLevelBySoftObjectPtr(GetWorld(), CustomInstance->GetMainWorld());
		}
		else UE_LOG(LogTemp, Error, TEXT("TitleScreen Could not Get Custom-GameInstance"))
	}
	else UE_LOG(LogTemp, Error, TEXT("TitleScreen Could not Get Custom-GameInstance"))
}
