// Copyright Epic Games, Inc. All Rights Reserved.

#include "Eternal_Grace_ArenaCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "CharacterAnimInstance.h"
#include "Kismet/KismetMathLibrary.h"
#include "HealthComponent.h"
#include "StaggerComponent.h"
#include "WeaponComponent.h"
#include "ShieldComponent.h"
#include "StatusEffectComponent.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// AEternal_Grace_ArenaCharacter

AEternal_Grace_ArenaCharacter::AEternal_Grace_ArenaCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)

	PhysicalMaterial = nullptr;
	WeaponSocket = FName("socket_weaponGrip");
	ShieldSocket = FName("socket_shieldGrip");

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health"));
	StaggerComponent = CreateDefaultSubobject<UStaggerComponent>(TEXT("StaggerCOmponent"));

	WeaponComponent = CreateDefaultSubobject<UWeaponComponent>("Equipment: Weapon");
	WeaponComponent->SetupAttachment(GetMesh(), WeaponSocket);

	ShieldComponent = CreateDefaultSubobject<UShieldComponent>("Equipment: Shield");
	ShieldComponent->SetupAttachment(GetMesh(), ShieldSocket);
}

void AEternal_Grace_ArenaCharacter::SetAttackStatus(UAnimMontage* AttackAnimation)
{
	CharacterAnimationInstance->isAttacking = true;
	CharacterAnimationInstance->attackCount++;
	UE_LOG(LogTemp, Warning, TEXT("Character Releases Attack"))
}

//////////////////////////////////////////////////////////////////////////
// Input

void AEternal_Grace_ArenaCharacter::NotifyControllerChanged()
{
	Super::NotifyControllerChanged();

	// Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void AEternal_Grace_ArenaCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {

		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AEternal_Grace_ArenaCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AEternal_Grace_ArenaCharacter::Look);


		//Guarding
		EnhancedInputComponent->BindAction(GuardAction, ETriggerEvent::Triggered, this, &AEternal_Grace_ArenaCharacter::Guard);
		EnhancedInputComponent->BindAction(GuardAction, ETriggerEvent::Completed, this, &AEternal_Grace_ArenaCharacter::CancelGuard);
		EnhancedInputComponent->BindAction(GuardAction, ETriggerEvent::Canceled, this, &AEternal_Grace_ArenaCharacter::CancelGuard);

		//Light Attack
		EnhancedInputComponent->BindAction(LightAttackAction, ETriggerEvent::Triggered, this, &AEternal_Grace_ArenaCharacter::LightAttack);


	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AEternal_Grace_ArenaCharacter::BeginPlay()
{
	Super::BeginPlay();
	world = GetWorld();
	InitializeAnimationInstance();

	if (CharacterAnimationInstance && ShieldComponent && ShieldComponent->CheckEquippedShieldClass())
	{
		ShieldComponent->SetAnimationInstanceReference();
	}
}

void AEternal_Grace_ArenaCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AEternal_Grace_ArenaCharacter::InitializeAnimationInstance()
{

	//CHECK IF CHARACTER HAS A VIABLE ANIMATION INSTANCE AND GET IT
	if (UAnimInstance* CurrentAnimInstance = GetMesh()->GetAnimInstance())
	{
		//CAST ANIMATION INSTANCE TO SPECIFIC CHARACTER ANIMATION INSTANCE
		CharacterAnimationInstance = Cast<UCharacterAnimInstance>(CurrentAnimInstance);
			return;
	}
	UE_LOG(LogTemp, Warning, TEXT("Animation Instance could not be found"))
}

FVector AEternal_Grace_ArenaCharacter::GetTargetLocation(AActor* Requestor) const
{
	USkeletalMeshComponent* SkeletalMesh = GetMesh();
	if(SkeletalMesh)
	{
		return SkeletalMesh->GetSocketLocation("Target");
	}
	return Super::GetTargetLocation(Requestor);
}

void AEternal_Grace_ArenaCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AEternal_Grace_ArenaCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}


void AEternal_Grace_ArenaCharacter::GetDamage_Implementation(float Damage, float PoiseDamage, float DamageDirection, EStaggeringType StaggerType, AEternal_Grace_ArenaCharacter* DamageSource, bool Blocked)
{

	if (Blocked == true)
	{
		ShieldComponent->BlockDamage(Damage, PoiseDamage, DamageDirection, StaggerType, DamageSource);
		return;
	}

	HealthComponent->CurrentHealth -= Damage;

		if (StaggerComponent)
		{
			StaggerComponent->GetStaggered(StaggerType, PoiseDamage, DamageDirection, DamageSource);
		}

	if (HealthComponent->CurrentHealth <= 0)
	{
		HealthComponent->CurrentHealth = 0;
		Execute_Die(this);
	}

}

void AEternal_Grace_ArenaCharacter::Die_Implementation()
{
	if (DeathAnimation)
	{
		CharacterAnimationInstance->StopAllMontages(0.1f);
		PlayAnimMontage(DeathAnimation);
		SetActorEnableCollision(false);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No DeathAnimation Assigned to %s"), *GetName())
	}
	OnCharacterDeath.Broadcast();
}

void AEternal_Grace_ArenaCharacter::FellOutOfWorld(const UDamageType& dmgType)
{
	Execute_Die(this);
}

void AEternal_Grace_ArenaCharacter::LightAttack()
{
	if(!canAttack)
	{
		return;
	}
}

void AEternal_Grace_ArenaCharacter::QuitAttack()
{
	if(CharacterAnimationInstance)
	{
		UE_LOG(LogTemp, Warning, TEXT("QUIT ATTACK CALLED"))
			UE_LOG(LogTemp, Warning, TEXT("Before: isAttacking = %s"), *FString(CharacterAnimationInstance->isAttacking ? TEXT("true") : TEXT("false")));

		CharacterAnimationInstance->isAttacking = false;
		CharacterAnimationInstance->Montage_Stop(0.1f);

		UE_LOG(LogTemp, Warning, TEXT("After: isAttacking = %s"), *FString(CharacterAnimationInstance->isAttacking ? TEXT("true") : TEXT("false")));
	}
}




void AEternal_Grace_ArenaCharacter::Guard()
{
	if (!CharacterAnimationInstance->isAttacking && !StaggerComponent->GetIsStaggered())
	{
		CharacterAnimationInstance->isGuarding = true;
	}
	else if (CharacterAnimationInstance->isGuarding == true)
	{
		CancelGuard();
	}
}

void AEternal_Grace_ArenaCharacter::CancelGuard()
{
	if (CharacterAnimationInstance->isGuarding)
	{
		CharacterAnimationInstance->isGuarding = false;
	}
}

UStatusEffectComponent* AEternal_Grace_ArenaCharacter::GetStatusEffectComponent()
{
	return StatusEffectComponent;
}

void AEternal_Grace_ArenaCharacter::RotateTowardsTarget(AActor* Target)
{
	//GET LOOK ROTATION BETWEEN PLAYER AND TARGET
	FRotator Look = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), Target->GetActorLocation());
	//BREAK LOOK ROTATION TO YAW ONLY
	FRotator DesiredRotation = FRotator(0, Look.Yaw, 0);
	SetActorRotation(DesiredRotation);
}

