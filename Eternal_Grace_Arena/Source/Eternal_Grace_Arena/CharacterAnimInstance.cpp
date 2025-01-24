// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAnimInstance.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "Eternal_Grace_ArenaEnemy.h"

void UCharacterAnimInstance::InterruptAttack(UAnimMontage* AttackAnimation, bool Interrupted)
{
	if (Interrupted)
	{
		if (isAttacking)
		{
			UE_LOG(LogTemp, Error, TEXT("Attack Interrupted"))
			isAttacking = false;
		}
	}
		// RESET BOOL ON BLEND OUT LEADS TO WEIRD RETRIGGERING OF ATTACKS SOMETIMES
}

void UCharacterAnimInstance::OnAttackEnd(UAnimMontage* AttackAnimation, bool Interrupted)
{
	if (isAttacking)
	{
		UE_LOG(LogTemp, Error, TEXT("Attack Ended"))
		isAttacking = false;
	}
}
