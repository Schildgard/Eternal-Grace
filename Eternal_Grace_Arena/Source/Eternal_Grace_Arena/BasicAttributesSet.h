// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BasicAttributesSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName)\
    GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName)\
    GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName)\
    GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName)\
    GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class ETERNAL_GRACE_ARENA_API UBasicAttributesSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UBasicAttributesSet();

public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess))
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UBasicAttributesSet, Health)
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess))
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UBasicAttributesSet, MaxHealth)
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess))
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UBasicAttributesSet, Stamina)
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess))
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UBasicAttributesSet, MaxStamina)


};
