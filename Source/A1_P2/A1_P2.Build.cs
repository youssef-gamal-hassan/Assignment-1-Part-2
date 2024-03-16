// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class A1_P2 : ModuleRules
{
	public A1_P2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
