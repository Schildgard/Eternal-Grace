// Fill out your copyright notice in the Description page of Project Settings.


#include "NS_WeaponSwing_CollisionToggle.h"
#include "Components/CapsuleComponent.h"
#include "Eternal_Grace_ArenaCharacter.h"

void UNS_WeaponSwing_CollisionToggle::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	//THIS NOTIFY TEMPORARILY DISABLES ENEMY COLLISION WITH PAWNS, SO HIS ATTACK LETS HIM MOVE THROUGH HIS OPPONENT
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);
	if (PerformingActor)
	{
		UCapsuleComponent* ActorCollisionCapsule = PerformingActor->GetCapsuleComponent();
		ActorCollisionCapsule->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);

	}
}

void UNS_WeaponSwing_CollisionToggle::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);
	if (PerformingActor)
	{
		UCapsuleComponent* ActorCollisionCapsule = PerformingActor->GetCapsuleComponent();
		ActorCollisionCapsule->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);

	}
}
