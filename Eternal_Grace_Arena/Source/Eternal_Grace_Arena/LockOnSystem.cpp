// Fill out your copyright notice in the Description page of Project Settings.


#include "LockOnSystem.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

void ULockOnSystem::LockOnTarget(AEternal_Grace_ArenaCharacter* NewTarget, AEternal_Grace_ArenaCharacter* LockingActor)
{
	UE_LOG(LogTemp, Warning, TEXT("Locked on : %s"), *NewTarget->GetName())
	LockedOnTarget = NewTarget;
}

void ULockOnSystem::UpdateLockOn(AEternal_Grace_ArenaCharacter* LockingActor, float DeltaTime)
{
	if(!LockedOnTarget ||!LockingActor)
	{
		return;
	}

	FVector LockingActorPosition = LockingActor->GetActorLocation();
	FVector CameraPosition = LockingActor->GetFollowCamera()->GetComponentLocation();
	FVector TargetPosition = LockedOnTarget->GetActorLocation();

	FRotator LockingActorRotation = LockingActor->GetActorRotation();
	FRotator CameraRotation = LockingActor->GetFollowCamera()->GetComponentRotation();



	float Divider = UKismetMathLibrary::Vector_Distance(LockingActorPosition, TargetPosition) / 2;
	FVector TargetTestPosition = FVector(TargetPosition.X, TargetPosition.Y, TargetPosition.Z - Divider);




	FRotator Look = UKismetMathLibrary::FindLookAtRotation(LockingActorPosition, TargetPosition);
	FRotator NewRotation = FMath::RInterpTo(LockingActorRotation, Look, DeltaTime, 10.0f);
	LockingActor->SetActorRotation(Look);


	FRotator CameraLook = UKismetMathLibrary::FindLookAtRotation(CameraPosition, TargetTestPosition);

	FRotator InterpolatedRotation = FMath::RInterpTo(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetControlRotation(), CameraLook, 0.01f, 1.0f);

	FRotator UltimateRotation = FRotator(InterpolatedRotation.Pitch, InterpolatedRotation.Yaw, UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetControlRotation().Roll);
	//UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetControlRotation().Roll;
	UGameplayStatics::GetPlayerController(GetWorld(),0)->SetControlRotation(UltimateRotation);
	//TODO:: SET OFFSET




}

void ULockOnSystem::UnlockTarget()
{
	UE_LOG(LogTemp, Warning, TEXT("Unlock"))
	LockedOnTarget = nullptr;
}

AEternal_Grace_ArenaCharacter* ULockOnSystem::GetLockedOnTarget()
{
	return LockedOnTarget;
}
