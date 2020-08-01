// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

using System;
using System.IO;
using UnrealBuildTool;

public class modio : ModuleRules
{
	private String modio_directory = "mod.io-sdk";

	private string ModulePath
	{
		get { return ModuleDirectory; }
	}

	private string ProjectPath
	{
		get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "..", "..", "..", "..")); }
	}
	
	private string ThirdPartyPath
	{
		get { return Path.GetFullPath(Path.Combine(ModulePath, "../../Source/ThirdParty/")); }
	}

	public modio(ReadOnlyTargetRules Target) : base(Target)
	{
		PublicDefinitions.Add("JSON_NOEXCEPTION");
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		// For beeing able to declare something public inside of the module, but private to outsiders
		PrivateDefinitions.Add( "MODIO_PACKAGE=1" );

		PrivateDependencyModuleNames.AddRange(new string[] { });

		LoadModio(Target);

		bEnableExceptions = true;
		// Made sure to disable unity builds, as exclusion of some files causes the project to explode
		// this was we atleast get deterministic builds even if they are slower
		MinSourceFilesForUnityBuildOverride = 256;
		
		PublicIncludePaths.AddRange(
			new string[] {
				//"modio/Public"
				/*,
				"Runtime/Core/Public/Modules/",
				"Editor/UnrealEd/Classes/Factories",
				"Editor/UnrealEd/Classes",
				"C:/Users/antar/Documents/Unreal Projects/ModioContainer21/Plugins/modio/Intermediate/Build/Win64/UE4Editor/Inc/modio",
				"C:/Program Files/Epic Games/UE_4.21/Engine/Intermediate/Build/Win64/UE4Editor/Inc/UnrealEd"
				*/
				// ... add public include paths required here ...
			}
			);
		
		PrivateIncludePaths.AddRange(
			new string[] {
				//"modio/Private",
				// ... add other private include paths required here ...
			}
			);
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"InputCore",
				"Projects",
				"Int64"
				// ... add other public dependencies that you statically link with here ...
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

	public bool LoadModio(ReadOnlyTargetRules Target)
	{
		bool isLibrarySupported = false;
		if ((Target.Platform == UnrealTargetPlatform.Win64) || (Target.Platform == UnrealTargetPlatform.Win32))
		{
			PublicDefinitions.Add("MODIO_UE4_WINDOWS_BUILD");

			isLibrarySupported = true;
			
			string LibrariesPath = Path.Combine(ThirdPartyPath, modio_directory, "lib", "win64");
			string DLLPath = Path.Combine(ThirdPartyPath, modio_directory, "bin", "win64");

#if UE_4_24_OR_LATER
			PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "modio.lib"));
#else
			PublicLibraryPaths.Add(LibrariesPath);
			PublicAdditionalLibraries.Add("modio");
#endif
			RuntimeDependencies.Add(Path.Combine(DLLPath, "modio.dll"));

			string ProjectBinariesDirectory = Path.Combine(ProjectPath, "Binaries", "Win64");
			if (!Directory.Exists(ProjectBinariesDirectory))
				System.IO.Directory.CreateDirectory(ProjectBinariesDirectory);
			
			string ModioDLLDestination = System.IO.Path.Combine(ProjectBinariesDirectory, "modio.dll");
			CopyFile(Path.Combine(DLLPath, "modio.dll"), ModioDLLDestination);
			PublicDelayLoadDLLs.AddRange(new string[] { "modio.dll" });
		}

		if (Target.Platform == UnrealTargetPlatform.Linux)
		{
			PublicDefinitions.Add("MODIO_UE4_LINUX_BUILD");

			isLibrarySupported = true;

			string LibrariesPath = Path.Combine(ThirdPartyPath, modio_directory, "lib", "linux-x64");

#if UE_4_24_OR_LATER
			PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "modio.lib"));
#else
			PublicLibraryPaths.Add(LibrariesPath);
			PublicAdditionalLibraries.Add("modio");
#endif

			string ProjectBinariesDirectory = Path.Combine(ProjectPath, "Binaries", "Linux");
			if (!Directory.Exists(ProjectBinariesDirectory))
				System.IO.Directory.CreateDirectory(ProjectBinariesDirectory);
		}

		if (Target.Platform == UnrealTargetPlatform.Mac)
		{
			PublicDefinitions.Add("MODIO_UE4_MAC_BUILD");

			isLibrarySupported = true;

			string LibrariesPath = Path.Combine(ThirdPartyPath, modio_directory, "lib", "macOS-x64");

#if UE_4_24_OR_LATER
			PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "modio.lib"));
#else
			PublicLibraryPaths.Add(LibrariesPath);
			PublicAdditionalLibraries.Add("modio");
#endif

			string ProjectBinariesDirectory = Path.Combine(ProjectPath, "Binaries", "Mac");
			if (!Directory.Exists(ProjectBinariesDirectory))
				System.IO.Directory.CreateDirectory(ProjectBinariesDirectory);
		}
		
		if (isLibrarySupported)
		{
			string ModioIncludePath = Path.Combine(ThirdPartyPath, modio_directory, "include");
			string AdditionalDependenciesPath = Path.Combine(ThirdPartyPath, modio_directory, "additional_dependencies");
			PublicIncludePaths.Add(ModioIncludePath);
			PublicIncludePaths.Add(AdditionalDependenciesPath);
		}
		
		return isLibrarySupported;
	}

	private void CopyFile(string source, string dest)
	{
		System.Console.WriteLine("Copying {0} to {1}", source, dest);
		if (System.IO.File.Exists(dest))
		{
			System.IO.File.SetAttributes(dest, System.IO.File.GetAttributes(dest) & ~System.IO.FileAttributes.ReadOnly);
		}
		try
		{
			System.IO.File.Copy(source, dest, true);
		}
		catch (System.Exception ex)
		{
			System.Console.WriteLine("Failed to copy file: {0}", ex.Message);
		}
	}
}
