// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Eternal_Grace_Arena : ModuleRules
{
	public Eternal_Grace_Arena(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
		//ICH SOLLTE NOCHMAL RECHERCHIEREN WIESO ICH DAS HIER EINFÜGEN MUSS
		PrivateDependencyModuleNames.AddRange(new string[] { "GameplayAbilities", "GameplayTags", "GameplayTasks" });
	}
}
