// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEternal_Grace_Arena_init() {}
	ETERNAL_GRACE_ARENA_API UFunction* Z_Construct_UDelegateFunction_Eternal_Grace_Arena_OnPlayerDied__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Eternal_Grace_Arena;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Eternal_Grace_Arena()
	{
		if (!Z_Registration_Info_UPackage__Script_Eternal_Grace_Arena.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_Eternal_Grace_Arena_OnPlayerDied__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Eternal_Grace_Arena",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x146AD1A1,
				0x6C949E3E,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Eternal_Grace_Arena.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Eternal_Grace_Arena.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Eternal_Grace_Arena(Z_Construct_UPackage__Script_Eternal_Grace_Arena, TEXT("/Script/Eternal_Grace_Arena"), Z_Registration_Info_UPackage__Script_Eternal_Grace_Arena, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x146AD1A1, 0x6C949E3E));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
