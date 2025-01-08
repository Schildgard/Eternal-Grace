// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "Blueprint/UserWidget.h"
#include "HealthComponent.h"
#include "Components/WidgetComponent.h"
#include "Eternal_Grace_ProgressBar.h"
#include "Enemy_UI_Healthbar.h"
#include "Eternal_Grace_ArenaEnemy.generated.h"

/**
 * 
 */
class UPawnSensingComponent;
UCLASS()
class ETERNAL_GRACE_ARENA_API AEternal_Grace_ArenaEnemy : public AEternal_Grace_ArenaCharacter
{
	GENERATED_BODY()
	
	AEternal_Grace_ArenaEnemy();
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack, meta = (AllowPrivateAccess))
	float AttackRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UI, meta = (AllowPrivateAccess))
	UWidgetComponent* HPBarComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UI, meta = (AllowPrivateAccess))
	UEnemy_UI_Healthbar* HealthbarWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Actions, meta = (AllowPrivateAccess))
	TArray<UAnimMontage*> AttackMontages;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Actions, meta = (AllowPrivateAccess))
	UAnimMontage* SecondPhaseMontage;

	//PLAYER DETECTION
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI, meta = (AllowPrivateAccess))
	UPawnSensingComponent* SensingComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI, meta = (AllowPrivateAccess))
	bool isAggro;
	UFUNCTION()
	bool CheckDistancetoPlayer(float Threshold);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI, meta = (AllowPrivateAccess))
	float ChasingCountDown;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI, meta = (AllowPrivateAccess))
	float ChasingDistanceThreshold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI, meta = (AllowPrivateAccess))
	bool ReturningToStartPosition;

	float const ChasingTimer = 10.0f;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta =(AllowPrivateAccess))
	float BackDetection;

	UPROPERTY()
	bool CanPerformGettOffMeMove;

	UFUNCTION(BlueprintCallable, CallInEditor, Category = Actions)
	void GetOffMeMove();
	virtual void LightAttack()override;

	UFUNCTION()
	void SpotPlayer(APawn* SpottedPawn);

	//THE OBJECTID REFERRS TO THE OBJECT ID WHICH THE DEATH OF THIS ENEMY SHOULD INFLUENCE VIA GAME INSTANCE
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Relation, meta = (AllowPrivateAccess))
	//TArray<FName> RelatedObjectIDs;
	TMap<FName, bool> ReferencedObjectIds;

	UFUNCTION()
	void SendInfoToGameInstance();

	UFUNCTION()
	float ShowDistanceVectorToPlayer();

	UFUNCTION()
	void TriggerSecondPhase();


protected:
	virtual void BeginPlay()override;
	virtual void Tick(float DeltaSeconds)override;
	virtual void DeathEvent()override;
	
	
};
