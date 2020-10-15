using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;
using System.Configuration;

namespace MakeRelease
{
	public class UE4Configuration : IConfigurationSectionHandler
	{
		public object Create(object parent, object configContext, XmlNode Section)
		{
			List<InstallMetadata> MyConfigObject = new List<InstallMetadata>();

			foreach (XmlNode ChildNode in Section.ChildNodes)
			{
				if( ChildNode.Attributes["Version"] == null )
				{
					continue;	
				}
				if (ChildNode.Attributes["ClangInstall"] == null)
				{
					continue;
				}
				MyConfigObject.Add( new InstallMetadata()
				{ 
					Version = ChildNode.Attributes["Version"].Value,
					ClangInstallPath = ChildNode.Attributes["ClangInstall"].Value 
				});
			}
			return MyConfigObject;
		}		
	}

	public class InstallMetadata
	{
		public string Version { get; set; }
		public string ClangInstallPath { get; set; }
	}

}
