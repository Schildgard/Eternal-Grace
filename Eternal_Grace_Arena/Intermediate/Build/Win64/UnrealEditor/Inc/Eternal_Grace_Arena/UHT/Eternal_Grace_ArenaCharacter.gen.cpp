// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Eternal_Grace_Arena/Eternal_Grace_ArenaCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEternal_Grace_ArenaCharacter() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UWorld_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
ETERNAL_GRACE_ARENA_API UClass* Z_Construct_UClass_AEternal_Grace_ArenaCharacter();
ETERNAL_GRACE_ARENA_API UClass* Z_Construct_UClass_AEternal_Grace_ArenaCharacter_NoRegister();
ETERNAL_GRACE_ARENA_API UClass* Z_Construct_UClass_UCharacterAnimInstance_NoRegister();
ETERNAL_GRACE_ARENA_API UClass* Z_Construct_UClass_UCharacterShield_NoRegister();
ETERNAL_GRACE_ARENA_API UClass* Z_Construct_UClass_UHealthComponent_NoRegister();
ETERNAL_GRACE_ARENA_API UClass* Z_Construct_UClass_UI_Damageable_NoRegister();
ETERNAL_GRACE_ARENA_API UClass* Z_Construct_UClass_UShieldComponent_NoRegister();
ETERNAL_GRACE_ARENA_API UClass* Z_Construct_UClass_UWeaponComponent_NoRegister();
ETERNAL_GRACE_ARENA_API UFunction* Z_Construct_UDelegateFunction_Eternal_Grace_Arena_OnCharacterDeath__DelegateSignature();
PHYSICSCORE_API UClass* Z_Construct_UClass_UPhysicalMaterial_NoRegister();
UPackage* Z_Construct_UPackage__Script_Eternal_Grace_Arena();
// End Cross Module References

// Begin Delegate FOnCharacterDeath
struct Z_Construct_UDelegateFunction_Eternal_Grace_Arena_OnCharacterDeath__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Eternal_Grace_ArenaCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_Eternal_Grace_Arena_OnCharacterDeath__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_Eternal_Grace_Arena, nullptr, "OnCharacterDeath__DelegateSignature", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Eternal_Grace_Arena_OnCharacterDeath__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Eternal_Grace_Arena_OnCharacterDeath__DelegateSignature_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UDelegateFunction_Eternal_Grace_Arena_OnCharacterDeath__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Eternal_Grace_Arena_OnCharacterDeath__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnCharacterDeath_DelegateWrapper(const FMulticastScriptDelegate& OnCharacterDeath)
{
	OnCharacterDeath.ProcessMulticastDelegate<UObject>(NULL);
}
// End Delegate FOnCharacterDeath

// Begin Class AEternal_Grace_ArenaCharacter Function CancelGuard
struct Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_CancelGuard_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Eternal_Grace_ArenaCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_CancelGuard_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEternal_Grace_ArenaCharacter, nullptr, "CancelGuard", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_CancelGuard_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_CancelGuard_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_CancelGuard()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_CancelGuard_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEternal_Grace_ArenaCharacter::execCancelGuard)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CancelGuard();
	P_NATIVE_END;
}
// End Class AEternal_Grace_ArenaCharacter Function CancelGuard

