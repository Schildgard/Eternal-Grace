// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_WeaponMaster.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "CharacterAnimInstance.h"
#include "Components/CapsuleComponent.h"
#include "HealthComponent.h"
#include "WeaponComponent.h"

AEnemy_WeaponMaster::AEnemy_WeaponMaster()
{
	GetOffMeAttack = nullptr;
}



void AEnemy_WeaponMaster::LightAttack()
{
	Attack();
}

void AEnemy_WeaponMaster::Attack()
{
	if (CheckIfPlayerIsBehind() && SecondPhaseTriggered)
	{
		GetOffMeMove();
		return;
	}


	if (!CharacterAnimationInstance->isAttacking)
	{
		CharacterAnimationInstance->isAttacking = true;
		RotateTowardsTarget(UGameplayStatics::GetPlayerCharacter(world, 0));

		int RandomAttackIndex = UKismetMathLibrary::RandomInteger(2); //CHANGE THIS TO LENGTH OF VIABLE ATTACK ARRAY

		PlayAnimMontage(WeaponComponent->GetCurrentLightAttacks()[RandomAttackIndex], 1.0f);

		FOnMontageEnded InterruptDelegate;
		FOnMontageEnded CompletedDelegate;

		InterruptDelegate.BindUObject(CharacterAnimationInstance, &UCharacterAnimInstance::InterruptAttack);
		CompletedDelegate.BindUObject(CharacterAnimationInstance, &UCharacterAnimInstance::OnAttackEnd);

		CharacterAnimationInstance->Montage_SetBlendingOutDelegate(InterruptDelegate, WeaponComponent->GetCurrentLightAttacks()[RandomAttackIndex]);
		CharacterAnimationInstance->Montage_SetEndDelegate(CompletedDelegate, WeaponComponent->GetCurrentLightAttacks()[RandomAttackIndex]);

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

		if (GetOffMeAttack != nullptr)
		{
			PlayAnimMontage(GetOffMeAttack, 1.0f);

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
