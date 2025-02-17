// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Eternal_Grace_ArenaEnemy.h"
#include "Eternal_Grace_ArenaBoss.generated.h"

/**
 * 
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API AEternal_Grace_ArenaBoss : public AEternal_Grace_ArenaEnemy
{
	GENERATED_BODY()


public:
	AEternal_Grace_ArenaBoss();

	UPROPERTY()
	bool SecondPhaseTriggered;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations, meta = (AllowPrivateAccess))
	UAnimMontage* SecondPhaseMontage;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations, meta = (AllowPrivateAccess))
	UAnimMontage* GetOffMeAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UI, meta = (AllowPrivateAccess))
	TSubclassOf<UEnemy_UI_Healthbar> HealthbarWidgetClass;



	UFUNCTION()
	virtual void TriggerSecondPhase();
	virtual void Tick(float DeltaSeconds)override;
	virtual void BeginPlay()override;
	virtual void SpotPlayer(APawn* SpottedPawn)override;


protected:
	UFUNCTION()
	virtual void GetOffMeMove();


	
};
