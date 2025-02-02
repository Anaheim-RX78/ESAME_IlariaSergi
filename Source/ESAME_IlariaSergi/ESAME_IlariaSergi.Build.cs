// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ESAME_IlariaSergi : ModuleRules
{
	public ESAME_IlariaSergi(ReadOnlyTargetRules Target) : base(Target)
	{
		PrivateDependencyModuleNames.AddRange(new string[] { "AITestSuite" });
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