// Begin Class AEternal_Grace_ArenaCharacter Function CheckActorStaggerAnimation
struct Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_CheckActorStaggerAnimation_Statics
{
	struct Eternal_Grace_ArenaCharacter_eventCheckActorStaggerAnimation_Parms
	{
		UAnimMontage* Montage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Eternal_Grace_ArenaCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Montage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_CheckActorStaggerAnimation_Statics::NewProp_Montage = { "Montage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Eternal_Grace_ArenaCharacter_eventCheckActorStaggerAnimation_Parms, Montage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_CheckActorStaggerAnimation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_CheckActorStaggerAnimation_Statics::NewProp_Montage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_CheckActorStaggerAnimation_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_CheckActorStaggerAnimation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEternal_Grace_ArenaCharacter, nullptr, "CheckActorStaggerAnimation", nullptr, nullptr, Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_CheckActorStaggerAnimation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_CheckActorStaggerAnimation_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_CheckActorStaggerAnimation_Statics::Eternal_Grace_ArenaCharacter_eventCheckActorStaggerAnimation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_CheckActorStaggerAnimation_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_CheckActorStaggerAnimation_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_CheckActorStaggerAnimation_Statics::Eternal_Grace_ArenaCharacter_eventCheckActorStaggerAnimation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_CheckActorStaggerAnimation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_CheckActorStaggerAnimation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEternal_Grace_ArenaCharacter::execCheckActorStaggerAnimation)
{
	P_GET_OBJECT(UAnimMontage,Z_Param_Montage);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CheckActorStaggerAnimation(Z_Param_Montage);
	P_NATIVE_END;
}
// End Class AEternal_Grace_ArenaCharacter Function CheckActorStaggerAnimation

// Begin Class AEternal_Grace_ArenaCharacter Function Guard
struct Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_Guard_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Eternal_Grace_ArenaCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_Guard_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEternal_Grace_ArenaCharacter, nullptr, "Guard", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_Guard_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_Guard_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_Guard()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_Guard_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEternal_Grace_ArenaCharacter::execGuard)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Guard();
	P_NATIVE_END;
}
// End Class AEternal_Grace_ArenaCharacter Function Guard

// Begin Class AEternal_Grace_ArenaCharacter Function LightAttack
struct Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_LightAttack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//COMBAT ACTION FUNCTIONS\n" },
#endif
		{ "ModuleRelativePath", "Eternal_Grace_ArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "COMBAT ACTION FUNCTIONS" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_LightAttack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEternal_Grace_ArenaCharacter, nullptr, "LightAttack", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_LightAttack_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_LightAttack_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_LightAttack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_LightAttack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEternal_Grace_ArenaCharacter::execLightAttack)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->LightAttack();
	P_NATIVE_END;
}
// End Class AEternal_Grace_ArenaCharacter Function LightAttack

// Begin Class AEternal_Grace_ArenaCharacter Function RotateTowardsTarget
struct Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_RotateTowardsTarget_Statics
{
	struct Eternal_Grace_ArenaCharacter_eventRotateTowardsTarget_Parms
	{
		AActor* Target;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Eternal_Grace_ArenaCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_RotateTowardsTarget_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Eternal_Grace_ArenaCharacter_eventRotateTowardsTarget_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_RotateTowardsTarget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_RotateTowardsTarget_Statics::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_RotateTowardsTarget_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_RotateTowardsTarget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEternal_Grace_ArenaCharacter, nullptr, "RotateTowardsTarget", nullptr, nullptr, Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_RotateTowardsTarget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_RotateTowardsTarget_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_RotateTowardsTarget_Statics::Eternal_Grace_ArenaCharacter_eventRotateTowardsTarget_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_RotateTowardsTarget_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_RotateTowardsTarget_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_RotateTowardsTarget_Statics::Eternal_Grace_ArenaCharacter_eventRotateTowardsTarget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_RotateTowardsTarget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_RotateTowardsTarget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEternal_Grace_ArenaCharacter::execRotateTowardsTarget)
{
	P_GET_OBJECT(AActor,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RotateTowardsTarget(Z_Param_Target);
	P_NATIVE_END;
}
// End Class AEternal_Grace_ArenaCharacter Function RotateTowardsTarget

// Begin Class AEternal_Grace_ArenaCharacter
void AEternal_Grace_ArenaCharacter::StaticRegisterNativesAEternal_Grace_ArenaCharacter()
{
	UClass* Class = AEternal_Grace_ArenaCharacter::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CancelGuard", &AEternal_Grace_ArenaCharacter::execCancelGuard },
		{ "CheckActorStaggerAnimation", &AEternal_Grace_ArenaCharacter::execCheckActorStaggerAnimation },
		{ "Guard", &AEternal_Grace_ArenaCharacter::execGuard },
		{ "LightAttack", &AEternal_Grace_ArenaCharacter::execLightAttack },
		{ "RotateTowardsTarget", &AEternal_Grace_ArenaCharacter::execRotateTowardsTarget },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEternal_Grace_ArenaCharacter);
UClass* Z_Construct_UClass_AEternal_Grace_ArenaCharacter_NoRegister()
{
	return AEternal_Grace_ArenaCharacter::StaticClass();
}
struct Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Eternal_Grace_ArenaCharacter.h" },
		{ "ModuleRelativePath", "Eternal_Grace_ArenaCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Camera boom positioning the camera behind the character */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Eternal_Grace_ArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera boom positioning the camera behind the character" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Follow camera */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Eternal_Grace_ArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Follow camera" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMappingContext_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** MappingContext */" },
#endif
		{ "ModuleRelativePath", "Eternal_Grace_ArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "MappingContext" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Jump Input Action */" },
#endif
		{ "ModuleRelativePath", "Eternal_Grace_ArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Jump Input Action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Move Input Action */" },
#endif
		{ "ModuleRelativePath", "Eternal_Grace_ArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Move Input Action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LookAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Look Input Action */" },
#endif
		{ "ModuleRelativePath", "Eternal_Grace_ArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Look Input Action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LightAttackAction_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//CUSTOM ACTIONS\n" },
#endif
		{ "ModuleRelativePath", "Eternal_Grace_ArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "CUSTOM ACTIONS" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GuardAction_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Eternal_Grace_ArenaCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LightAttacks_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Animations" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//LIGHT ATTACKS\n" },
#endif
		{ "ModuleRelativePath", "Eternal_Grace_ArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "LIGHT ATTACKS" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeathAnimation_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Animations" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//DEATH ANIMATIONS\n" },
#endif
		{ "ModuleRelativePath", "Eternal_Grace_ArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "DEATH ANIMATIONS" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeathAnimationWithKnockBack_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Animations" },
		{ "ModuleRelativePath", "Eternal_Grace_ArenaCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_world_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//GENERAL PROPERTIES\n" },
#endif
		{ "ModuleRelativePath", "Eternal_Grace_ArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "GENERAL PROPERTIES" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PhysicalMaterial_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "HitEffect" },
		{ "ModuleRelativePath", "Eternal_Grace_ArenaCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterAnimationInstance_MetaData[] = {
		{ "ModuleRelativePath", "Eternal_Grace_ArenaCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WeaponSocket_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Equipment" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//WEAPON\n" },
#endif
		{ "ModuleRelativePath", "Eternal_Grace_ArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "WEAPON" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WeaponComponent_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Equipment" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Eternal_Grace_ArenaCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Shield_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Equipment" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//SHIELD\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Eternal_Grace_ArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "SHIELD" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShieldSocket_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Equipment" },
		{ "ModuleRelativePath", "Eternal_Grace_ArenaCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShieldComponent_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Equipment" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Eternal_Grace_ArenaCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealthComponent_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Attributes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//HEALTH\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Eternal_Grace_ArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "HEALTH" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCharacterDeath_MetaData[] = {
		{ "Category", "Events" },
		{ "ModuleRelativePath", "Eternal_Grace_ArenaCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMappingContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LightAttackAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GuardAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LightAttacks_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_LightAttacks;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DeathAnimation;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DeathAnimationWithKnockBack;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_world;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PhysicalMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CharacterAnimationInstance;
	static const UECodeGen_Private::FNamePropertyParams NewProp_WeaponSocket;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WeaponComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Shield;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ShieldSocket;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ShieldComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HealthComponent;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCharacterDeath;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_CancelGuard, "CancelGuard" }, // 634185616
		{ &Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_CheckActorStaggerAnimation, "CheckActorStaggerAnimation" }, // 1367190048
		{ &Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_Guard, "Guard" }, // 14112022
		{ &Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_LightAttack, "LightAttack" }, // 2932826134
		{ &Z_Construct_UFunction_AEternal_Grace_ArenaCharacter_RotateTowardsTarget, "RotateTowardsTarget" }, // 3593094434
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEternal_Grace_ArenaCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEternal_Grace_ArenaCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraBoom_MetaData), NewProp_CameraBoom_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEternal_Grace_ArenaCharacter, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FollowCamera_MetaData), NewProp_FollowCamera_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_DefaultMappingContext = { "DefaultMappingContext", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEternal_Grace_ArenaCharacter, DefaultMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultMappingContext_MetaData), NewProp_DefaultMappingContext_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEternal_Grace_ArenaCharacter, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpAction_MetaData), NewProp_JumpAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEternal_Grace_ArenaCharacter, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveAction_MetaData), NewProp_MoveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEternal_Grace_ArenaCharacter, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LookAction_MetaData), NewProp_LookAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_LightAttackAction = { "LightAttackAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEternal_Grace_ArenaCharacter, LightAttackAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LightAttackAction_MetaData), NewProp_LightAttackAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_GuardAction = { "GuardAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEternal_Grace_ArenaCharacter, GuardAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GuardAction_MetaData), NewProp_GuardAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_LightAttacks_Inner = { "LightAttacks", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_LightAttacks = { "LightAttacks", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEternal_Grace_ArenaCharacter, LightAttacks), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LightAttacks_MetaData), NewProp_LightAttacks_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_DeathAnimation = { "DeathAnimation", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEternal_Grace_ArenaCharacter, DeathAnimation), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeathAnimation_MetaData), NewProp_DeathAnimation_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_DeathAnimationWithKnockBack = { "DeathAnimationWithKnockBack", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEternal_Grace_ArenaCharacter, DeathAnimationWithKnockBack), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeathAnimationWithKnockBack_MetaData), NewProp_DeathAnimationWithKnockBack_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_world = { "world", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEternal_Grace_ArenaCharacter, world), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_world_MetaData), NewProp_world_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_PhysicalMaterial = { "PhysicalMaterial", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEternal_Grace_ArenaCharacter, PhysicalMaterial), Z_Construct_UClass_UPhysicalMaterial_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PhysicalMaterial_MetaData), NewProp_PhysicalMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_CharacterAnimationInstance = { "CharacterAnimationInstance", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEternal_Grace_ArenaCharacter, CharacterAnimationInstance), Z_Construct_UClass_UCharacterAnimInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterAnimationInstance_MetaData), NewProp_CharacterAnimationInstance_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_WeaponSocket = { "WeaponSocket", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEternal_Grace_ArenaCharacter, WeaponSocket), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WeaponSocket_MetaData), NewProp_WeaponSocket_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_WeaponComponent = { "WeaponComponent", nullptr, (EPropertyFlags)0x001000000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEternal_Grace_ArenaCharacter, WeaponComponent), Z_Construct_UClass_UWeaponComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WeaponComponent_MetaData), NewProp_WeaponComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_Shield = { "Shield", nullptr, (EPropertyFlags)0x001000000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEternal_Grace_ArenaCharacter, Shield), Z_Construct_UClass_UCharacterShield_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Shield_MetaData), NewProp_Shield_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_ShieldSocket = { "ShieldSocket", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEternal_Grace_ArenaCharacter, ShieldSocket), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShieldSocket_MetaData), NewProp_ShieldSocket_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_ShieldComponent = { "ShieldComponent", nullptr, (EPropertyFlags)0x001000000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEternal_Grace_ArenaCharacter, ShieldComponent), Z_Construct_UClass_UShieldComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShieldComponent_MetaData), NewProp_ShieldComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_HealthComponent = { "HealthComponent", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEternal_Grace_ArenaCharacter, HealthComponent), Z_Construct_UClass_UHealthComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealthComponent_MetaData), NewProp_HealthComponent_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_OnCharacterDeath = { "OnCharacterDeath", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEternal_Grace_ArenaCharacter, OnCharacterDeath), Z_Construct_UDelegateFunction_Eternal_Grace_Arena_OnCharacterDeath__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCharacterDeath_MetaData), NewProp_OnCharacterDeath_MetaData) }; // 550197217
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_CameraBoom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_FollowCamera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_DefaultMappingContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_JumpAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_MoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_LookAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_LightAttackAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_GuardAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_LightAttacks_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_LightAttacks,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_DeathAnimation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_DeathAnimationWithKnockBack,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_world,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_PhysicalMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_CharacterAnimationInstance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_WeaponSocket,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_WeaponComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_Shield,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_ShieldSocket,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_ShieldComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_HealthComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::NewProp_OnCharacterDeath,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_Eternal_Grace_Arena,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UI_Damageable_NoRegister, (int32)VTABLE_OFFSET(AEternal_Grace_ArenaCharacter, II_Damageable), false },  // 1245346242
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::ClassParams = {
	&AEternal_Grace_ArenaCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x008000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEternal_Grace_ArenaCharacter()
{
	if (!Z_Registration_Info_UClass_AEternal_Grace_ArenaCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEternal_Grace_ArenaCharacter.OuterSingleton, Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEternal_Grace_ArenaCharacter.OuterSingleton;
}
template<> ETERNAL_GRACE_ARENA_API UClass* StaticClass<AEternal_Grace_ArenaCharacter>()
{
	return AEternal_Grace_ArenaCharacter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEternal_Grace_ArenaCharacter);
AEternal_Grace_ArenaCharacter::~AEternal_Grace_ArenaCharacter() {}
// End Class AEternal_Grace_ArenaCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_Repository_Eternal_Grace_Arena_Eternal_Grace_Arena_Source_Eternal_Grace_Arena_Eternal_Grace_ArenaCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEternal_Grace_ArenaCharacter, AEternal_Grace_ArenaCharacter::StaticClass, TEXT("AEternal_Grace_ArenaCharacter"), &Z_Registration_Info_UClass_AEternal_Grace_ArenaCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEternal_Grace_ArenaCharacter), 2692526577U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Repository_Eternal_Grace_Arena_Eternal_Grace_Arena_Source_Eternal_Grace_Arena_Eternal_Grace_ArenaCharacter_h_2458511100(TEXT("/Script/Eternal_Grace_Arena"),
	Z_CompiledInDeferFile_FID_Repository_Eternal_Grace_Arena_Eternal_Grace_Arena_Source_Eternal_Grace_Arena_Eternal_Grace_ArenaCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Repository_Eternal_Grace_Arena_Eternal_Grace_Arena_Source_Eternal_Grace_Arena_Eternal_Grace_ArenaCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
