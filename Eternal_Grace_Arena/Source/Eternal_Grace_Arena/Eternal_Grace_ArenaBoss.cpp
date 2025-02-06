// Fill out your copyright notice in the Description page of Project Settings.


#include "Eternal_Grace_ArenaBoss.h"
#include "HealthComponent.h"

AEternal_Grace_ArenaBoss::AEternal_Grace_ArenaBoss()
{
	SecondPhaseMontage = nullptr;
	SecondPhaseTriggered = false;
	isAggro = true;
	GetOffMeAttack = nullptr;
	HealthbarWidget = nullptr;
	HealthbarWidgetClass = nullptr;
}

void AEternal_Grace_ArenaBoss::TriggerSecondPhase()
{
	PlayAnimMontage(SecondPhaseMontage, 1.0f);
	SecondPhaseTriggered = true;
	UE_LOG(LogTemp, Error, TEXT("Can now perform GetOffMeMove"))
}

void AEternal_Grace_ArenaBoss::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (HealthComponent->CurrentHealth <= (HealthComponent->MaxHealth / 2) && !SecondPhaseTriggered)
	{
		TriggerSecondPhase();
	}
}

void AEternal_Grace_ArenaBoss::BeginPlay()
{
	Super::BeginPlay();

	if (HealthbarWidgetClass)
	{
		HealthbarWidget = CreateWidget<UEnemy_UI_Healthbar>(GetWorld(), HealthbarWidgetClass);
	}
	ShowHealthWidget();

}

void AEternal_Grace_ArenaBoss::GetOffMeMove()
{
}
