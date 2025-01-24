// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_MushroomKing.h"
#include "CharacterAnimInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet//KismetMathLibrary.h"

void AEnemy_MushroomKing::GetOffMeMove()
{
	//JUMP END ANIMATION HAS AN NOTIFY WICH TRIGGERS AN AOE WAVE 
	//if (GetOffMeAttack != nullptr)
	//{
		//PlayAnimMontage(GetOffMeAttack, 1.0f); // TO DO:REPLACE THAT MAGIC NUMBER WITH SOMETHING ELSE LIKE A POINTER TO A SPECIFIC MONTAGE OR SOMETHING
	//	Jump();

	PlayAnimMontage(GetOffMeAttack, 1.0f);

	//	FOnMontageEnded InterruptDelegate;
	FOnMontageEnded CompleteDelegate;

	//	InterruptDelegate.BindUObject(CharacterAnimationInstance, &UCharacterAnimInstance::InterruptAttack);
	//	InterruptDelegate.BindUObject(this, &AEternal_Grace_ArenaEnemy::ResetCollision);

	//	CompleteDelegate.BindUObject(this, &AEternal_Grace_ArenaEnemy::ResetCollision);
	CompleteDelegate.BindUObject(CharacterAnimationInstance, &UCharacterAnimInstance::OnAttackEnd);

	//CharacterAnimationInstance->Montage_SetBlendingOutDelegate(InterruptDelegate, GetOffMeAttack);
	CharacterAnimationInstance->Montage_SetEndDelegate(CompleteDelegate, GetOffMeAttack);
}
//Jump();


void AEnemy_MushroomKing::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);


}

void AEnemy_MushroomKing::LightAttack()
{
	if (!CharacterAnimationInstance->isAttacking)
	{
		CharacterAnimationInstance->isAttacking = true;
		if (CheckDistancetoPlayer(300.f))
		{
			GetOffMeMove();
		}
		else
		{
			RotateTowardsTarget(UGameplayStatics::GetPlayerCharacter(world, 0));

				int RandomAttackIndex = UKismetMathLibrary::RandomInteger(2); //CHANGE THIS TO LENGTH OF VIABLE ATTACK ARRAY

				PlayAnimMontage(LightAttacks[RandomAttackIndex], 1.0f);

				FOnMontageEnded InterruptDelegate;
				FOnMontageEnded CompletedDelegate;

				InterruptDelegate.BindUObject(CharacterAnimationInstance, &UCharacterAnimInstance::InterruptAttack);
				CompletedDelegate.BindUObject(CharacterAnimationInstance, &UCharacterAnimInstance::OnAttackEnd);

				CharacterAnimationInstance->Montage_SetBlendingOutDelegate(InterruptDelegate, LightAttacks[RandomAttackIndex]);
				CharacterAnimationInstance->Montage_SetEndDelegate(CompletedDelegate, LightAttacks[RandomAttackIndex]);
		}
	}
}
