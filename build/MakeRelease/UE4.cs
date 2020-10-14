using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.IO;
using System.Text;

namespace MakeRelease
{
	class UE4InstallInfo
	{
		public string InstallLocation { get; set; }
		public string AppName { get; set; }
		public string AppVersion { get; set; }

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
		private static List<Install> RequiredUE4Installs = null;

		private static UE4Installs InstalledVersions = null;

		private static UE4Installs RequiredUE4Versions = null;

		public static string GetPlatformString()
		{
			if (Platform.IsWindows())
			{
				// This might look wrong, but it's actually correct, sending in Linux also compiles Win64 binaries so we can see that both Win64 and Linux works by using this
				return "Linux";
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

		static public UE4Installs GetRequiredVersionList()
		{
			if (RequiredUE4Versions == null)
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
		static private List<Install> GetRequiredUE4Installs()
		{
			if (RequiredUE4Installs == null)
			{
				RequiredUE4Installs = ConfigurationManager.GetSection("RequiredUE4Installs") as List<Install>;
			}

			return RequiredUE4Installs;
		}
	}
}
