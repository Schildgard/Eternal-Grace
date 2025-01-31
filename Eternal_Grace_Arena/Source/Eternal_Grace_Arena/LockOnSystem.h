// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LockOnSystem.generated.h"

/**
 * 
 */
class AEternal_Grace_ArenaCharacter;
UCLASS()
class ETERNAL_GRACE_ARENA_API ULockOnSystem : public UObject
{
	GENERATED_BODY()

    ULockOnSystem();

public:
    UFUNCTION(BlueprintCallable, Category = "LockOn")
    void LockOnTarget(AEternal_Grace_ArenaCharacter* NewTarget, AEternal_Grace_ArenaCharacter* LockingActor);
    UFUNCTION(BlueprintCallable, Category = "LockOn")
    void UpdateLockOn(AEternal_Grace_ArenaCharacter* LockingActor, float DeltaTime);
    UFUNCTION(BlueprintCallable, Category = "LockOn")
    void UnlockTarget();
    UFUNCTION()
    AEternal_Grace_ArenaCharacter* GetLockedOnTarget();


private:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "LockOn", meta = (AllowPrivateAccess))
    float CameraRotationInterpolation;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "LockOn", meta = (AllowPrivateAccess))
    float CharacterRotationInterpolation;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "LockOn", meta = (AllowPrivateAccess))
    float DistanceDivider;
    UPROPERTY()
    AEternal_Grace_ArenaCharacter* LockedOnTarget;
};
