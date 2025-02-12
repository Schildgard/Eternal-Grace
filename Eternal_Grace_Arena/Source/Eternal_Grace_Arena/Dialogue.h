// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Dialogue.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FDialogue : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialogues, meta = (AllowPrivateAccess))
	TArray<FText> DialogueTexts;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialogues, meta = (AllowPrivateAccess))
	TArray<USoundBase*> DialogueVoices;

};
