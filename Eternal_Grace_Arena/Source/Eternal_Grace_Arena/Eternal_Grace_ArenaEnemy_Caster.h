// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Eternal_Grace_ArenaEnemy.h"
#include "Eternal_Grace_ArenaEnemy_Caster.generated.h"

/**
 * 
 */
class USpellComponent;
class ASpell;
class ASpawnPoint;
class ASpawnManager;
UCLASS()
class ETERNAL_GRACE_ARENA_API AEternal_Grace_ArenaEnemy_Caster : public AEternal_Grace_ArenaEnemy
{
	GENERATED_BODY()
	
protected:
	AEternal_Grace_ArenaEnemy_Caster();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	USpellComponent* SpellComponent;
	UPROPERTY()
	TArray<ASpawnPoint*> SpawnPositions;
	//THIS ARRAY IS USED TO CONTROL IF THE CASTER CAN TELEPORT TO THE SAME POSITION MULTIPLE TIMES
	UPROPERTY()
	TArray<ASpawnPoint*> BlockedSpawnPositions;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	UAnimMontage* TeleportAnim;

	UFUNCTION()
	void CastSpell();

	UFUNCTION(CallInEditor, Category = "Test")
	void CastTeleport();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	UAnimMontage* CastAnimTest;
	UFUNCTION(CallInEditor, Category = "Test")
	void Test_PlayCastAnim();



	virtual void BeginPlay()override;
	virtual void Tick(float DeltaSeconds)override;

public:
	UFUNCTION()
	USpellComponent* GetSpellComponent();
};
