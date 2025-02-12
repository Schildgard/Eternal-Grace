// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC_Loretta.h"
#include "EternalGrace_GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "DialogueComponent.h"
#include "EternalGrace_GameInstance.h"

void ANPC_Loretta::BeginPlay()
{
	Super::BeginPlay();
	GetInfoFromGameInstance();
	UE_LOG(LogTemp, Error, TEXT("Loretta Check WinCondition"))
}

void ANPC_Loretta::GetInfoFromGameInstance()
{
	//LORETTA HAS AN ENDING DIALOGUE, IF WIN CONDITION IS MET.
	UGameInstance* CurrentInstance = UGameplayStatics::GetGameInstance(GetWorld());
	UEternalGrace_GameInstance* CustomGameInstance = Cast<UEternalGrace_GameInstance>(CurrentInstance);
	if (CustomGameInstance)
	{
		//CHECK IN GAMEINSTANCE IS WIN CONDITION IS MET
		bool isWinConditionMet = CustomGameInstance->GetWinCondition();
		if (isWinConditionMet == true)
		{
			DialogueComponent->SetCurrentDialogueIndex(1);
			UE_LOG(LogTemp, Error, TEXT("Win Condition Set on loretta"))
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Win Condition is false on loretta"))
		}
	}
}

void ANPC_Loretta::Interact_Implementation()
{
	Super::Interact_Implementation();

	//CHECK IF LAST DIALOGUE IS TRIGGERED
	if (DialogueComponent->GetCurrentDialogueIndex() == DialogueComponent->GetDialogueArraySize() - 1)
	{
		UE_LOG(LogTemp, Error, TEXT("Current Dialogue: %i of %i"), DialogueComponent->GetCurrentDialogueIndex(), DialogueComponent->GetDialogueArraySize() - 1)
			// CHECK IF LAST LINE OF LAST DIALOGUE
			UE_LOG(LogTemp, Error, TEXT("CHECK: Current Line %i of %i"), DialogueComponent->GetCurrentLineIndex(), DialogueComponent->GetLineArraySize() - 1)
			if (DialogueComponent->GetCurrentLineIndex() >= DialogueComponent->GetLineArraySize()-1)
			{
				UE_LOG(LogTemp, Error, TEXT("Current Line %i of %i"), DialogueComponent->GetCurrentLineIndex(), DialogueComponent->GetLineArraySize() - 1)
					UE_LOG(LogTemp, Error, TEXT("Shoudl load Level"))

					UGameInstance* CurrentInstance = UGameplayStatics::GetGameInstance(GetWorld());
				UEternalGrace_GameInstance* CustomGameInstance = Cast<UEternalGrace_GameInstance>(CurrentInstance);
				if (CustomGameInstance)
				{
					CustomGameInstance->SetLevelToLoad("Level_Ending");
					CustomGameInstance->LoadLevel();
				}
			}
	}



}
