// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "StaggeringType.h"
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


	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta =(AllowPrivateAccess))
	TSubclassOf<AWeapon> EquippedWeaponClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	AWeapon* EquippedWeapon;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Collision)
	TArray<AEternal_Grace_ArenaCharacter*> HittedActors;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HitEffect, meta = (AllowPrivateAccess))
	UDataTable* HitEffectDataTable;
	UPROPERTY()
	EStaggeringType CurrentStaggerType;


	UFUNCTION()
	void DealDamage(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
	void ApplyHitEffect(UPhysicalMaterial* PhysicalMaterial);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Trail, meta = (AllowPrivateAccess))
	UNiagaraSystem* WeaponTrail;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Trail, meta = (AllowPrivateAccess))
	UNiagaraSystem* WeaponSparks;



public:	
	UFUNCTION()
	float CalculateAttackAngle(AActor* Target);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HitTrace, meta = (AllowPrivateAccess))
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SetStaggerType(EStaggeringType StaggerType);

	UFUNCTION()
	AWeapon* GetCurrentWeapon();

	UFUNCTION()
	void ResetAttackValues();

	//UFUNCTION()
	//UPhysicalMaterial* GetPhysicalMaterial(UPrimitiveComponent* OverlappedComponent);

	UFUNCTION()
	UNiagaraSystem* GetWeaponTrail();
	UFUNCTION()
	UNiagaraSystem* GetWeaponSparks();
	UFUNCTION()
	UDataTable* GetHitEffectDataTable();
		
};
