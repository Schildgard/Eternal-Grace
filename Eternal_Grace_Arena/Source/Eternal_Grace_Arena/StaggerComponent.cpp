// Fill out your copyright notice in the Description page of Project Settings.


#include "StaggerComponent.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "CharacterAnimInstance.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UStaggerComponent::UStaggerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	Owner = nullptr;
	isStaggered = false;

	MaxPoise = 25.0f;
	CurrentPoise = MaxPoise;
	PoiseRegenerationRate = 0.0f;
}


void UStaggerComponent::GetStaggered(EStaggeringType StaggerType, float PoiseDamage, float AttackAngle, AActor* Instigator)
{
		CurrentPoise -= PoiseDamage;
		if (CurrentPoise <= 0.0f)
		{
			//If Character is Attacking, interrupt his Attack Status.
			Owner->QuitAttack();
			isStaggered = true;
			//Owner->CharacterAnimationInstance->StopAllMontages(0.0f);
			//IF ATTACK COMES FROM BEHIND -> TRIGGER BACKSTAGGER
			if (AttackAngle >= 135.0f && AttackAngle <= 180.0f)
			{
				if (BackStaggerAnimationMap.Contains(StaggerType))
				{
					PlayStaggerAnimation(FrontalStaggerAnimationMap[StaggerType]);
				}
			}
			// IF ATTACK COMES FROM FRONT -> TRIGGER FRONTSTAGGER
			else if (FrontalStaggerAnimationMap.Contains(StaggerType))
			{
				if (StaggerType != EStaggeringType::NoStagger)
				{
					Owner->RotateTowardsTarget(Instigator);
				}
				PlayStaggerAnimation(FrontalStaggerAnimationMap[StaggerType]);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("%s Stagger Animation Map contains no Key for this StaggerType"), *Owner->GetName())
			}
			CurrentPoise = MaxPoise;
		}
}

void UStaggerComponent::EndStaggerCondition(UAnimMontage* AttackAnimation, bool Interrupted)
{
	isStaggered = false;
	Owner->QuitAttack();

	// Sperre Attacken für 0.2 Sekunden nach Stagger
	Owner->canAttack = false;
	FTimerHandle AttackCooldownHandle;



	Owner->GetWorldTimerManager().SetTimer(AttackCooldownHandle, [this]()
		{
			Owner->canAttack = true;
		}, 0.2f, false);


}

void UStaggerComponent::PlayStaggerAnimation(UAnimMontage* StaggerMontage)
{
	//PLAY ANIMATION
	Owner->PlayAnimMontage(StaggerMontage);

	FOnMontageEnded EndDelegate;
	//BlendoutDelegate.BindUObject(this, &UStaggerComponent::EndStaggerCondition);
	EndDelegate.BindUObject(this, &UStaggerComponent::EndStaggerCondition);
	//Owner->CharacterAnimationInstance->Montage_SetBlendingOutDelegate(BlendoutDelegate, StaggerMontage);
	Owner->CharacterAnimationInstance->Montage_SetEndDelegate(EndDelegate, StaggerMontage);
}

void UStaggerComponent::BeginPlay()
{
	Super::BeginPlay();

	AActor* OwningActor = GetOwner();
	if (OwningActor)
	{
		Owner = Cast<AEternal_Grace_ArenaCharacter>(OwningActor);
		if (!Owner)
		{
			UE_LOG(LogTemp, Warning, TEXT("Could not Cast %s into Eternal Grace Character"), *OwningActor->GetName())
				return;
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Could not Get Owning of StaggerComponent"))
	}

}


void UStaggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (CurrentPoise <= MaxPoise)
	{
		CurrentPoise += DeltaTime * PoiseRegenerationRate;
	}
}

bool UStaggerComponent::GetIsStaggered()
{
	return isStaggered;
}

