// Fill out your copyright notice in the Description page of Project Settings.


#include "NS_Liftup.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "CharacterAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"

void UNS_Liftup::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	if (PerformingActor == nullptr)
	{
		PerformingActor = Cast<AEternal_Grace_ArenaCharacter>(MeshComp->GetOwner());
	}
	if (PerformingActor)
	{
		FVector LaunchVelocity = FVector(0.f, 0.f, 1000.f);
		PerformingActor->GetCharacterMovement()->AddImpulse(LaunchVelocity, true);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No Actor Found"))

	}
}
