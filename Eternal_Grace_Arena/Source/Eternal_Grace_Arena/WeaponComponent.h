// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "WeaponComponent.generated.h"

class AWeapon;
class AEternal_Grace_ArenaCharacter;
class UNiagaraSystem;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ETERNAL_GRACE_ARENA_API UWeaponComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY()
	AActor* WeaponOwner;

	UPROPERTY()
	AEternal_Grace_ArenaCharacter* OwningCharacter;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta =(AllowPrivateAccess))
	TSubclassOf<AWeapon> EquippedWeaponClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	AWeapon* EquippedWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HitEffect, meta = (AllowPrivateAccess))
	UDataTable* HitEffectDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Trail, meta = (AllowPrivateAccess))
	UNiagaraSystem* WeaponTrail;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Trail, meta = (AllowPrivateAccess))
	UNiagaraSystem* WeaponSparks;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HitTrace, meta = (AllowPrivateAccess))
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;



	UPROPERTY()
	TArray<UAnimMontage*> CurrentLightAttacks;

	UPROPERTY()
	TArray<UAnimMontage*> CurrentHeavyAttacks;

public:	

	UFUNCTION()
	void Attack();

	UFUNCTION()
	void HeavyAttack();


	UFUNCTION()
	float CalculateAttackAngle(AActor* Target);


	UFUNCTION()
	TArray<TEnumAsByte<EObjectTypeQuery>> GetObjectTypes();

	UFUNCTION()
	AWeapon* GetCurrentWeapon();

	UFUNCTION()
	UNiagaraSystem* GetWeaponTrail();
	UFUNCTION()
	UNiagaraSystem* GetWeaponSparks();
	UFUNCTION()
	UDataTable* GetHitEffectDataTable();


	UFUNCTION()
	TArray<UAnimMontage*> GetCurrentLightAttacks();
		
};
