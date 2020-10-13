using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.IO;
using CommandLine;

namespace MakeRelease
{
	class Program
	{
		static UE4Installs InstalledVersions = null;

		static UE4Installs RequiredUE4Versions = null;

		static int StaticResult = -1;

		static string GetUATPath( UE4InstallInfo Install )
		{
			return Install.InstallLocation + @"/Engine/Build/BatchFiles/RunUAT.bat";
		}

		static private UE4Installs GetInstalledLauncherVersions()
		{
			if (InstalledVersions == null)
			{
				// On windows, this path is to where to know what installed engine versions are installed
				string Path = Environment.GetFolderPath(Environment.SpecialFolder.CommonApplicationData) + "/Epic/UnrealEngineLauncher/LauncherInstalled.dat";
				if (!File.Exists(Path))
				{
					throw new System.ApplicationException("Can't find installed launcher file, please install at least on UE4 engine before running this script");
				}

				InstalledVersions = JsonConvert.DeserializeObject<UE4Installs>(File.ReadAllText(Path));
			}

			return InstalledVersions;
		}

		static private UE4Installs GetRequiredVersionList()
		{
			if(RequiredUE4Versions == null )
			{
				RequiredUE4Versions = new UE4Installs();
				foreach (Install RequiredInstall in UE4.GetRequiredUE4Installs())
				{
					UE4InstallInfo Installation = GetInstalledLauncherVersions().InstallationList.Find(InstalledVersion => InstalledVersion.AppName == "UE_" + RequiredInstall.Version);
					if (Installation == null)
					{
						throw new System.ApplicationException("You don't have the required version " + RequiredInstall.Version + " of UE4 installed");
					}

					RequiredUE4Versions.InstallationList.Add(Installation);
				}
			}

			return RequiredUE4Versions;
		}

		static string BuildPluginForInstall(UE4InstallInfo Install)
		{
			string InstallDirectory = String.Format(@"{0}/PluginStaging_ALL/modio_UE4_{1}",
				Directory.GetCurrentDirectory(),
				Install.AppName);

			string BuildTemplate = @"BuildPlugin -Plugin={0}\..\modio.uplugin -TargetPlatforms={1} -Package={2} -Rocket";

			if (!Process.RunCommand( GetUATPath(Install),
								String.Format(BuildTemplate,
									Directory.GetCurrentDirectory(),
									UE4.GetPlatformString(),
									InstallDirectory),
								Install.AppName
							)
				)
			{
				throw new System.ApplicationException("Failed to build the plugin for installation " + Install.AppName + " of UE4");
			}

			return InstallDirectory;
		}

		static void CleanupInstallDirectory(string PluginDirectory)
		{
			SafeDeleteDirectory(PluginDirectory + "/Binaries", true);
			SafeDeleteDirectory(PluginDirectory + "/img", true);
			SafeDeleteDirectory(PluginDirectory + "/Intermediate", true);
		}

		static void AddConfigFiles(string PluginDirectory)
		{
			Filesystem.DirectoryCopy(@"../Config/", PluginDirectory + @"/Config/", true);
		}

		static int Main(string[] args)
		{
			Parser.Default.ParseArguments<Options>(args)
				.WithParsed(RunOptions)
				.WithNotParsed(HandleParseError);

			return StaticResult;
		}

		static void HandleParseError(IEnumerable<Error> Errors)
		{
			StaticResult = -1;
		}

		static void RunOptions(Options Opts)
		{
			foreach (UE4InstallInfo Install in GetRequiredVersionList().InstallationList)
			{
				string DestinationDirectory = BuildPluginForInstall(Install);
				CleanupInstallDirectory(DestinationDirectory);
				AddConfigFiles(DestinationDirectory);
				CompressPlugin(DestinationDirectory, Opts.UE4PluginVersion);
			}

			StaticResult = 0;
		}

		static void CompressPlugin(string PluginDirectory, string PluginVersion)
		{

		}

		private static void SafeDeleteDirectory(string DirectoryToDelete, bool Recursive)
		{
			if (Directory.Exists(DirectoryToDelete))
			{
				Directory.Delete(DirectoryToDelete, Recursive);
			}
		}
	}
}
