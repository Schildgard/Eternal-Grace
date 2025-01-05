// Fill out your copyright notice in the Description page of Project Settings.


#include "EternalGrace_PlayerState.h"

void AEternalGrace_PlayerState::SetPlayerHealth(float HealthFromPlayer)
{
	CurrentHealth = HealthFromPlayer;
}

float AEternalGrace_PlayerState::GetPlayerHealth()
{
	return CurrentHealth;
}
