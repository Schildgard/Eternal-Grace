// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAnimInstance.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "Eternal_Grace_ArenaEnemy.h"
#include "CharacterWeapon.h"

void UCharacterAnimInstance::InterruptAttack(UAnimMontage* AttackAnimation, bool Interrupted)
{
	if (Interrupted)
	{
		isAttacking = false;
		UE_LOG(LogTemp, Error, TEXT("Animation was interrupted"))
			AEternal_Grace_ArenaCharacter* ThisCharacter = Cast<AEternal_Grace_ArenaCharacter>(GetOwningActor());
		if (ThisCharacter)
		{
			//THIS DOES NOT SEEM TO MAKE A DIFFERENCE
			ThisCharacter->Weapon->ResetAttackValues();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Cast Not successfull"))
		}
	}
}

void UCharacterAnimInstance::OnAttackEnd(UAnimMontage* AttackAnimation, bool Interrupted)
{
	isAttacking = false;
	AEternal_Grace_ArenaCharacter* ThisCharacter = Cast<AEternal_Grace_ArenaCharacter>(GetOwningActor());
	if (ThisCharacter)
	{
		ThisCharacter->Weapon->ResetAttackValues();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Cast Not successfull"))
	}
}
