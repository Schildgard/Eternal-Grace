// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DialogueWidget.h"
#include "DialogueComponent.generated.h"

struct FDialogue;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ETERNAL_GRACE_ARENA_API UDialogueComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UDialogueComponent();



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialogues, meta = (AllowPrivateAccess))
	UDialogueWidget* DialogueWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialogues, meta = (AllowPrivateAccess))
	TArray<FDialogue> Dialogues;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio, meta = (AllowPrivateAccess))
	UAudioComponent* AudioComponent;




protected:
	UPROPERTY()
	int CurrentDialogueIndex;
	UPROPERTY()
	int CurrentLineIndex;

public:	

	UFUNCTION()
	void PlayDialogue();

	UFUNCTION()
	void SetCurrentDialogueIndex(int IndexNumber);

	UFUNCTION()
	int GetCurrentDialogueIndex();

	UFUNCTION()
	int GetDialogueArraySize();

	UFUNCTION()
	int GetCurrentLineIndex();

	UFUNCTION()
	int GetLineArraySize();



		
};
