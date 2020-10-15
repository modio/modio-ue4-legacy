using System;
using System.Collections.Generic;
using System.Text;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace MakeRelease
{
	public class Process
	{
		// The running process we have started. We currently only support a single running process at the time
		public static System.Diagnostics.Process RunningProcess = null;

		public delegate void CleanupDelegate();

		private static CleanupDelegate Cleanup;

		/** Get you a callback when the application is terminated in some way to be able to add some cleanup code  */
		public static void AddCleanupHandler(CleanupDelegate Del)
		{
			Cleanup = Del;
			if (Platform.IsWindows())
			{
				SetConsoleCtrlHandler(WindowsHandler, true);
			}
			else
			{
				// On Mac/Linux we will only catch a ctrl-c event
                Console.CancelKeyPress += CallCleanupMacLinux;
			}
		}

		/// <summary>
		/// Run a bat/sh file
		/// </summary>
		/// <param name="Executable">Path to the bat/sh file</param>
		/// <param name="Arguments">Arguments to the bat/sh file</param>
		/// <param name="Tag">
		/// Optional tag to write in the log before output, eg., if you pass "Build", then output will look like this:
		/// "Build> Output from build tool"
		/// </param>
		/// <returns>True if the process returns a 0 error code</returns>
		public static bool RunCommand(string Executable, string Arguments, string Tag = "")
		{
			var ProcessInfo = CreateProcessStartInfo(Executable, Arguments);
			ProcessInfo.CreateNoWindow = true;
			ProcessInfo.UseShellExecute = false;
			ProcessInfo.RedirectStandardError = true;
			ProcessInfo.RedirectStandardOutput = true;

			RunningProcess = System.Diagnostics.Process.Start(ProcessInfo);

			RunningProcess.OutputDataReceived += (object sender, DataReceivedEventArgs Evt) =>
				Console.WriteLine(Tag + ">" + Evt.Data);
			RunningProcess.BeginOutputReadLine();

			RunningProcess.ErrorDataReceived += (object sender, DataReceivedEventArgs Evt) =>
				Console.WriteLine(Tag + "!>" + Evt.Data);
			RunningProcess.BeginErrorReadLine();

			RunningProcess.WaitForExit();

			int ReturnValue = RunningProcess.ExitCode;
			RunningProcess.Close();

			RunningProcess = null;

			return ReturnValue == 0;
		}

		/// <summary>
		/// Platform dependent way of creating the process start info
		/// </summary>
		/// <param name="Executable"></param>
		/// <param name="Arguments"></param>
		/// <returns></returns>
		private static ProcessStartInfo CreateProcessStartInfo(string Executable, string Arguments)
		{
			if (Platform.IsWindows())
			{
				// Append "" around the executable so that it can be run
				Executable = "\"\"" + Executable + "\"\"";

				// On windows, run it in the command prompt
				return new ProcessStartInfo("cmd", "/c " + Executable + " " + Arguments);
			}
			else if (Platform.IsMacOS())
			{
				return new ProcessStartInfo(Executable, Arguments);
			}

			throw new System.ApplicationException("Calling CreateProcessStartInfo on unsupported platform");
		}

		/// <summary>
		/// Mac/linux way of calling the cleanup function
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private static void CallCleanupMacLinux(object sender, ConsoleCancelEventArgs e)
		{
			if (Cleanup != null)
			{
				Cleanup();
			}
		}

		/// <summary>
		/// Information about why the application terminated on Windows
		/// </summary>
		private enum SignalType
		{
			CTRL_C_EVENT = 0,
			CTRL_BREAK_EVENT = 1,
			CLOSE_EVENT = 2,
			LOGOFF_EVENT = 5,
			SHUTDOWN_EVENT = 6
		}

		/// <summary>
		/// Windows specific close handler
		/// </summary>
		/// <param name="Signal"></param>
		/// <returns></returns>
		private static bool WindowsHandler(SignalType Signal)
		{
			switch (Signal)
			{
				case SignalType.CTRL_BREAK_EVENT:
				case SignalType.CTRL_C_EVENT:
				case SignalType.LOGOFF_EVENT:
				case SignalType.SHUTDOWN_EVENT:
				case SignalType.CLOSE_EVENT:
					if (Cleanup != null)
					{
						Cleanup();
					}
					return false;

				default:
					return false;
			}
		}


		// https://msdn.microsoft.com/en-us/library/windows/desktop/ms686016.aspx
		[DllImport("Kernel32")]
		private static extern bool SetConsoleCtrlHandler(SetConsoleCtrlEventHandler handler, bool add);

		// https://msdn.microsoft.com/en-us/library/windows/desktop/ms683242.aspx
		private delegate bool SetConsoleCtrlEventHandler(SignalType sig);
	}
}
