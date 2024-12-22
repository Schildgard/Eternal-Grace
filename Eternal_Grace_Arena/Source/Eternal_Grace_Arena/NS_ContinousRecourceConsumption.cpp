// Fill out your copyright notice in the Description page of Project Settings.


#include "NS_ContinousRecourceConsumption.h"

void UNS_ContinousRecourceConsumption::ConsumeRessource()
{
	//RessourceToConsume -= ConsumptionRate;
}

void UNS_ContinousRecourceConsumption::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference)
{
	//if (RessourceToConsume > 0.0f)
	//{
	//	ConsumeRessource();
	//}
}
