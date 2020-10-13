using System;
using System.Collections.Generic;
using System.Text;
using System.Diagnostics;

namespace MakeRelease
{
	public class Process
	{
		public static bool RunCommand(string Executable, string Arguments, string Tag)
		{
			// Convert spaces to acceptable spaces
			// Append "" around the executable so that it can be run
			Executable = "\"\"" + Executable + "\"\"";

			Console.WriteLine("cmd.exe /c " + Executable + " " + Arguments);
			var ProcessInfo = new ProcessStartInfo("cmd.exe", "/c " + Executable + " " + Arguments);
			ProcessInfo.CreateNoWindow = true;
			ProcessInfo.UseShellExecute = false;
			ProcessInfo.RedirectStandardError = true;
			ProcessInfo.RedirectStandardOutput = true;

			var Process = System.Diagnostics.Process.Start(ProcessInfo);

			Process.OutputDataReceived += (object sender, DataReceivedEventArgs Evt) =>
				Console.WriteLine(Tag + ">" + Evt.Data);
			Process.BeginOutputReadLine();

			Process.ErrorDataReceived += (object sender, DataReceivedEventArgs Evt) =>
				Console.WriteLine(Tag + "!>" + Evt.Data);
			Process.BeginErrorReadLine();

			Process.WaitForExit();

			int ReturnValue = Process.ExitCode;
			Console.WriteLine("ExitCode: {0}", ReturnValue);
			Process.Close();

			return ReturnValue == 0;
		}
	}
}
