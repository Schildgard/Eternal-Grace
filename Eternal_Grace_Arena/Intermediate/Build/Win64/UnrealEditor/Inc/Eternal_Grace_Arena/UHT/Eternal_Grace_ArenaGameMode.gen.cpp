// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Eternal_Grace_Arena/Eternal_Grace_ArenaGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEternal_Grace_ArenaGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
ETERNAL_GRACE_ARENA_API UClass* Z_Construct_UClass_AEternal_Grace_ArenaGameMode();
ETERNAL_GRACE_ARENA_API UClass* Z_Construct_UClass_AEternal_Grace_ArenaGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_Eternal_Grace_Arena();
// End Cross Module References

// Begin Class AEternal_Grace_ArenaGameMode
void AEternal_Grace_ArenaGameMode::StaticRegisterNativesAEternal_Grace_ArenaGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEternal_Grace_ArenaGameMode);
UClass* Z_Construct_UClass_AEternal_Grace_ArenaGameMode_NoRegister()
{
	return AEternal_Grace_ArenaGameMode::StaticClass();
}
struct Z_Construct_UClass_AEternal_Grace_ArenaGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Eternal_Grace_ArenaGameMode.h" },
		{ "ModuleRelativePath", "Eternal_Grace_ArenaGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEternal_Grace_ArenaGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AEternal_Grace_ArenaGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Eternal_Grace_Arena,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEternal_Grace_ArenaGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEternal_Grace_ArenaGameMode_Statics::ClassParams = {
	&AEternal_Grace_ArenaGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEternal_Grace_ArenaGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AEternal_Grace_ArenaGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEternal_Grace_ArenaGameMode()
{
	if (!Z_Registration_Info_UClass_AEternal_Grace_ArenaGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEternal_Grace_ArenaGameMode.OuterSingleton, Z_Construct_UClass_AEternal_Grace_ArenaGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEternal_Grace_ArenaGameMode.OuterSingleton;
}
template<> ETERNAL_GRACE_ARENA_API UClass* StaticClass<AEternal_Grace_ArenaGameMode>()
{
	return AEternal_Grace_ArenaGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEternal_Grace_ArenaGameMode);
AEternal_Grace_ArenaGameMode::~AEternal_Grace_ArenaGameMode() {}
// End Class AEternal_Grace_ArenaGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Repository_Eternal_Grace_Arena_Eternal_Grace_Arena_Source_Eternal_Grace_Arena_Eternal_Grace_ArenaGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEternal_Grace_ArenaGameMode, AEternal_Grace_ArenaGameMode::StaticClass, TEXT("AEternal_Grace_ArenaGameMode"), &Z_Registration_Info_UClass_AEternal_Grace_ArenaGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEternal_Grace_ArenaGameMode), 628428886U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Repository_Eternal_Grace_Arena_Eternal_Grace_Arena_Source_Eternal_Grace_Arena_Eternal_Grace_ArenaGameMode_h_774202538(TEXT("/Script/Eternal_Grace_Arena"),
	Z_CompiledInDeferFile_FID_Repository_Eternal_Grace_Arena_Eternal_Grace_Arena_Source_Eternal_Grace_Arena_Eternal_Grace_ArenaGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Repository_Eternal_Grace_Arena_Eternal_Grace_Arena_Source_Eternal_Grace_Arena_Eternal_Grace_ArenaGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
