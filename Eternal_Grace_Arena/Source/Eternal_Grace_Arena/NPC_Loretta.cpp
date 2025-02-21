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
	FinalDialogueIndex = 2;
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
			DialogueComponent->SetCurrentDialogueIndex(FinalDialogueIndex); // HARD CODED, 
			UE_LOG(LogTemp, Error, TEXT("Win Condition Set on loretta"))
		}
	}
}

void ANPC_Loretta::Interact_Implementation()
{

	//CHECK IF LAST DIALOGUE IS TRIGGERED
	if (DialogueComponent->GetCurrentDialogueIndex() == DialogueComponent->GetDialogueArraySize() - 1)
	{
		// CHECK IF LAST LINE OF LAST DIALOGUE
		if (DialogueComponent->GetCurrentLineIndex() > DialogueComponent->GetLineArraySize() - 1)
		{
			UGameInstance* CurrentInstance = UGameplayStatics::GetGameInstance(GetWorld());
			UEternalGrace_GameInstance* CustomGameInstance = Cast<UEternalGrace_GameInstance>(CurrentInstance);
			if (CustomGameInstance)
			{
				CustomGameInstance->SetLevelToLoad("Level_Ending");
				CustomGameInstance->OnMapLeave();
			}
		}
	}

	Super::Interact_Implementation();


}
