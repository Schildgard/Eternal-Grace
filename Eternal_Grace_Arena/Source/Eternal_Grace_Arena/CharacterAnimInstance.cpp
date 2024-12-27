// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAnimInstance.h"
#include "Eternal_Grace_ArenaEnemy.h"

void UCharacterAnimInstance::InterruptAttack(UAnimMontage* AttackAnimation, bool Interrupted)
{
	if (Interrupted)
	{
		isAttacking = false;
		UE_LOG(LogTemp, Error, TEXT("Animation was interrupted"))
	}
}

void UCharacterAnimInstance::OnAttackEnd(UAnimMontage* AttackAnimation, bool Interrupted)
{
	isAttacking = false;
	UE_LOG(LogTemp, Warning, TEXT("is Attacking : %s"),isAttacking ? TEXT("true") : TEXT("false"));
//	AEternal_Grace_ArenaEnemy* Owner = Cast<AEternal_Grace_ArenaEnemy>(GetOwningActor());
//	//check attack count
//	if (Owner && attackCount <= 2)
//	{
//		UE_LOG(LogTemp, Warning, TEXT("Continue Attack"))
//		//check distance to player
//		bool PlayerInReach = Owner->CheckDistancetoPlayer();
//		if (PlayerInReach)
//		{
//			UE_LOG(LogTemp, Warning, TEXT("Perform Continous Attack"))
//			Owner->LightAttack();
//		}
//	}
	UE_LOG(LogTemp, Warning, TEXT("Animation was completed"))
}
