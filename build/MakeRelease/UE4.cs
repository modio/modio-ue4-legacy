using System;
using System.Collections.Generic;
using System.Configuration;
using System.Text;

namespace MakeRelease
{
	class UE4InstallInfo
	{
		public string InstallLocation { get; set; }
		public string AppName { get; set; }
		public string AppVersion { get; set; }
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

		public static string GetPlatformString()
		{
			if (Platform.IsWindows())
			{
				return "Win64";
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

		static public List<Install> GetRequiredUE4Installs()
		{
			if (RequiredUE4Installs == null)
			{
				RequiredUE4Installs = ConfigurationManager.GetSection("RequiredUE4Installs") as List<Install>;
			}

			return RequiredUE4Installs;
		}
	}
}
