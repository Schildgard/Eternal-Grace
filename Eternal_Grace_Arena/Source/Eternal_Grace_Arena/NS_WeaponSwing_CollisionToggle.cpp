// Fill out your copyright notice in the Description page of Project Settings.


#include "NS_WeaponSwing_CollisionToggle.h"
#include "Components/CapsuleComponent.h"
#include "Eternal_Grace_ArenaCharacter.h"

void UNS_WeaponSwing_CollisionToggle::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);
	UCapsuleComponent* ActorCollisionCapsule = PerformingActor->GetCapsuleComponent();
	ActorCollisionCapsule->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
}

void UNS_WeaponSwing_CollisionToggle::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);
	UCapsuleComponent* ActorCollisionCapsule = PerformingActor->GetCapsuleComponent();
	ActorCollisionCapsule->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);
}
