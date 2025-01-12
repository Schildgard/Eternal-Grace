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
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
ENGINE_API UEnum* Z_Construct_UEnum_Engine_EObjectTypeQuery();
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

// Begin Class APlayerCharacter Function DisengageLockOn
struct Z_Construct_UFunction_APlayerCharacter_DisengageLockOn_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerCharacter_DisengageLockOn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerCharacter, nullptr, "DisengageLockOn", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerCharacter_DisengageLockOn_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlayerCharacter_DisengageLockOn_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_APlayerCharacter_DisengageLockOn()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlayerCharacter_DisengageLockOn_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlayerCharacter::execDisengageLockOn)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DisengageLockOn();
	P_NATIVE_END;
}
// End Class APlayerCharacter Function DisengageLockOn

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

// Begin Class APlayerCharacter Function EngageLockOn
struct Z_Construct_UFunction_APlayerCharacter_EngageLockOn_Statics
{
	struct PlayerCharacter_eventEngageLockOn_Parms
	{
		AActor* Target;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_APlayerCharacter_EngageLockOn_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlayerCharacter_eventEngageLockOn_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlayerCharacter_EngageLockOn_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerCharacter_EngageLockOn_Statics::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerCharacter_EngageLockOn_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerCharacter_EngageLockOn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerCharacter, nullptr, "EngageLockOn", nullptr, nullptr, Z_Construct_UFunction_APlayerCharacter_EngageLockOn_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerCharacter_EngageLockOn_Statics::PropPointers), sizeof(Z_Construct_UFunction_APlayerCharacter_EngageLockOn_Statics::PlayerCharacter_eventEngageLockOn_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerCharacter_EngageLockOn_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlayerCharacter_EngageLockOn_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_APlayerCharacter_EngageLockOn_Statics::PlayerCharacter_eventEngageLockOn_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_APlayerCharacter_EngageLockOn()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlayerCharacter_EngageLockOn_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlayerCharacter::execEngageLockOn)
{
	P_GET_OBJECT(AActor,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->EngageLockOn(Z_Param_Target);
	P_NATIVE_END;
}
// End Class APlayerCharacter Function EngageLockOn

// Begin Class APlayerCharacter Function FindNearestTarget
struct Z_Construct_UFunction_APlayerCharacter_FindNearestTarget_Statics
{
	struct PlayerCharacter_eventFindNearestTarget_Parms
	{
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_APlayerCharacter_FindNearestTarget_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlayerCharacter_eventFindNearestTarget_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlayerCharacter_FindNearestTarget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerCharacter_FindNearestTarget_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerCharacter_FindNearestTarget_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerCharacter_FindNearestTarget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerCharacter, nullptr, "FindNearestTarget", nullptr, nullptr, Z_Construct_UFunction_APlayerCharacter_FindNearestTarget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerCharacter_FindNearestTarget_Statics::PropPointers), sizeof(Z_Construct_UFunction_APlayerCharacter_FindNearestTarget_Statics::PlayerCharacter_eventFindNearestTarget_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerCharacter_FindNearestTarget_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlayerCharacter_FindNearestTarget_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_APlayerCharacter_FindNearestTarget_Statics::PlayerCharacter_eventFindNearestTarget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_APlayerCharacter_FindNearestTarget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlayerCharacter_FindNearestTarget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlayerCharacter::execFindNearestTarget)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->FindNearestTarget();
	P_NATIVE_END;
}
// End Class APlayerCharacter Function FindNearestTarget

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

// Begin Class APlayerCharacter Function ScanForTargets
struct Z_Construct_UFunction_APlayerCharacter_ScanForTargets_Statics
{
	struct PlayerCharacter_eventScanForTargets_Parms
	{
		TArray<AActor*> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_APlayerCharacter_ScanForTargets_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_APlayerCharacter_ScanForTargets_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlayerCharacter_eventScanForTargets_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlayerCharacter_ScanForTargets_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerCharacter_ScanForTargets_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerCharacter_ScanForTargets_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerCharacter_ScanForTargets_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerCharacter_ScanForTargets_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerCharacter, nullptr, "ScanForTargets", nullptr, nullptr, Z_Construct_UFunction_APlayerCharacter_ScanForTargets_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerCharacter_ScanForTargets_Statics::PropPointers), sizeof(Z_Construct_UFunction_APlayerCharacter_ScanForTargets_Statics::PlayerCharacter_eventScanForTargets_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerCharacter_ScanForTargets_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlayerCharacter_ScanForTargets_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_APlayerCharacter_ScanForTargets_Statics::PlayerCharacter_eventScanForTargets_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_APlayerCharacter_ScanForTargets()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlayerCharacter_ScanForTargets_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlayerCharacter::execScanForTargets)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<AActor*>*)Z_Param__Result=P_THIS->ScanForTargets();
	P_NATIVE_END;
}
// End Class APlayerCharacter Function ScanForTargets

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

// Begin Class APlayerCharacter Function SwitchLockOnTarget
struct Z_Construct_UFunction_APlayerCharacter_SwitchLockOnTarget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerCharacter_SwitchLockOnTarget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerCharacter, nullptr, "SwitchLockOnTarget", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerCharacter_SwitchLockOnTarget_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlayerCharacter_SwitchLockOnTarget_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_APlayerCharacter_SwitchLockOnTarget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlayerCharacter_SwitchLockOnTarget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlayerCharacter::execSwitchLockOnTarget)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SwitchLockOnTarget();
	P_NATIVE_END;
}
// End Class APlayerCharacter Function SwitchLockOnTarget

