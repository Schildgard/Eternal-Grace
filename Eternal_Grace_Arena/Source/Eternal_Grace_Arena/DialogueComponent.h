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





protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY()
	int CurrentDialogueIndex;
	UPROPERTY()
	int CurrentLineIndex;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void PlayDialogue();

		
};
