// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StaggeringType.h"
#include "HealthComponent.generated.h"

class AEternal_Grace_ArenaCharacter;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ETERNAL_GRACE_ARENA_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UHealthComponent();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BaseValues, meta = (AllowPrivateAccess))
	float MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BaseValues, meta = (AllowPrivateAccess))
	float CurrentHealth;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
