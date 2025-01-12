// Fill out your copyright notice in the Description page of Project Settings.


#include "Shield.h"


AShield::AShield()
{
	Stats =
	{
		100.0f,
		50.0f,
		nullptr,
	};
}

FShieldStats AShield::GetShieldStats()
{
	return Stats;
}
