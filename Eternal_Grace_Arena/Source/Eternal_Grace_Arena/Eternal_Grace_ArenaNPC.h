// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Eternal_Grace_ArenaEnemy.h"
#include "I_Interactable.h"
#include "Eternal_Grace_ArenaNPC.generated.h"

/**
 * 
 */
class USphereComponent;
UCLASS()
class ETERNAL_GRACE_ARENA_API AEternal_Grace_ArenaNPC : public AEternal_Grace_ArenaEnemy, public II_Interactable
{
	GENERATED_BODY()
	
protected:
	AEternal_Grace_ArenaNPC();

	//INTERACTION SPHERE
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Interaction, meta = (AllowPrivateAccess))
	USphereComponent* InteractionRadius;
	UPROPERTY()
	float DefaultRadiusSize;
	UFUNCTION()
	virtual void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent,AActor* OtherActor,UPrimitiveComponent* OtherComponent,int32 OtherBodyIndex,bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent,AActor* OtherActor,UPrimitiveComponent* OtherComponent,int32 OtherBodyIndex);


	// TALK TOOLTIP
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> InfoClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	UAnimatedWidget* InteractInfoWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialogues, meta = (AllowPrivateAccess))
	UAnimatedWidget* DialogueWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialogues, meta = (AllowPrivateAccess))
	TArray<FText> DialogueTexts;


	virtual void BeginPlay()override;

public:
	virtual void Interact_Implementation()override;



};
