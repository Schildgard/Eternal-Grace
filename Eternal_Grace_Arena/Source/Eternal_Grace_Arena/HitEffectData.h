// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PhysicalMaterials/PhysicalMaterial.h" // Für UPhysicalMaterial
#include "Sound/SoundBase.h" // Für USoundBase
#include "NiagaraSystem.h" // Für UNiagaraSystem
#include "HitEffectData.generated.h"

USTRUCT(BlueprintType)
struct FHitEffectData : public FTableRowBase
{
    GENERATED_BODY()

   UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hit Effect")
   UPhysicalMaterial* PhysicalMaterial;
 
   UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hit Effect")
   USoundBase* HitSound;
 
   UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hit Effect")
   UNiagaraSystem* NiagaraEffect;

    // Konstruktor für Defaults
    FHitEffectData();
};

