// Fill out your copyright notice in the Description page of Project Settings.


#include "Eternal_Grace_ProgressBar.h"
#include "HealthComponent.h"


void UEternal_Grace_ProgressBar::UpdateProgressBar(float MaxHealth, float CurrentHealth)
{
	float Healthpercentage = CurrentHealth / MaxHealth;
	Progressbar->SetPercent(Healthpercentage);
}
