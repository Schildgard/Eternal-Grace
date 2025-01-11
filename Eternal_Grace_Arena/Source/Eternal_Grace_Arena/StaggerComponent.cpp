// Fill out your copyright notice in the Description page of Project Settings.


#include "StaggerComponent.h"
#include "Eternal_Grace_ArenaCharacter.h"

// Sets default values for this component's properties
UStaggerComponent::UStaggerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	Owner = nullptr;

	// ...
}


void UStaggerComponent::GetStaggered(EStaggeringType StaggerType, float AttackAngle, AActor* Instigator)
{
	//ATTACK FROM BEHIND
	if (AttackAngle >= 135.0f && AttackAngle <= 180.0f)
	{
		if (BackStaggerAnimationMap.Contains(StaggerType))
		{
			Owner->PlayAnimMontage(BackStaggerAnimationMap[StaggerType]);
			return;
		}
	}
	// FRONTAL ATTACK
	if (FrontalStaggerAnimationMap.Contains(StaggerType))
	{
		if (StaggerType != EStaggeringType::NoStagger)
		{
			Owner->RotateTowardsTarget(Instigator);
		}
		Owner->PlayAnimMontage(FrontalStaggerAnimationMap[StaggerType]);
		return;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s Stagger Animation Map contains no Key for this StaggerType"), *Owner->GetName())
	}

}

// Called when the game starts
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
		UE_LOG(LogTemp, Warning, TEXT("Could not Get Owning of StaggerComponent"))
	}

	// ...

}


// Called every frame
void UStaggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

