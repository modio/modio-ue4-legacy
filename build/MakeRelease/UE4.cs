using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.IO;
using System.Text;

namespace MakeRelease
{
	/// <summary>
	/// Information about a unreal install
	/// </summary>
	class UE4InstallInfo
	{
		/// <summary>
		/// From LauncherInstalled.dat
		/// </summary>
		public string InstallLocation { get; set; }

		/// <summary>
		/// From LauncherInstalled.dat
		/// </summary>
		public string AppName { get; set; }

		/// <summary>
		/// From LauncherInstalled.dat
		/// </summary>
		public string AppVersion { get; set; }

		/// <summary>
		/// Extra metadata associated with the install. Specified in App.config
		/// </summary>
		public InstallMetadata Metadata { get; set; }

		/// <summary>
		/// Get the clean version name
		/// </summary>
		/// <returns></returns>
		public string GetCleanAppName() 
		{
			return AppName.ToLower().Replace("_", "").Replace(".", "");
		}
	};

	class UE4Installs
	{
		public UE4Installs()
		{
			InstallationList = new List<UE4InstallInfo>();
		}

		public List<UE4InstallInfo> InstallationList { get; set; }
	};
	class UE4
	{
		private static List<InstallMetadata> RequiredUE4Installs = null;

		private static UE4Installs InstalledVersions = null;

		private static UE4Installs RequiredUE4Versions = null;

		/// <summary>
		/// What platforms do we want to compile when running on a specific platform
		/// </summary>
		/// <returns></returns>
		public static string GetPlatformBuildString()
		{
			if (Platform.IsWindows())
			{
				// We want to build both Linux and Windows when running on Windows, so we can verify that the linux version compiles on windows
				return "Linux+Win64";
			}
			if (Platform.IsMacOS())
			{
				return "Mac";
			}
			if (Platform.IsLinux())
			{
				return "Linux";
			}

			throw new System.ApplicationException("Running the tool on a unknown platform");
		}

		/// <summary>
		/// Mirrors FPlatformProcess::ApplicationSettingsDir from UE4 source code
		/// </summary>
		/// <returns></returns>
		static public string GetApplicationSettingsDir()
		{
			if (Platform.IsWindows())
			{
				return Environment.GetFolderPath(Environment.SpecialFolder.CommonApplicationData);
			}
			if (Platform.IsMacOS())
			{
				return "/Users/" + Environment.UserName + "/Library/Application Support";
			}

			throw new System.ApplicationException("Unknown platform trying to aquire Application Settings Dir");
		}

		/// <summary>
		/// Finds and caches all installed UE4 version that's installed from the Epic Games Launcher
		/// </summary>
		/// <returns></returns>
		static public UE4Installs GetInstalledLauncherVersions()
		{
			if (InstalledVersions == null)
			{
				// On windows, this path is to where to know what installed engine versions are installed
				string Path = GetApplicationSettingsDir() + "/Epic/UnrealEngineLauncher/LauncherInstalled.dat";
				if (!File.Exists(Path))
				{
					throw new System.ApplicationException("Can't find installed launcher file, please install at least on UE4 engine before running this script");
				}

				InstalledVersions = JsonConvert.DeserializeObject<UE4Installs>(File.ReadAllText(Path));
			}

			return InstalledVersions;
		}

		/// <summary>
		/// Get all of our required UE4 version (that we want to support on the marketplace) and populate them with the metadata from our config file
		/// </summary>
		/// <returns></returns>
		static public UE4Installs GetRequiredVersionList()
		{
			if (RequiredUE4Versions == null)
			{
				RequiredUE4Versions = new UE4Installs();
				foreach (InstallMetadata RequiredInstall in UE4.GetRequiredUE4Installs())
				{
					UE4InstallInfo Installation = GetInstalledLauncherVersions().InstallationList.Find(InstalledVersion => InstalledVersion.AppName == "UE_" + RequiredInstall.Version);
					if (Installation == null)
					{
						throw new System.ApplicationException("You don't have the required version " + RequiredInstall.Version + " of UE4 installed");
					}

					Installation.Metadata = RequiredInstall;
					RequiredUE4Versions.InstallationList.Add(Installation);
				}
			}

			return RequiredUE4Versions;
		}

		/// <summary>
		/// All required (supported) ue 4 versions
		/// </summary>
		/// <returns></returns>
		static private List<InstallMetadata> GetRequiredUE4Installs()
		{
			if (RequiredUE4Installs == null)
			{
				RequiredUE4Installs = ConfigurationManager.GetSection("RequiredUE4Installs") as List<InstallMetadata>;
			}

			return RequiredUE4Installs;
		}
	}
}
