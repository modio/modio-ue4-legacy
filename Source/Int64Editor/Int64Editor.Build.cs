// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

using System;
using System.IO;
using UnrealBuildTool;

public class Int64Editor : ModuleRules
{
	public Int64Editor( ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		bEnforceIWYU = true;

		PublicIncludePaths.AddRange(
			new string[]
			{
			}
		);
		
		PrivateIncludePaths.AddRange(
			new string[]
			{
			}
		);
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"Int64",
				"PropertyEditor",
				"SlateCore",
				"Slate"
			}
		);
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				// ... add private dependencies that you statically link with here ...	
			}
		);
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
		);
	}
}
