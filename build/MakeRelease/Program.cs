using System;
using System.Collections.Generic;
using System.IO;
using CommandLine;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.IO.Compression;

namespace MakeRelease
{
	class Program
	{
		static int StaticResult = -1;

		static string GetUATPath( UE4InstallInfo Install )
		{
			string TemplateUATPath = @"{0}/Engine/Build/BatchFiles/RunUAT.{1}";

			return string.Format(TemplateUATPath,
				Install.InstallLocation,
				Platform.IsWindows() ? "bat" : "sh");
		}

		static string BuildPluginForInstall(UE4InstallInfo Install)
		{
			string InstallDirectory = String.Format(@"{0}/PluginStaging_ALL/modio_UE4_{1}",
				Directory.GetCurrentDirectory(),
				Install.AppName);

			string BuildTemplate = @"BuildPlugin -Plugin={0}/../modio.uplugin -TargetPlatforms={1} -Package={2} -Rocket";

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
			Filesystem.SafeDeleteDirectory(PluginDirectory + "/Binaries", true);
			Filesystem.SafeDeleteDirectory(PluginDirectory + "/img", true);
			Filesystem.SafeDeleteDirectory(PluginDirectory + "/Intermediate", true);
		}

		static void AddConfigFiles(string PluginDirectory)
		{
			Filesystem.DirectoryCopy(@"../Config/", PluginDirectory + @"/Config/", true);
		}

		protected static void Cleanup()
		{
			// Kill any running process we might have
			if (Process.RunningProcess != null)
			{
				Process.RunningProcess.Kill();
			}
		}

		static int Main(string[] args)
		{
			// Register the handler
			MakeRelease.Process.AddCleanupHandler(Cleanup);
			Environment.CurrentDirectory = "../../../";

			Parser.Default.ParseArguments<Options>(args)
				.WithParsed(RunOptions)
				.WithNotParsed(HandleParseError);

			return StaticResult;
		}

		static void HandleParseError(IEnumerable<Error> Errors)
		{
			StaticResult = -1;
		}

		static void SetupClean()
		{
			Filesystem.SafeDeleteDirectory( Environment.CurrentDirectory + "/PluginStaging_ALL", true);
		}

		static void RunOptions(Options Opts)
		{
			SetupClean();

			foreach (UE4InstallInfo Install in UE4.GetRequiredVersionList().InstallationList)
			{
				string DestinationDirectory = BuildPluginForInstall(Install);
				CleanupInstallDirectory(DestinationDirectory);
				AddConfigFiles(DestinationDirectory);
				CompressPlugin(Install, DestinationDirectory, Opts.UE4PluginVersion);
			}

			StaticResult = 0;
		}

		static void CompressPlugin(UE4InstallInfo Install, string PluginDirectory, string PluginVersion)
		{
			Filesystem.SafeCreateDirectory("tmp");
			Filesystem.DirectoryCopy(PluginDirectory, "tmp/modio", true);

			ZipFile.CreateFromDirectory("tmp/modio", string.Format("PluginStaging_ALL/modio-{0}-{1}.zip",
				PluginVersion,
				Install.GetCleanAppName())
			);

			Directory.Delete("tmp", true);
		}
	}
}
