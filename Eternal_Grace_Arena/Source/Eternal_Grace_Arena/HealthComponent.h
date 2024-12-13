// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ETERNAL_GRACE_ARENA_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = BaseValues, meta = (AllowPrivateAccess))
	float MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = BaseValues, meta = (AllowPrivateAccess))
	float CurrentHealth;
public:
	UFUNCTION(CallInEditor, Category = Actions)
	virtual void GetDamage(float Damage);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


	UFUNCTION(CallInEditor, Category = Actions)
	virtual void Die();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
