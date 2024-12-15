// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "StaggeringType.generated.h"

/**
 *
 */
UENUM(BlueprintType)
enum class EStaggeringType : uint8
{
		NormalStagger	UMETA(DisplayName = "NormalStagger"),
		HeavyStagger 	UMETA(DisplayName = "HeavyStagger"),
		KnockbackStagger UMETA(DisplayName = "KnockbackStagger"),
		ThrowupStagger	UMETA(DisplayName = "ThrowupStagger"),
		CrushdownStagger	UMETA(DisplayName = "CrushdownStagger"),
		NoStagger	UMETA(DisplayName = "NoStagger")
};
