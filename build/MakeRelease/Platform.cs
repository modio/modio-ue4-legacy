using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

namespace MakeRelease
{
	/** Simple helpers for cleaner syntax when we want to check the platform */
	class Platform
	{
		public static bool IsWindows() => RuntimeInformation.IsOSPlatform(OSPlatform.Windows);
		public static bool IsMacOS() => RuntimeInformation.IsOSPlatform(OSPlatform.OSX);
		public static bool IsLinux() => RuntimeInformation.IsOSPlatform(OSPlatform.Linux);
	}
}
