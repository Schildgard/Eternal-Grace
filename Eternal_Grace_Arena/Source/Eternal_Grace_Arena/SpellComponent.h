// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Spell.h"
#include "SpellComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ETERNAL_GRACE_ARENA_API USpellComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	USpellComponent();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta =(AllowPrivateAccess))
	TArray<TSubclassOf<ASpell>> SpellList;

protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	FVector TargetPosition;

	UPROPERTY()
	AEternal_Grace_ArenaCharacter* TargetCharacter;




public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION()
	virtual void CastSpell(ASpell* SpellToCast);
	UFUNCTION()
	void SetTargetPosition(FVector NewPosition);
	UFUNCTION()
	FVector GetTargetPosition();
	UFUNCTION()
	AEternal_Grace_ArenaCharacter* GetTarget();
	
};
