// Fill out your copyright notice in the Description page of Project Settings.


#include "NotifyState_WeaponSwing.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "PlayerCharacter.h"

void UNotifyState_WeaponSwing::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{

	AActor* Owner = MeshComp->GetOwner();
	if(APlayerCharacter* PerformingCharacter = Cast<APlayerCharacter>(Owner))
	{
		UE_LOG(LogTemp, Warning, TEXT("Owner Found"))
//			UStaticMeshComponent* WeaponMesh = PerformingCharacter->
		//PerformingCharacter->Weapon
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Owner NOT Found"))
		return;
	}
if (WeaponComponent)
{
	UE_LOG(LogTemp, Warning, TEXT("Swing Start with attached Weapon successfully"))
}
else
{
	UE_LOG(LogTemp, Warning, TEXT("Get Static Mesh Fail"))
}
}

void UNotifyState_WeaponSwing::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
}
