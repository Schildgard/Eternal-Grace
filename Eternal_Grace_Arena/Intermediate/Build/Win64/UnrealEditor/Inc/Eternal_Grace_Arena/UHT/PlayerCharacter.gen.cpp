// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Eternal_Grace_Arena/PlayerCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlayerCharacter() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPostProcessComponent_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ETERNAL_GRACE_ARENA_API UClass* Z_Construct_UClass_AEternal_Grace_ArenaCharacter();
ETERNAL_GRACE_ARENA_API UClass* Z_Construct_UClass_APlayerCharacter();
ETERNAL_GRACE_ARENA_API UClass* Z_Construct_UClass_APlayerCharacter_NoRegister();
ETERNAL_GRACE_ARENA_API UClass* Z_Construct_UClass_UStaminaComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_Eternal_Grace_Arena();
// End Cross Module References

// Begin Class APlayerCharacter Function CancelSprint
struct Z_Construct_UFunction_APlayerCharacter_CancelSprint_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerCharacter_CancelSprint_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerCharacter, nullptr, "CancelSprint", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerCharacter_CancelSprint_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlayerCharacter_CancelSprint_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_APlayerCharacter_CancelSprint()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlayerCharacter_CancelSprint_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlayerCharacter::execCancelSprint)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CancelSprint();
	P_NATIVE_END;
}
// End Class APlayerCharacter Function CancelSprint

// Begin Class APlayerCharacter Function ChargeHeavyAttack
struct Z_Construct_UFunction_APlayerCharacter_ChargeHeavyAttack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerCharacter_ChargeHeavyAttack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerCharacter, nullptr, "ChargeHeavyAttack", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerCharacter_ChargeHeavyAttack_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlayerCharacter_ChargeHeavyAttack_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_APlayerCharacter_ChargeHeavyAttack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlayerCharacter_ChargeHeavyAttack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlayerCharacter::execChargeHeavyAttack)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ChargeHeavyAttack();
	P_NATIVE_END;
}
// End Class APlayerCharacter Function ChargeHeavyAttack

// Begin Class APlayerCharacter Function Dodge
struct Z_Construct_UFunction_APlayerCharacter_Dodge_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerCharacter_Dodge_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerCharacter, nullptr, "Dodge", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerCharacter_Dodge_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlayerCharacter_Dodge_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_APlayerCharacter_Dodge()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlayerCharacter_Dodge_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlayerCharacter::execDodge)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Dodge();
	P_NATIVE_END;
}
// End Class APlayerCharacter Function Dodge

// Begin Class APlayerCharacter Function GetPoisonPostProcessEffect
struct Z_Construct_UFunction_APlayerCharacter_GetPoisonPostProcessEffect_Statics
{
	struct PlayerCharacter_eventGetPoisonPostProcessEffect_Parms
	{
		UPostProcessComponent* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_APlayerCharacter_GetPoisonPostProcessEffect_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlayerCharacter_eventGetPoisonPostProcessEffect_Parms, ReturnValue), Z_Construct_UClass_UPostProcessComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlayerCharacter_GetPoisonPostProcessEffect_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerCharacter_GetPoisonPostProcessEffect_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerCharacter_GetPoisonPostProcessEffect_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerCharacter_GetPoisonPostProcessEffect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerCharacter, nullptr, "GetPoisonPostProcessEffect", nullptr, nullptr, Z_Construct_UFunction_APlayerCharacter_GetPoisonPostProcessEffect_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerCharacter_GetPoisonPostProcessEffect_Statics::PropPointers), sizeof(Z_Construct_UFunction_APlayerCharacter_GetPoisonPostProcessEffect_Statics::PlayerCharacter_eventGetPoisonPostProcessEffect_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerCharacter_GetPoisonPostProcessEffect_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlayerCharacter_GetPoisonPostProcessEffect_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_APlayerCharacter_GetPoisonPostProcessEffect_Statics::PlayerCharacter_eventGetPoisonPostProcessEffect_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_APlayerCharacter_GetPoisonPostProcessEffect()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlayerCharacter_GetPoisonPostProcessEffect_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlayerCharacter::execGetPoisonPostProcessEffect)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UPostProcessComponent**)Z_Param__Result=P_THIS->GetPoisonPostProcessEffect();
	P_NATIVE_END;
}
// End Class APlayerCharacter Function GetPoisonPostProcessEffect

