// Fill out your copyright notice in the Description page of Project Settings.


#include "NS_RotateTowardsTarget.h"
#include "Eternal_Grace_ArenaEnemy.h"
#include "Kismet/GameplayStatics.h"
UNS_RotateTowardsTarget::UNS_RotateTowardsTarget()
{
	PerformingActor = nullptr;
}


void UNS_RotateTowardsTarget::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	//ACTUALLY THIS IS NOT USED SO FAR AND PROBABLY CAN BE DELETED
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
	PerformingActor->RotateTowardsTarget(UGameplayStatics::GetPlayerCharacter(PerformingActor->world, 0));

}
