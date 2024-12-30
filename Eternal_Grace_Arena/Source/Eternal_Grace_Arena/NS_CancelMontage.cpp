// Fill out your copyright notice in the Description page of Project Settings.


#include "NS_CancelMontage.h"
#include "CharacterAnimInstance.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "Eternal_Grace_ArenaEnemy.h"

UNS_CancelMontage::UNS_CancelMontage()
{
	PerformingActor = nullptr;
	BlendOutTime = 0.25f;
}
void UNS_CancelMontage::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	//THIS SHOULDNT BE DONE ON EVERY NOTIFY BEGIN, BUT ON INITIALIZATION
	if (PerformingActor == nullptr)
	{
		PerformingActor = Cast<AEternal_Grace_ArenaEnemy>(MeshComp->GetOwner());
		if (PerformingActor == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("Could not Cast Actor to Player Character"))
				return;
		}
	}
	bool continueAttack = PerformingActor->CheckDistancetoPlayer(PerformingActor->AttackRange);

	if(!continueAttack)
	{
	PerformingActor->CharacterAnimationInstance->StopAllMontages(BlendOutTime);
	PerformingActor->CharacterAnimationInstance->isAttacking = false;

	}

}
