// Fill out your copyright notice in the Description page of Project Settings.


#include "Eternal_Grace_ProgressBar.h"
#include "HealthComponent.h"


void UEternal_Grace_ProgressBar::UpdateProgressBar(UProgressBar* Progressbar, float MaxValue, float CurrentValue)
{
	float Valuepercentage = CurrentValue / MaxValue;
	Progressbar->SetPercent(Valuepercentage);
}
