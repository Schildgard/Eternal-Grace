// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "StaggeringType.h"
#include "CharacterWeapon.generated.h"

class AEternal_Grace_ArenaCharacter;
USTRUCT(BlueprintType)
struct FCustomValues
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float BaseDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float StaminaCost;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float PoiseDamage;
};

UCLASS()
class ETERNAL_GRACE_ARENA_API UCharacterWeapon : public UStaticMeshComponent
{
	GENERATED_BODY()
	UCharacterWeapon();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess))
	FCustomValues Values;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess))
	AActor* WeaponOwner;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Collision)
	TArray<AEternal_Grace_ArenaCharacter*> HittedActors;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HitEffect, meta = (AllowPrivateAccess))
	UDataTable* HitEffectDataTable;


	UFUNCTION()
	void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult

	);

	//DEAL DAMAGE FUNCTIONS NEEDS TO GET A DAMAGE MULTIPLIER AND STAGGER TYPE FROM THE ATTACKANIMATION NOTIFY THAT ENABLES THE COLLISION HIT BOX
	UFUNCTION()
	void DealDamage(AEternal_Grace_ArenaCharacter* Target, float DamageMultiplier, EStaggeringType Staggertype);
	UFUNCTION()
	void HitDetect(float DamageMultiplier, EStaggeringType Staggertype);

	UFUNCTION()
	void ApplyHitEffect(UPhysicalMaterial* PhysicalMaterial);
	
};
