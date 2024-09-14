// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Ingrained_Sandbox : ModuleRules
{
	public Ingrained_Sandbox(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
