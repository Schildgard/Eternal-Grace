// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "I_Interactable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UI_Interactable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ETERNAL_GRACE_ARENA_API II_Interactable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent) // BlueprintNativeEvent makes that the function can be overwritten in c++ but also be implemented in blueprint
	void Interact();
};
