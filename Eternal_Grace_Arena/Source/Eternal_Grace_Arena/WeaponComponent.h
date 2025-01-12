// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "StaggeringType.h"
#include "WeaponComponent.generated.h"

class AWeapon;
class AEternal_Grace_ArenaCharacter;
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
	float CalculateAttackAngle(AActor* Target);
	UFUNCTION()
	void ApplyHitEffect(UPhysicalMaterial* PhysicalMaterial);



public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SetStaggerType(EStaggeringType StaggerType);

	UFUNCTION()
	AWeapon* GetCurrentWeapon();

	UFUNCTION()
	void ResetAttackValues();

	

		
};
