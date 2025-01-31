// Fill out your copyright notice in the Description page of Project Settings.


#include "LockOnSystem.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"


ULockOnSystem::ULockOnSystem()
{
	LockedOnTarget = nullptr;
	DistanceDivider = 2.0f;
	CharacterRotationInterpolation = 10.0f;
	CameraRotationInterpolation = 2.0f;

}

void ULockOnSystem::LockOnTarget(AEternal_Grace_ArenaCharacter* NewTarget, AEternal_Grace_ArenaCharacter* LockingActor)
{
	//UE_LOG(LogTemp, Warning, TEXT("Locked on To : %s"), *NewTarget->GetName())
	LockedOnTarget = NewTarget;
}

void ULockOnSystem::UpdateLockOn(AEternal_Grace_ArenaCharacter* LockingActor, float DeltaSeconds)
{
	if(!LockedOnTarget ||!LockingActor)
	{
		return;
	}

	//GET RELEVANT POSITIONS
	FVector LockingActorPosition = LockingActor->GetActorLocation();
	FVector CameraPosition = LockingActor->GetFollowCamera()->GetComponentLocation();
	FVector TargetPosition = LockedOnTarget->GetCapsuleComponent()->GetComponentLocation();
	//GET RELEVANT ROTATIONS
	FRotator LockingActorRotation = LockingActor->GetActorRotation();
	FRotator CameraRotation = LockingActor->GetFollowCamera()->GetComponentRotation();

	//DIVIDE DISTANCE TO OPTIMIZE CAMERA Z ANGLE
	float Divider = UKismetMathLibrary::Vector_Distance(LockingActorPosition, TargetPosition) / DistanceDivider;
	FVector TargetCameraDirection = FVector(TargetPosition.X, TargetPosition.Y, TargetPosition.Z - Divider);

	//SET LOCKING ACTOR ROTATION
	FRotator Look = UKismetMathLibrary::FindLookAtRotation(LockingActorPosition, TargetPosition);
	FRotator NewRotation = FMath::RInterpTo(LockingActorRotation, Look, DeltaSeconds, CharacterRotationInterpolation);
	LockingActor->SetActorRotation(NewRotation);

	//SET CAMERA ROTATION
	FRotator CameraLook = UKismetMathLibrary::FindLookAtRotation(CameraPosition, TargetCameraDirection);
	FRotator InterpolatedRotation = FMath::RInterpTo(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetControlRotation(), CameraLook, DeltaSeconds, CameraRotationInterpolation);

	// ONLY USE INTERPOLATED PITCH AND YAW
	FRotator UltimateRotation = FRotator(InterpolatedRotation.Pitch, InterpolatedRotation.Yaw, UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetControlRotation().Roll);
	UGameplayStatics::GetPlayerController(GetWorld(),0)->SetControlRotation(UltimateRotation);

}

void ULockOnSystem::UnlockTarget()
{
	LockedOnTarget = nullptr;
}

AEternal_Grace_ArenaCharacter* ULockOnSystem::GetLockedOnTarget()
{
	return LockedOnTarget;
}
