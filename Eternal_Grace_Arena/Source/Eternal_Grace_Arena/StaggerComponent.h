// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StaggeringType.h"
#include "StaggerComponent.generated.h"

class AEternal_Grace_ArenaCharacter;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ETERNAL_GRACE_ARENA_API UStaggerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UStaggerComponent();

	UFUNCTION()
	void GetStaggered(EStaggeringType StaggerType, float PoiseDamage, float AttackAngle, AActor* Instigator);
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	TMap<EStaggeringType, UAnimMontage*> FrontalStaggerAnimationMap;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	TMap<EStaggeringType, UAnimMontage*> BackStaggerAnimationMap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BaseValues, meta = (AllowPrivateAccess))
	float MaxPoise;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BaseValues, meta = (AllowPrivateAccess))
	float CurrentPoise;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BaseValues, meta = (AllowPrivateAccess))
	float PoiseRegenerationRate;

	UPROPERTY()
	bool isStaggered;

	UFUNCTION()
	void EndStaggerCondition(UAnimMontage* AttackAnimation, bool Interrupted);

	UFUNCTION()
	void PlayStaggerAnimation(UAnimMontage* StaggerMontage);

	UPROPERTY()
	AEternal_Grace_ArenaCharacter* Owner;


	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	bool GetIsStaggered();

		
};