// Begin Class APlayerCharacter Function GuardCounterAttack
struct Z_Construct_UFunction_APlayerCharacter_GuardCounterAttack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerCharacter_GuardCounterAttack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerCharacter, nullptr, "GuardCounterAttack", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerCharacter_GuardCounterAttack_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlayerCharacter_GuardCounterAttack_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_APlayerCharacter_GuardCounterAttack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlayerCharacter_GuardCounterAttack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlayerCharacter::execGuardCounterAttack)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GuardCounterAttack();
	P_NATIVE_END;
}
// End Class APlayerCharacter Function GuardCounterAttack

// Begin Class APlayerCharacter Function HeavyAttack
struct Z_Construct_UFunction_APlayerCharacter_HeavyAttack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerCharacter_HeavyAttack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerCharacter, nullptr, "HeavyAttack", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerCharacter_HeavyAttack_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlayerCharacter_HeavyAttack_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_APlayerCharacter_HeavyAttack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlayerCharacter_HeavyAttack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlayerCharacter::execHeavyAttack)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HeavyAttack();
	P_NATIVE_END;
}
// End Class APlayerCharacter Function HeavyAttack

// Begin Class APlayerCharacter Function IncreaseChargePower
struct Z_Construct_UFunction_APlayerCharacter_IncreaseChargePower_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerCharacter_IncreaseChargePower_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerCharacter, nullptr, "IncreaseChargePower", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerCharacter_IncreaseChargePower_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlayerCharacter_IncreaseChargePower_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_APlayerCharacter_IncreaseChargePower()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlayerCharacter_IncreaseChargePower_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlayerCharacter::execIncreaseChargePower)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->IncreaseChargePower();
	P_NATIVE_END;
}
// End Class APlayerCharacter Function IncreaseChargePower

// Begin Class APlayerCharacter Function Interact
struct Z_Construct_UFunction_APlayerCharacter_Interact_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//INTERACT\n" },
#endif
		{ "ModuleRelativePath", "PlayerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "INTERACT" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerCharacter_Interact_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerCharacter, nullptr, "Interact", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerCharacter_Interact_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlayerCharacter_Interact_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_APlayerCharacter_Interact()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlayerCharacter_Interact_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlayerCharacter::execInteract)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Interact();
	P_NATIVE_END;
}
// End Class APlayerCharacter Function Interact

// Begin Class APlayerCharacter Function Sprint
struct Z_Construct_UFunction_APlayerCharacter_Sprint_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerCharacter_Sprint_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerCharacter, nullptr, "Sprint", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerCharacter_Sprint_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlayerCharacter_Sprint_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_APlayerCharacter_Sprint()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlayerCharacter_Sprint_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlayerCharacter::execSprint)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Sprint();
	P_NATIVE_END;
}
// End Class APlayerCharacter Function Sprint

// Begin Class APlayerCharacter Function SprintAttack
struct Z_Construct_UFunction_APlayerCharacter_SprintAttack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerCharacter_SprintAttack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerCharacter, nullptr, "SprintAttack", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerCharacter_SprintAttack_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlayerCharacter_SprintAttack_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_APlayerCharacter_SprintAttack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlayerCharacter_SprintAttack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlayerCharacter::execSprintAttack)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SprintAttack();
	P_NATIVE_END;
}
// End Class APlayerCharacter Function SprintAttack

// Begin Class APlayerCharacter
void APlayerCharacter::StaticRegisterNativesAPlayerCharacter()
{
	UClass* Class = APlayerCharacter::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CancelSprint", &APlayerCharacter::execCancelSprint },
		{ "ChargeHeavyAttack", &APlayerCharacter::execChargeHeavyAttack },
		{ "Dodge", &APlayerCharacter::execDodge },
		{ "GetPoisonPostProcessEffect", &APlayerCharacter::execGetPoisonPostProcessEffect },
		{ "GuardCounterAttack", &APlayerCharacter::execGuardCounterAttack },
		{ "HeavyAttack", &APlayerCharacter::execHeavyAttack },
		{ "IncreaseChargePower", &APlayerCharacter::execIncreaseChargePower },
		{ "Interact", &APlayerCharacter::execInteract },
		{ "Sprint", &APlayerCharacter::execSprint },
		{ "SprintAttack", &APlayerCharacter::execSprintAttack },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APlayerCharacter);
