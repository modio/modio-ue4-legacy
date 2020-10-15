using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace MakeRelease
{
	static class Filesystem
	{
		public static void SafeDeleteFile(string FileToDelete)
		{
			if (File.Exists(FileToDelete))
			{
				File.Delete(FileToDelete);
			}
		}

		/** Ensure that Directory.Delete doesn't throw if the directory doesn't exist */
		public static void SafeDeleteDirectory(string DirectoryToDelete, bool Recursive)
		{
			if (Directory.Exists(DirectoryToDelete))
			{
				Directory.Delete(DirectoryToDelete, Recursive);
			}
		}

		/** Ensure that Directory.CreateDirectory doesn't throw if the directory exists */
		public static void SafeCreateDirectory(string DirectoryToCreate)
		{
			if (!Directory.Exists(DirectoryToCreate))
			{
				Directory.CreateDirectory(DirectoryToCreate);
			}
		}

		// Copies a directory and all it's subdirectories
		// From https://docs.microsoft.com/en-us/dotnet/standard/io/how-to-copy-directories
		public static void DirectoryCopy(string sourceDirName, string destDirName, bool copySubDirs)
		{
			// Get the subdirectories for the specified directory.
			DirectoryInfo dir = new DirectoryInfo(sourceDirName);

			if (!dir.Exists)
			{
				throw new DirectoryNotFoundException(
					"Source directory does not exist or could not be found: "
					+ sourceDirName);
			}

			DirectoryInfo[] dirs = dir.GetDirectories();

			// If the destination directory doesn't exist, create it.       
			Directory.CreateDirectory(destDirName);

			// Get the files in the directory and copy them to the new location.
			FileInfo[] files = dir.GetFiles();
			foreach (FileInfo file in files)
			{
				string tempPath = Path.Combine(destDirName, file.Name);
				file.CopyTo(tempPath, true);
			}

			// If copying subdirectories, copy them and their contents to new location.
			if (copySubDirs)
			{
				foreach (DirectoryInfo subdir in dirs)
				{
					string tempPath = Path.Combine(destDirName, subdir.Name);
					Filesystem.DirectoryCopy(subdir.FullName, tempPath, copySubDirs);
				}
			}
		}

		/// <summary>
        /// Creates a symbolic link
        /// </summary>
        /// <param name="PathToOriginal"></param>
        /// <param name="PathToLink"></param>
        /// <returns></returns>
		public static bool CreateSymbolicLink(string PathToOriginal, string PathToLink)
		{
			if (Platform.IsMacOS())
			{
				return Process.RunCommand("ln", string.Format("-s {0} {1}",
					PathToOriginal,
					PathToLink)
				);
			}

			throw new System.ApplicationException("Calling CreateSymbolicLink on unimplemented platform");
		}
	}
}
