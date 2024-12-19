// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "PlayerCharacter.generated.h"

/**
 *
 */
class UStaminaComponent;
UCLASS()
class ETERNAL_GRACE_ARENA_API APlayerCharacter : public AEternal_Grace_ArenaCharacter
{
	GENERATED_BODY()

	APlayerCharacter();
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LockOn, meta = (AllowPrivateAccess))
	UStaminaComponent* StaminaComponent;
protected:
	virtual void BeginPlay()override;
	virtual void Tick(float DeltaSeconds) override;

};
