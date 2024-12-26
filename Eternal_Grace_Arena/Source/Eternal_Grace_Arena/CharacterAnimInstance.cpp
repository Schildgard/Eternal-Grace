// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAnimInstance.h"

void UCharacterAnimInstance::InterruptAttack(UAnimMontage* AttackAnimation, bool Interrupted)
{
	if(Interrupted)
	{
		isAttacking = false;
		UE_LOG(LogTemp,Error,TEXT("Animation was interrupted"))
	}
}

void UCharacterAnimInstance::OnAttackEnd(UAnimMontage* AttackAnimation, bool Interrupted)
{
	isAttacking = false;
	UE_LOG(LogTemp, Warning, TEXT("Animation was completed"))
}
