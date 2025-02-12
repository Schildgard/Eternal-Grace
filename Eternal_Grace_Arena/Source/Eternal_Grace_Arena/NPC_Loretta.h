// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Eternal_Grace_ArenaNPC.h"
#include "NPC_Loretta.generated.h"

/**
 * 
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API ANPC_Loretta : public AEternal_Grace_ArenaNPC
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay()override;
	virtual void GetInfoFromGameInstance()override;
	virtual void Interact_Implementation()override;
};
