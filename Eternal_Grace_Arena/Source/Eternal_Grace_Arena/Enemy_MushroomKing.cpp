// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_MushroomKing.h"
#include "CharacterAnimInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet//KismetMathLibrary.h"
#include "WeaponComponent.h"

void AEnemy_MushroomKing::GetOffMeMove()
{
	//JUMP END ANIMATION HAS AN NOTIFY WICH TRIGGERS AN AOE WAVE 

	PlayAnimMontage(GetOffMeAttack, 1.0f);

//	FOnMontageEnded CompleteDelegate;
//	CompleteDelegate.BindUObject(CharacterAnimationInstance, &UCharacterAnimInstance::OnAttackEnd);
//	CharacterAnimationInstance->Montage_SetEndDelegate(CompleteDelegate, GetOffMeAttack);
}

void AEnemy_MushroomKing::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AEnemy_MushroomKing::LightAttack()
{
	TArray<UAnimMontage*> Attacks = WeaponComponent->GetCurrentLightAttacks();
	if (!CharacterAnimationInstance->isAttacking)
	{
		int AttackIndex = 0;
		CharacterAnimationInstance->isAttacking = true;
		//If PLAYER is very Close
		if (CheckDistancetoPlayer(300.f))
		{
			GetOffMeMove();
			return;
		}
		else if (CheckDistancetoPlayer(400.f))
		{
			RotateTowardsTarget(UGameplayStatics::GetPlayerCharacter(world, 0));
			AttackIndex = 0;
		}
		else
		{
			RotateTowardsTarget(UGameplayStatics::GetPlayerCharacter(world, 0));
			AttackIndex = 1;
		}

		PlayAnimMontage(Attacks[AttackIndex], 1.0f);

		FOnMontageEnded InterruptDelegate;
		FOnMontageEnded CompletedDelegate;

		InterruptDelegate.BindUObject(CharacterAnimationInstance, &UCharacterAnimInstance::InterruptAttack);
		CompletedDelegate.BindUObject(CharacterAnimationInstance, &UCharacterAnimInstance::OnAttackEnd);

		CharacterAnimationInstance->Montage_SetBlendingOutDelegate(InterruptDelegate, Attacks[AttackIndex]);
		CharacterAnimationInstance->Montage_SetEndDelegate(CompletedDelegate, Attacks[AttackIndex]);
	}

	
}
