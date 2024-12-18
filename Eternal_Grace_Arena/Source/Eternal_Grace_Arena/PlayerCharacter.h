// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "PlayerCharacter.generated.h"

/**
 *
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API APlayerCharacter : public AEternal_Grace_ArenaCharacter
{
	GENERATED_BODY()

	APlayerCharacter();
protected:
	virtual void BeginPlay()override;
	virtual void Tick(float DeltaSeconds) override;

};
