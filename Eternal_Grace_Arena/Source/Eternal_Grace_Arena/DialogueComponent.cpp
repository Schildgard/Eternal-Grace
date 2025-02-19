// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueComponent.h"
#include "Dialogue.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"

// Sets default values for this component's properties
UDialogueComponent::UDialogueComponent()
{

	PrimaryComponentTick.bCanEverTick = false;
	CurrentDialogueIndex = 0;
	CurrentLineIndex = 0;
	DialogueWidget = nullptr;

	AudioComponent = CreateDefaultSubobject<UAudioComponent>("AudioComponent");
}


void UDialogueComponent::PlayDialogue()
{

	// CHECK IF DIALOGUE IS IN VIEWPORT
	if (!DialogueWidget->IsInViewport())
	{
		CurrentLineIndex = 0;
		//ADD TO VIEWPORT / BLEND IN
		DialogueWidget->AddToViewport();
		DialogueWidget->PlayAnimation(DialogueWidget->GetBlendInAnimation());
		//SHOW TEXT AND PLAY VOICE LINE
		DialogueWidget->UpdateDialogueText(Dialogues[CurrentDialogueIndex].DialogueTexts[CurrentLineIndex]);

		if (Dialogues[CurrentDialogueIndex].DialogueVoices.Num() > CurrentLineIndex)
		{
			AudioComponent->SetSound(Dialogues[CurrentDialogueIndex].DialogueVoices[CurrentLineIndex]);
			AudioComponent->Play();
		}
		//INCREMENT LINE INDEX
		CurrentLineIndex++;

	}
	else
	{
		//CHECK IF ALL LINES OF DIALOGUE HAVE BEEN EXHAUSTED
		if (CurrentLineIndex >= Dialogues[CurrentDialogueIndex].DialogueTexts.Num())
		{
			//ENABLE NEXT DIALOGUE
			CurrentDialogueIndex = 1; // TODO: CHANGE TO INCREMENT, BECAUSE THIS IS VERY SPECIFIC TO LORETTA
			//REMOVE FROM VIEWPORT
			DialogueWidget->PlayAnimation(DialogueWidget->GetBlendOutAnimation());
			//CHECK IF THATS THE LAST DIALOGUE
			if (CurrentDialogueIndex >= Dialogues.Num())
			{
				//REPEAT LAST DIALOGUE
				CurrentDialogueIndex = Dialogues.Num() - 1;
			}
		}
		else
		{
			DialogueWidget->UpdateDialogueText(Dialogues[CurrentDialogueIndex].DialogueTexts[CurrentLineIndex]);

			if (Dialogues[CurrentDialogueIndex].DialogueVoices.Num() > CurrentLineIndex)
			{
				AudioComponent->SetSound(Dialogues[CurrentDialogueIndex].DialogueVoices[CurrentLineIndex]);
				AudioComponent->Play();
			}
			//INCREMENT LINE INDEX
			CurrentLineIndex++;
		}
	}

}

void UDialogueComponent::SetCurrentDialogueIndex(int IndexNumber)
{
	CurrentDialogueIndex = IndexNumber;
}

int UDialogueComponent::GetCurrentDialogueIndex()
{
	return CurrentDialogueIndex;
}

int UDialogueComponent::GetDialogueArraySize()
{
	return Dialogues.Num();
}

int UDialogueComponent::GetCurrentLineIndex()
{
	return CurrentLineIndex;
}

int UDialogueComponent::GetLineArraySize()
{
	return Dialogues[CurrentDialogueIndex].DialogueTexts.Num();
}



