// Fill out your copyright notice in the Description page of Project Settings.


#include "NS_DrainStamina.h"
#include "PlayerCharacter.h"
#include "StaminaComponent.h"
#include "WeaponComponent.h"
#include "Weapon.h"

UNS_DrainStamina::UNS_DrainStamina()
{
	PerformingActor = nullptr;
	OwningActor = nullptr;
	ConsumptionMultiplier = 1.0f;
}
void UNS_DrainStamina::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{

	//THIS SHOULDNT BE DONE ON EVERY NOTIFY BEGIN, BUT ON INITIALIZATION
	if (PerformingActor == nullptr)
	{
		PerformingActor = Cast<APlayerCharacter>(MeshComp->GetOwner());
		if (PerformingActor == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("Could not Cast Actor to Player Character"))
				return;
		}
	}

	PerformingActor->StaminaComponent->CurrentStamina -= (PerformingActor->WeaponComponent->GetCurrentWeapon()->GetWeaponStats().StaminaCost * ConsumptionMultiplier);
};
