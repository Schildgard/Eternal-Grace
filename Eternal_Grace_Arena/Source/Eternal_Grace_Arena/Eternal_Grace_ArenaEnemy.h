// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "Components/WidgetComponent.h"
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
protected:
	AEternal_Grace_ArenaEnemy();




	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UI, meta = (AllowPrivateAccess))
	UWidgetComponent* HPBarComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UI, meta = (AllowPrivateAccess))
	UEnemy_UI_Healthbar* HealthbarWidget;

	//PLAYER DETECTION
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI, meta = (AllowPrivateAccess))
	UPawnSensingComponent* SensingComponent;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack, meta = (AllowPrivateAccess))
	float AttackRange;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI, meta = (AllowPrivateAccess))
	bool isAggro;
	UFUNCTION()
	bool CheckDistancetoPlayer(float Threshold); //MAYBE CHANGE THIS TO FLOAT AS A RETURN TYPE
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI, meta = (AllowPrivateAccess))
	//float ChasingCountDown;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI, meta = (AllowPrivateAccess))
	//float ChasingDistanceThreshold;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI, meta = (AllowPrivateAccess))
	//bool ReturningToStartPosition;
	//
	//float const ChasingTimer = 10.0f;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta =(AllowPrivateAccess))
	float BackDetection;


	UFUNCTION()
	void SpotPlayer(APawn* SpottedPawn);

	//THE OBJECTID REFERRS TO THE OBJECT ID WHICH THE DEATH OF THIS ENEMY SHOULD INFLUENCE VIA GAME INSTANCE
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Relation, meta = (AllowPrivateAccess))
	TMap<FName, bool> ReferencedObjectIds;

	UFUNCTION()
	virtual void SendInfoToGameInstance();

	UFUNCTION()
	bool CheckIfPlayerIsBehind();


	UFUNCTION()
	void ResetCollision(UAnimMontage* AttackAnimation, bool Interrupted);

protected:
	virtual void BeginPlay()override;
	virtual void Tick(float DeltaSeconds)override;
	virtual void Die_Implementation()override;
	
	
};
