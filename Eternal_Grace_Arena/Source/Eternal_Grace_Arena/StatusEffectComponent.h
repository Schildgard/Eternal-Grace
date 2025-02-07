// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StatusEffectComponent.generated.h"

class AEternal_Grace_ArenaCharacter;
class UPostProcessComponent;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ETERNAL_GRACE_ARENA_API UStatusEffectComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UStatusEffectComponent();

protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	bool isPoisoned;
	UPROPERTY()
	AEternal_Grace_ArenaCharacter* OwningCharacter;

	UPROPERTY()
	float PoisonDamage;

public:	

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void SetIsPoisoned(bool Condition);

	UFUNCTION()
	bool GetIsPoisoned();

		
};
