// Fill out your copyright notice in the Description page of Project Settings.


#include "NS_DrainStamina.h"
#include "PlayerCharacter.h"
#include "CharacterWeapon.h"
#include "StaminaComponent.h"

UNS_DrainStamina::UNS_DrainStamina()
{
	PerformingActor = nullptr;
	OwningActor = nullptr;
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

	PerformingActor->StaminaComponent->CurrentStamina -= PerformingActor->Weapon->Values.StaminaCost;
};
