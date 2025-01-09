// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_WeaponMaster.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "CharacterAnimInstance.h"
#include "Components/CapsuleComponent.h"

AEnemy_WeaponMaster::AEnemy_WeaponMaster()
{
	GetOffMeAttack = nullptr;
}

void AEnemy_WeaponMaster::LightAttack()
{
	//Super::LightAttack();

	if (CheckIfPlayerIsBehind() && SecondPhaseTriggered)
	{
		GetOffMeMove();
		return;
	}



	if (!CharacterAnimationInstance->isAttacking)
	{
		CharacterAnimationInstance->isAttacking = true;
		RotateTowardsTarget(UGameplayStatics::GetPlayerCharacter(world, 0));
		if (CharacterAnimationInstance->isGuarding)
		{
			CancelGuard();
		}
		int RandomAttackIndex = UKismetMathLibrary::RandomInteger(2);

		PlayAnimMontage(LightAttacks[RandomAttackIndex], 1.0f);

		FOnMontageEnded InterruptDelegate;
		FOnMontageEnded CompletedDelegate;

		InterruptDelegate.BindUObject(CharacterAnimationInstance, &UCharacterAnimInstance::InterruptAttack);
		CompletedDelegate.BindUObject(CharacterAnimationInstance, &UCharacterAnimInstance::OnAttackEnd);

		CharacterAnimationInstance->Montage_SetBlendingOutDelegate(InterruptDelegate, LightAttacks[RandomAttackIndex]);
		CharacterAnimationInstance->Montage_SetEndDelegate(CompletedDelegate, LightAttacks[RandomAttackIndex]);


	}
}

void AEnemy_WeaponMaster::GetOffMeMove()
{
	if (!CharacterAnimationInstance->isAttacking)
	{
		CharacterAnimationInstance->isAttacking = true;

		//TEMPORARY
		UCapsuleComponent* ActorCollisionCapsule = GetCapsuleComponent();
		ActorCollisionCapsule->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);


		RotateTowardsTarget(UGameplayStatics::GetPlayerCharacter(world, 0));
		if (CharacterAnimationInstance->isGuarding)
		{
			CancelGuard();
		}
		if (GetOffMeAttack != nullptr)
		{
			PlayAnimMontage(GetOffMeAttack, 1.0f); // TO DO:REPLACE THAT MAGIC NUMBER WITH SOMETHING ELSE LIKE A POINTER TO A SPECIFIC MONTAGE OR SOMETHING

			FOnMontageEnded InterruptDelegate;
			FOnMontageEnded CompleteDelegate;

			InterruptDelegate.BindUObject(CharacterAnimationInstance, &UCharacterAnimInstance::InterruptAttack);
			InterruptDelegate.BindUObject(this, &AEternal_Grace_ArenaEnemy::ResetCollision);

			CompleteDelegate.BindUObject(this, &AEternal_Grace_ArenaEnemy::ResetCollision);
			CompleteDelegate.BindUObject(CharacterAnimationInstance, &UCharacterAnimInstance::OnAttackEnd);

			CharacterAnimationInstance->Montage_SetBlendingOutDelegate(InterruptDelegate, GetOffMeAttack);
			CharacterAnimationInstance->Montage_SetEndDelegate(CompleteDelegate, GetOffMeAttack);
		}
	}
}
