// Fill out your copyright notice in the Description page of Project Settings.


#include "NS_CastSpell.h"
#include "Spell.h"
#include "Kismet/GameplayStatics.h"

void UNS_CastSpell::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{

	if (OwningActor == nullptr)
	{
		OwningActor = Cast<APawn>(MeshComp->GetOwner());
		if (OwningActor == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("Could not Cast Actor to Player Character"))
				return;
		}
	}
	if (SpellToCast)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = OwningActor;
		SpawnParams.Instigator = OwningActor;
		ASpell* SpellCast = OwningActor->GetWorld()->SpawnActor<ASpell>(SpellToCast, OwningActor->GetActorLocation(), OwningActor->GetActorRotation(), SpawnParams);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Spell in notify is null"))
	}
}