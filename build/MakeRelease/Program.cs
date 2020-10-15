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
		// As the entire program is static, we need to to store the result in a static variable
		static int StaticResult = -1;

		/** Get the path to UAT depending on what UE4 version we are aiming for */
		static string GetUATPath( UE4InstallInfo Install )
		{
			string TemplateUATPath = @"{0}/Engine/Build/BatchFiles/RunUAT.{1}";

			return string.Format(TemplateUATPath,
				Install.InstallLocation,
				Platform.IsWindows() ? "bat" : "sh");
		}

		/** Build the plugin for a specific UE4 install */
		static string BuildPluginForInstall(UE4InstallInfo Install)
		{
			string InstallDirectory = String.Format(@"{0}/PluginStaging_ALL/modio_UE4_{1}",
				Directory.GetCurrentDirectory(),
				Install.AppName);

			string BuildTemplate = @"BuildPlugin -Plugin={0}/../modio.uplugin -TargetPlatforms={1} -Package={2} -Rocket";

			if (!Process.RunCommand( GetUATPath(Install),
								String.Format(BuildTemplate,
									Directory.GetCurrentDirectory(),
									UE4.GetPlatformBuildString(),
									InstallDirectory),
								Install.AppName
							)
				)
			{
				throw new System.ApplicationException("Failed to build the plugin for installation " + Install.AppName + " of UE4");
			}

			return InstallDirectory;
		}

		/** After the plugin has been built, cleanup the output directory so we only have the desired files */
		static void CleanupInstallDirectory(string PluginDirectory)
		{
			Filesystem.SafeDeleteDirectory(PluginDirectory + "/Binaries", true);
			Filesystem.SafeDeleteDirectory(PluginDirectory + "/img", true);
			Filesystem.SafeDeleteDirectory(PluginDirectory + "/Intermediate", true);
		}

		/** Add the config to the plugin as we has redistrubuted this config directory with each plugin */
		static void AddConfigFiles(string PluginDirectory)
		{
			Filesystem.DirectoryCopy(@"../Config/", PluginDirectory + @"/Config/", true);
		}

		/** Called when someone closes the window, terminate any running processes we have so that we can run the tool again easier */
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
			Stopwatch Timer = new Stopwatch();
			Timer.Start();

			// Register the handler
			MakeRelease.Process.AddCleanupHandler(Cleanup);
			Environment.CurrentDirectory = "../../../";

			Parser.Default.ParseArguments<Options>(args)
				.WithParsed(RunWithOptions)
				.WithNotParsed(IncorrectArugmentsSupplied);

			Timer.Stop();
			Console.WriteLine(string.Format("{0}: Took: {1:00}min {2:0.##}s",
				StaticResult == 0 ? "SUCCESS" : "FAILURE",
				Timer.Elapsed.TotalMinutes,
				Timer.Elapsed.TotalSeconds -  Math.Floor(Timer.Elapsed.TotalMinutes) * 60.0f)
			); ;

			return StaticResult;
		}

		static void IncorrectArugmentsSupplied(IEnumerable<Error> Errors)
		{
			// Terminate with error code
			StaticResult = -1;
		}

		/** Cleanup the output directory so that we start with a clean output directory */
		static void SetupClean()
		{
			Filesystem.SafeDeleteDirectory( Environment.CurrentDirectory + "/PluginStaging_ALL", true);
		}

		/** Basically a main with parsed options */
		static void RunWithOptions(Options Opts)
		{
			SetupClean();

			foreach (UE4InstallInfo Install in UE4.GetRequiredVersionList().InstallationList)
			{
				PlatformSetup(Install);
				
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
			// We have no need of the plugin directory after this
			Directory.Delete(PluginDirectory, true);
		}

		/// <summary>
        /// Platform specific code depending on what platform we currently are running
        /// </summary>
		static void PlatformSetup(UE4InstallInfo Install)
		{
			// @todo: Next instance we need to check for the platform, make a platform object that we can use to
			// move the platform specific code in a specific object
			// On windows, we compile linux so need to ensure that the environment is properly setup
			if (Platform.IsWindows())
			{
				// Ensure that we are using the correct clang version for each engine install
				Environment.SetEnvironmentVariable("LINUX_MULTIARCH_ROOT", Install.Metadata.ClangInstallPath, EnvironmentVariableTarget.Process);
			}
			// On OS X, we require different Xcode-versions to compile all versions. Switch X-code version depending
			// on the current UE4 version
			if (Platform.IsMacOS())
			{
				Filesystem.SafeDeleteDirectory("/Applications/Xcode.app", true);
				Filesystem.CreateSymbolicLink(Install.Metadata.XCodeInstallPath, "/Applications/Xcode.app");
			}
		}
	}
}
