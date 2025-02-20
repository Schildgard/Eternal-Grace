// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Eternal_Grace_ArenaCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UAnimMontage;
class UStatusEffectComponent;
#ifdef ETERNAL_GRACE_ARENA_Eternal_Grace_ArenaCharacter_generated_h
#error "Eternal_Grace_ArenaCharacter.generated.h already included, missing '#pragma once' in Eternal_Grace_ArenaCharacter.h"
#endif
#define ETERNAL_GRACE_ARENA_Eternal_Grace_ArenaCharacter_generated_h

#define FID_Repository_Eternal_Grace_Arena_Eternal_Grace_Arena_Source_Eternal_Grace_Arena_Eternal_Grace_ArenaCharacter_h_23_DELEGATE \
ETERNAL_GRACE_ARENA_API void FOnCharacterDeath_DelegateWrapper(const FMulticastScriptDelegate& OnCharacterDeath);


#define FID_Repository_Eternal_Grace_Arena_Eternal_Grace_Arena_Source_Eternal_Grace_Arena_Eternal_Grace_ArenaCharacter_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execQuitAttack); \
	DECLARE_FUNCTION(execRotateTowardsTarget); \
	DECLARE_FUNCTION(execGetStatusEffectComponent); \
	DECLARE_FUNCTION(execCancelGuard); \
	DECLARE_FUNCTION(execGuard); \
	DECLARE_FUNCTION(execLightAttack); \
	DECLARE_FUNCTION(execSetAttackStatus);


#define FID_Repository_Eternal_Grace_Arena_Eternal_Grace_Arena_Source_Eternal_Grace_Arena_Eternal_Grace_ArenaCharacter_h_29_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEternal_Grace_ArenaCharacter(); \
	friend struct Z_Construct_UClass_AEternal_Grace_ArenaCharacter_Statics; \
public: \
	DECLARE_CLASS(AEternal_Grace_ArenaCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Eternal_Grace_Arena"), NO_API) \
	DECLARE_SERIALIZER(AEternal_Grace_ArenaCharacter) \
	virtual UObject* _getUObject() const override { return const_cast<AEternal_Grace_ArenaCharacter*>(this); }


#define FID_Repository_Eternal_Grace_Arena_Eternal_Grace_Arena_Source_Eternal_Grace_Arena_Eternal_Grace_ArenaCharacter_h_29_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AEternal_Grace_ArenaCharacter(AEternal_Grace_ArenaCharacter&&); \
	AEternal_Grace_ArenaCharacter(const AEternal_Grace_ArenaCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEternal_Grace_ArenaCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEternal_Grace_ArenaCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEternal_Grace_ArenaCharacter) \
	NO_API virtual ~AEternal_Grace_ArenaCharacter();


#define FID_Repository_Eternal_Grace_Arena_Eternal_Grace_Arena_Source_Eternal_Grace_Arena_Eternal_Grace_ArenaCharacter_h_26_PROLOG
#define FID_Repository_Eternal_Grace_Arena_Eternal_Grace_Arena_Source_Eternal_Grace_Arena_Eternal_Grace_ArenaCharacter_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Repository_Eternal_Grace_Arena_Eternal_Grace_Arena_Source_Eternal_Grace_Arena_Eternal_Grace_ArenaCharacter_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Repository_Eternal_Grace_Arena_Eternal_Grace_Arena_Source_Eternal_Grace_Arena_Eternal_Grace_ArenaCharacter_h_29_INCLASS_NO_PURE_DECLS \
	FID_Repository_Eternal_Grace_Arena_Eternal_Grace_Arena_Source_Eternal_Grace_Arena_Eternal_Grace_ArenaCharacter_h_29_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ETERNAL_GRACE_ARENA_API UClass* StaticClass<class AEternal_Grace_ArenaCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Repository_Eternal_Grace_Arena_Eternal_Grace_Arena_Source_Eternal_Grace_Arena_Eternal_Grace_ArenaCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