// Begin Class APlayerCharacter Function ToggleLockOn
struct Z_Construct_UFunction_APlayerCharacter_ToggleLockOn_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//LOCK ON FUNCTIONS\n" },
#endif
		{ "ModuleRelativePath", "PlayerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "LOCK ON FUNCTIONS" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerCharacter_ToggleLockOn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerCharacter, nullptr, "ToggleLockOn", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerCharacter_ToggleLockOn_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlayerCharacter_ToggleLockOn_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_APlayerCharacter_ToggleLockOn()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlayerCharacter_ToggleLockOn_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlayerCharacter::execToggleLockOn)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ToggleLockOn();
	P_NATIVE_END;
}
// End Class APlayerCharacter Function ToggleLockOn

// Begin Class APlayerCharacter
void APlayerCharacter::StaticRegisterNativesAPlayerCharacter()
{
	UClass* Class = APlayerCharacter::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CancelSprint", &APlayerCharacter::execCancelSprint },
		{ "ChargeHeavyAttack", &APlayerCharacter::execChargeHeavyAttack },
		{ "DisengageLockOn", &APlayerCharacter::execDisengageLockOn },
		{ "Dodge", &APlayerCharacter::execDodge },
		{ "EngageLockOn", &APlayerCharacter::execEngageLockOn },
		{ "FindNearestTarget", &APlayerCharacter::execFindNearestTarget },
		{ "GuardCounterAttack", &APlayerCharacter::execGuardCounterAttack },
		{ "HeavyAttack", &APlayerCharacter::execHeavyAttack },
		{ "IncreaseChargePower", &APlayerCharacter::execIncreaseChargePower },
		{ "Interact", &APlayerCharacter::execInteract },
		{ "ScanForTargets", &APlayerCharacter::execScanForTargets },
		{ "Sprint", &APlayerCharacter::execSprint },
		{ "SprintAttack", &APlayerCharacter::execSprintAttack },
		{ "SwitchLockOnTarget", &APlayerCharacter::execSwitchLockOnTarget },
		{ "ToggleLockOn", &APlayerCharacter::execToggleLockOn },
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToggleLockOnAction_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SwitchLockOnTargetAction_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "PlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractAction_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Input" },
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObjectTypes_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "LockOn" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//LOCKON PROPERTIES\n" },
#endif
		{ "ModuleRelativePath", "PlayerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "LOCKON PROPERTIES" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LockedOnTarget_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "LockOn" },
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HeavyAttacks_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Animations" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//HEAVY ATTACKS\n" },
#endif
		{ "ModuleRelativePath", "PlayerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "HEAVY ATTACKS" },
#endif
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DodgeAction_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "Animations" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//DODGE\n" },
#endif
		{ "ModuleRelativePath", "PlayerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "DODGE" },
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
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HeavyAttackAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SprintAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GuardCounterAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ToggleLockOnAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SwitchLockOnTargetAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InteractAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StaminaComponent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RunningStaminaConsumption;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ObjectTypes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ObjectTypes;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LockedOnTarget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GuardCounter;
	static void NewProp_GuardCounterPossible_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_GuardCounterPossible;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GuardCounterReactionCountdown;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_currentChargePower;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_maxChargePower;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HeavyAttacks_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_HeavyAttacks;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ChargeAttack;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RunningAttack;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DodgeAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InteractAnimation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_APlayerCharacter_CancelSprint, "CancelSprint" }, // 1635053788
		{ &Z_Construct_UFunction_APlayerCharacter_ChargeHeavyAttack, "ChargeHeavyAttack" }, // 1713464993
		{ &Z_Construct_UFunction_APlayerCharacter_DisengageLockOn, "DisengageLockOn" }, // 3897422342
		{ &Z_Construct_UFunction_APlayerCharacter_Dodge, "Dodge" }, // 3111381103
		{ &Z_Construct_UFunction_APlayerCharacter_EngageLockOn, "EngageLockOn" }, // 956507681
		{ &Z_Construct_UFunction_APlayerCharacter_FindNearestTarget, "FindNearestTarget" }, // 172116821
		{ &Z_Construct_UFunction_APlayerCharacter_GuardCounterAttack, "GuardCounterAttack" }, // 1036179294
		{ &Z_Construct_UFunction_APlayerCharacter_HeavyAttack, "HeavyAttack" }, // 171223720
		{ &Z_Construct_UFunction_APlayerCharacter_IncreaseChargePower, "IncreaseChargePower" }, // 2751030947
		{ &Z_Construct_UFunction_APlayerCharacter_Interact, "Interact" }, // 1929792896
		{ &Z_Construct_UFunction_APlayerCharacter_ScanForTargets, "ScanForTargets" }, // 957635959
		{ &Z_Construct_UFunction_APlayerCharacter_Sprint, "Sprint" }, // 2307348509
		{ &Z_Construct_UFunction_APlayerCharacter_SprintAttack, "SprintAttack" }, // 158576561
		{ &Z_Construct_UFunction_APlayerCharacter_SwitchLockOnTarget, "SwitchLockOnTarget" }, // 1139922841
		{ &Z_Construct_UFunction_APlayerCharacter_ToggleLockOn, "ToggleLockOn" }, // 628230847
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
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_ToggleLockOnAction = { "ToggleLockOnAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, ToggleLockOnAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToggleLockOnAction_MetaData), NewProp_ToggleLockOnAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_SwitchLockOnTargetAction = { "SwitchLockOnTargetAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, SwitchLockOnTargetAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SwitchLockOnTargetAction_MetaData), NewProp_SwitchLockOnTargetAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_InteractAction = { "InteractAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, InteractAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractAction_MetaData), NewProp_InteractAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_StaminaComponent = { "StaminaComponent", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, StaminaComponent), Z_Construct_UClass_UStaminaComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StaminaComponent_MetaData), NewProp_StaminaComponent_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_RunningStaminaConsumption = { "RunningStaminaConsumption", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, RunningStaminaConsumption), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RunningStaminaConsumption_MetaData), NewProp_RunningStaminaConsumption_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_ObjectTypes_Inner = { "ObjectTypes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_Engine_EObjectTypeQuery, METADATA_PARAMS(0, nullptr) }; // 1798967895
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_ObjectTypes = { "ObjectTypes", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, ObjectTypes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObjectTypes_MetaData), NewProp_ObjectTypes_MetaData) }; // 1798967895
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_LockedOnTarget = { "LockedOnTarget", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, LockedOnTarget), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LockedOnTarget_MetaData), NewProp_LockedOnTarget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_GuardCounter = { "GuardCounter", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, GuardCounter), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GuardCounter_MetaData), NewProp_GuardCounter_MetaData) };
void Z_Construct_UClass_APlayerCharacter_Statics::NewProp_GuardCounterPossible_SetBit(void* Obj)
{
	((APlayerCharacter*)Obj)->GuardCounterPossible = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_GuardCounterPossible = { "GuardCounterPossible", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(APlayerCharacter), &Z_Construct_UClass_APlayerCharacter_Statics::NewProp_GuardCounterPossible_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GuardCounterPossible_MetaData), NewProp_GuardCounterPossible_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_GuardCounterReactionCountdown = { "GuardCounterReactionCountdown", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, GuardCounterReactionCountdown), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GuardCounterReactionCountdown_MetaData), NewProp_GuardCounterReactionCountdown_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_currentChargePower = { "currentChargePower", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, currentChargePower), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_currentChargePower_MetaData), NewProp_currentChargePower_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_maxChargePower = { "maxChargePower", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, maxChargePower), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_maxChargePower_MetaData), NewProp_maxChargePower_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_HeavyAttacks_Inner = { "HeavyAttacks", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_HeavyAttacks = { "HeavyAttacks", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, HeavyAttacks), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HeavyAttacks_MetaData), NewProp_HeavyAttacks_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_ChargeAttack = { "ChargeAttack", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, ChargeAttack), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChargeAttack_MetaData), NewProp_ChargeAttack_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_RunningAttack = { "RunningAttack", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, RunningAttack), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RunningAttack_MetaData), NewProp_RunningAttack_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_DodgeAction = { "DodgeAction", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, DodgeAction), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DodgeAction_MetaData), NewProp_DodgeAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerCharacter_Statics::NewProp_InteractAnimation = { "InteractAnimation", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter, InteractAnimation), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractAnimation_MetaData), NewProp_InteractAnimation_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APlayerCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_HeavyAttackAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_SprintAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_GuardCounterAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_ToggleLockOnAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_SwitchLockOnTargetAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_InteractAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_StaminaComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_RunningStaminaConsumption,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_ObjectTypes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_ObjectTypes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_LockedOnTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_GuardCounter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_GuardCounterPossible,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_GuardCounterReactionCountdown,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_currentChargePower,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_maxChargePower,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_HeavyAttacks_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_HeavyAttacks,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_ChargeAttack,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_RunningAttack,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_DodgeAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Statics::NewProp_InteractAnimation,
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
		{ Z_Construct_UClass_APlayerCharacter, APlayerCharacter::StaticClass, TEXT("APlayerCharacter"), &Z_Registration_Info_UClass_APlayerCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APlayerCharacter), 4069850031U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Repository_Eternal_Grace_Arena_Eternal_Grace_Arena_Source_Eternal_Grace_Arena_PlayerCharacter_h_3226433714(TEXT("/Script/Eternal_Grace_Arena"),
	Z_CompiledInDeferFile_FID_Repository_Eternal_Grace_Arena_Eternal_Grace_Arena_Source_Eternal_Grace_Arena_PlayerCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Repository_Eternal_Grace_Arena_Eternal_Grace_Arena_Source_Eternal_Grace_Arena_PlayerCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