UClass* Z_Construct_UClass_APlayerCharacter_NoRegister()
{
	return APlayerCharacter::StaticClass();
}
struct Z_Construct_UClass_APlayerCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "PlayerCharacter.h" },
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HeavyAttackAction_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SprintAction_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GuardCounterAction_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractAction_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DodgeAction_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultPostProcess_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "PostProcessing" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PoisonPostProcess_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "PostProcessing" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StaminaComponent_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Attribtues" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//STAMINA\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "PlayerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "STAMINA" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RunningStaminaConsumption_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Attribtues" },
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GuardCounter_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Animation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//GUARD COUNTER\n" },
#endif
		{ "ModuleRelativePath", "PlayerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "GUARD COUNTER" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GuardCounterPossible_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GuardCounterReactionCountdown_MetaData[] = {
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_currentChargePower_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Attributes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//HEAVY ATTACK PROPERTIES\n" },
#endif
		{ "ModuleRelativePath", "PlayerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "HEAVY ATTACK PROPERTIES" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_maxChargePower_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Attributes" },
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChargeAttack_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Animations" },
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RunningAttack_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Animations" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//SPRINT ATTACKS\n" },
#endif
		{ "ModuleRelativePath", "PlayerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "SPRINT ATTACKS" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractAnimation_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Animations" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//INTERACT\n" },
#endif
		{ "ModuleRelativePath", "PlayerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "INTERACT" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DodgeMontage_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Animations" },
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HeavyAttackAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SprintAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GuardCounterAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InteractAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DodgeAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultPostProcess;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PoisonPostProcess;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StaminaComponent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RunningStaminaConsumption;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GuardCounter;
	static void NewProp_GuardCounterPossible_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_GuardCounterPossible;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GuardCounterReactionCountdown;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_currentChargePower;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_maxChargePower;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ChargeAttack;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RunningAttack;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InteractAnimation;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DodgeMontage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_APlayerCharacter_CancelSprint, "CancelSprint" }, // 1635053788
		{ &Z_Construct_UFunction_APlayerCharacter_ChargeHeavyAttack, "ChargeHeavyAttack" }, // 1713464993
		{ &Z_Construct_UFunction_APlayerCharacter_Dodge, "Dodge" }, // 3111381103
		{ &Z_Construct_UFunction_APlayerCharacter_GetPoisonPostProcessEffect, "GetPoisonPostProcessEffect" }, // 3760307018
		{ &Z_Construct_UFunction_APlayerCharacter_GuardCounterAttack, "GuardCounterAttack" }, // 1036179294
		{ &Z_Construct_UFunction_APlayerCharacter_HeavyAttack, "HeavyAttack" }, // 171223720
		{ &Z_Construct_UFunction_APlayerCharacter_IncreaseChargePower, "IncreaseChargePower" }, // 2751030947
		{ &Z_Construct_UFunction_APlayerCharacter_Interact, "Interact" }, // 1929792896
		{ &Z_Construct_UFunction_APlayerCharacter_Sprint, "Sprint" }, // 2307348509
		{ &Z_Construct_UFunction_APlayerCharacter_SprintAttack, "SprintAttack" }, // 158576561
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APlayerCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_HeavyAttackAction = { "HeavyAttackAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, HeavyAttackAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HeavyAttackAction_MetaData), NewProp_HeavyAttackAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_SprintAction = { "SprintAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, SprintAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SprintAction_MetaData), NewProp_SprintAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_GuardCounterAction = { "GuardCounterAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, GuardCounterAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GuardCounterAction_MetaData), NewProp_GuardCounterAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_InteractAction = { "InteractAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, InteractAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractAction_MetaData), NewProp_InteractAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_DodgeAction = { "DodgeAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, DodgeAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DodgeAction_MetaData), NewProp_DodgeAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_DefaultPostProcess = { "DefaultPostProcess", nullptr, (EPropertyFlags)0x004000000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, DefaultPostProcess), Z_Construct_UClass_UPostProcessComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultPostProcess_MetaData), NewProp_DefaultPostProcess_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_PoisonPostProcess = { "PoisonPostProcess", nullptr, (EPropertyFlags)0x004000000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, PoisonPostProcess), Z_Construct_UClass_UPostProcessComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PoisonPostProcess_MetaData), NewProp_PoisonPostProcess_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_StaminaComponent = { "StaminaComponent", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, StaminaComponent), Z_Construct_UClass_UStaminaComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StaminaComponent_MetaData), NewProp_StaminaComponent_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_RunningStaminaConsumption = { "RunningStaminaConsumption", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, RunningStaminaConsumption), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RunningStaminaConsumption_MetaData), NewProp_RunningStaminaConsumption_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_GuardCounter = { "GuardCounter", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, GuardCounter), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GuardCounter_MetaData), NewProp_GuardCounter_MetaData) };
void Z_Construct_UClass_APlayerCharacter_Statics::NewProp_GuardCounterPossible_SetBit(void* Obj)
{
	((APlayerCharacter*)Obj)->GuardCounterPossible = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_GuardCounterPossible = { "GuardCounterPossible", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(APlayerCharacter), &Z_Construct_UClass_APlayerCharacter_Statics::NewProp_GuardCounterPossible_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GuardCounterPossible_MetaData), NewProp_GuardCounterPossible_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_GuardCounterReactionCountdown = { "GuardCounterReactionCountdown", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, GuardCounterReactionCountdown), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GuardCounterReactionCountdown_MetaData), NewProp_GuardCounterReactionCountdown_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_currentChargePower = { "currentChargePower", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, currentChargePower), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_currentChargePower_MetaData), NewProp_currentChargePower_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_maxChargePower = { "maxChargePower", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, maxChargePower), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_maxChargePower_MetaData), NewProp_maxChargePower_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_ChargeAttack = { "ChargeAttack", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, ChargeAttack), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChargeAttack_MetaData), NewProp_ChargeAttack_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_RunningAttack = { "RunningAttack", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, RunningAttack), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RunningAttack_MetaData), NewProp_RunningAttack_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_InteractAnimation = { "InteractAnimation", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, InteractAnimation), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractAnimation_MetaData), NewProp_InteractAnimation_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_DodgeMontage = { "DodgeMontage", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, DodgeMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DodgeMontage_MetaData), NewProp_DodgeMontage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APlayerCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_HeavyAttackAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_SprintAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_GuardCounterAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_InteractAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_DodgeAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_DefaultPostProcess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_PoisonPostProcess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_StaminaComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_RunningStaminaConsumption,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_GuardCounter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_GuardCounterPossible,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_GuardCounterReactionCountdown,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_currentChargePower,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_maxChargePower,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_ChargeAttack,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_RunningAttack,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_InteractAnimation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_DodgeMontage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APlayerCharacter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_APlayerCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AEternal_Grace_ArenaCharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_Eternal_Grace_Arena,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APlayerCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_APlayerCharacter_Statics::ClassParams = {
	&APlayerCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_APlayerCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_APlayerCharacter_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APlayerCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_APlayerCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_APlayerCharacter()
{
	if (!Z_Registration_Info_UClass_APlayerCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APlayerCharacter.OuterSingleton, Z_Construct_UClass_APlayerCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_APlayerCharacter.OuterSingleton;
}
template<> ETERNAL_GRACE_ARENA_API UClass* StaticClass<APlayerCharacter>()
{
	return APlayerCharacter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(APlayerCharacter);
APlayerCharacter::~APlayerCharacter() {}
// End Class APlayerCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_Repository_Eternal_Grace_Arena_Eternal_Grace_Arena_Source_Eternal_Grace_Arena_PlayerCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APlayerCharacter, APlayerCharacter::StaticClass, TEXT("APlayerCharacter"), &Z_Registration_Info_UClass_APlayerCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APlayerCharacter), 2379717419U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Repository_Eternal_Grace_Arena_Eternal_Grace_Arena_Source_Eternal_Grace_Arena_PlayerCharacter_h_3518010768(TEXT("/Script/Eternal_Grace_Arena"),
	Z_CompiledInDeferFile_FID_Repository_Eternal_Grace_Arena_Eternal_Grace_Arena_Source_Eternal_Grace_Arena_PlayerCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Repository_Eternal_Grace_Arena_Eternal_Grace_Arena_Source_Eternal_Grace_Arena_PlayerCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
