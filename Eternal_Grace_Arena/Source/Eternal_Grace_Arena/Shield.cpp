// Fill out your copyright notice in the Description page of Project Settings.


#include "Shield.h"


AShield::AShield()
{

	Stats.PhysicalDamageReduction = 100.0f;
	Stats.Stability = 50.0f;
	Stats.PhysicalMaterial = nullptr;

}

FShieldStats AShield::GetShieldStats()
{
	return Stats;
}
