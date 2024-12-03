// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API UCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = States, meta = (AllowPrivateAccess))
	bool isRunning;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = States, meta = (AllowPrivateAccess))
	bool isGuarding;
	
};
