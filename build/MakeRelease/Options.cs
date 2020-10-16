using CommandLine;
using System;
using System.Collections.Generic;
using System.Text;

namespace MakeRelease
{
	/** Handles the arguments passed into main */
	public class Options
	{
		// @todo: Add a new option switch that logs the output to a file too, so that we can look at the logs afterwards
		[Option('v', "version", Required = true, HelpText = "The version of the UE4 plugin we want to submit")]
		public string UE4PluginVersion { get; set; }
	}
}
