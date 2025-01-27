// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponComponent.h"
#include "Weapon.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "Kismet//KismetMathLibrary.h"
#include "Kismet//GameplayStatics.h"
#include "HitEffectData.h"
#include "NiagaraFunctionLibrary.h"
#include "Engine/StaticMeshActor.h"
#include "ShieldComponent.h"
#include "Shield.h"
#include "CharacterAnimInstance.h"

// Sets default values for this component's properties
UWeaponComponent::UWeaponComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	WeaponOwner = nullptr;
	EquippedWeapon = nullptr;
	HitEffectDataTable = nullptr;

	CurrentStaggerType = EStaggeringType::NormalStagger;

	// ...
}


// Called when the game starts
void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	WeaponOwner = GetOwner();
	if (!WeaponOwner)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to get WeaponOwner for %s"), *GetName())
			return;
	}

	if (!EquippedWeaponClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to get Equipped Weapon Class for %s"), *GetName())
			return;
	}

	EquippedWeapon = GetWorld()->SpawnActor<AWeapon>(EquippedWeaponClass);
	if (!EquippedWeapon)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to Spawn Equipped Weapon Object for %s"), *GetName())
			return;
	}
	EquippedWeapon->AttachToComponent(this, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	EquippedWeapon->GetMesh()->OnComponentBeginOverlap.AddDynamic(this, &UWeaponComponent::DealDamage);

}


void UWeaponComponent::DealDamage(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{


	if (OtherActor != WeaponOwner && OtherActor->Implements<UI_Damageable>())
	{
		if (!HittedActors.Contains(OtherActor))
		{
			UPhysicalMaterial* HitEffectToApply;

			//CALCULATE DAMAGE PROPERTIES
			float Damage = EquippedWeapon->GetWeaponStats().BaseDamage * EquippedWeapon->DamageMultiplier;
			float PoiseDamage = EquippedWeapon->GetWeaponStats().PoiseDamage * EquippedWeapon->DamageMultiplier;;
			float DamageDirection = CalculateAttackAngle(OtherActor);
			bool AttackWasBlocked = false;


			//CHECK IF HITTED WAS A CHARACTER
			AEternal_Grace_ArenaCharacter* TargetActor = Cast<AEternal_Grace_ArenaCharacter>(OtherActor);
			if (TargetActor)
			{
				HitEffectToApply = TargetActor->PhysicalMaterial;
				HittedActors.AddUnique(TargetActor); //MAYBE IT MAKES SENSE TO CHANGE THIS TO TARGETACTOR->GET OWNER
				//CHECK IF ATTACK WAS FRONTAL AND BLOCKED BY A SHIELD
				//IF SO, THE GET DAMAGE PARAMETER CHANGES SO IT RECOGNIZES THE BLOCK AND THE WEAPON APPLIES HIT EFFECT OF THE SHIELD INSTEAD OF THE TARGET
				if (TargetActor->ShieldComponent && TargetActor->ShieldComponent->GetCurrentShield())
				{
					if (TargetActor->CharacterAnimationInstance->isGuarding)
					{
						if (DamageDirection <= 135.0f || DamageDirection >= 180.0f)
						{
							AttackWasBlocked = true;
							HitEffectToApply = TargetActor->ShieldComponent->GetCurrentShield()->GetShieldStats().PhysicalMaterial;
						}
					}
				}
				ApplyHitEffect(HitEffectToApply);
			}

			II_Damageable::Execute_GetDamage(OtherActor, Damage, PoiseDamage, DamageDirection, CurrentStaggerType, Cast<AEternal_Grace_ArenaCharacter>(WeaponOwner), AttackWasBlocked);
			return;
		}
	}




	//AStaticMeshActor* HitActor = Cast<AStaticMeshActor>(OtherActor);
	//if (HitActor)
	//{
	//	UStaticMeshComponent* MeshComponent = HitActor->GetStaticMeshComponent();
	//	if (MeshComponent)
	//	{
	//		UMaterialInterface* Material = MeshComponent->GetMaterial(0);
	//		if (Material)
	//		{
	//			UPhysicalMaterial* PhysMaterial = Material->GetPhysicalMaterial();
	//			UE_LOG(LogTemp, Warning, TEXT("Got Phys Material %s"), *PhysMaterial->GetName());
	//			ApplyHitEffect(PhysMaterial);
	//		}
	//
	//	}
	//}

}

float UWeaponComponent::CalculateAttackAngle(AActor* Target)
{
	FVector OwnerPosition = WeaponOwner->GetActorLocation();
	FVector TargetPosition = Target->GetActorLocation();
	FVector Direction = OwnerPosition - TargetPosition;
	Direction.Normalize(0.0001f);
	FVector ForwardDirectionOfTarget = Target->GetActorForwardVector();
	float DotProduct = UKismetMathLibrary::Dot_VectorVector(Direction, ForwardDirectionOfTarget);
	float Degrees = UKismetMathLibrary::DegAcos(DotProduct);
	return Degrees;
}

void UWeaponComponent::ApplyHitEffect(UPhysicalMaterial* PhysicalMaterial)
{
	if (!PhysicalMaterial || !HitEffectDataTable)
	{
		UE_LOG(LogTemp, Warning, TEXT("No PhysicalMaterial or DataTable assigned!"));
		return;
	}

	//CREATE A CONTEXT STRING
	static const FString ContextString(TEXT("Hit Effect Context"));
	FName MaterialName = FName(*PhysicalMaterial->GetName());
	//GONNA CHECK WHAT CONTEXT STRING PARAMETER DOES
	FHitEffectData* EffectData = HitEffectDataTable->FindRow<FHitEffectData>(MaterialName, ContextString);

	if (EffectData)
	{
		if (EffectData->HitSound)
		{
			UGameplayStatics::PlaySoundAtLocation(this, EffectData->HitSound, GetOwner()->GetActorLocation());
		}
		if (EffectData->NiagaraEffect)
		{
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, EffectData->NiagaraEffect, GetOwner()->GetActorLocation());
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No effects found for PhysicalMaterial: %s"), *MaterialName.ToString());
	}
}

// Called every frame
void UWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UWeaponComponent::SetStaggerType(EStaggeringType StaggerType)
{
	CurrentStaggerType = StaggerType;
}

AWeapon* UWeaponComponent::GetCurrentWeapon()
{
	return EquippedWeapon;
}

void UWeaponComponent::ResetAttackValues()
{
	EquippedWeapon->DamageMultiplier = 1.0f;
	HittedActors.Empty();
}

UPhysicalMaterial* UWeaponComponent::GetPhysicalMaterial(UPrimitiveComponent* OverlappedComponent)
{
	//CURRENTLY NOT IN USE AT ALL DUE TO COMPLICATIONS. PROBABLY CHANGE THE PARAMETER TO ANOTHER TYPE TO MAKE IT WORK
	UE_LOG(LogTemp, Error, TEXT("Overllaped Component is %s"), *OverlappedComponent->GetName())
		UMaterialInterface* TargetMaterial = OverlappedComponent->GetMaterial(0);
	if (TargetMaterial)
	{
		UPhysicalMaterial* TargetsPhyiscalMaterial = TargetMaterial->GetPhysicalMaterial();
		if (TargetsPhyiscalMaterial)
		{
			return TargetsPhyiscalMaterial;
		}
	}
	return nullptr;
}

