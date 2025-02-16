// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueComponent.h"
#include "Dialogue.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"

// Sets default values for this component's properties
UDialogueComponent::UDialogueComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDialogueComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UDialogueComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
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
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), Dialogues[CurrentDialogueIndex].DialogueVoices[CurrentLineIndex], GetOwner()->GetActorLocation(), 3.0f);
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
				UGameplayStatics::PlaySoundAtLocation(GetWorld(), Dialogues[CurrentDialogueIndex].DialogueVoices[CurrentLineIndex], GetOwner()->GetActorLocation(), 3.0f);
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



