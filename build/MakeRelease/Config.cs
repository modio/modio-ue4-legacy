using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;
using System.Configuration;

namespace MakeRelease
{
	/// <summary>
    /// For parsing the App.config
    /// </summary>
	public class UE4Configuration : IConfigurationSectionHandler
	{
		public object Create(object parent, object configContext, XmlNode Section)
		{
			List<InstallMetadata> MyConfigObject = new List<InstallMetadata>();

			foreach (XmlNode ChildNode in Section.ChildNodes)
			{
				if( ChildNode.Attributes["Version"] == null )
				{
					throw new System.ApplicationException("Missing Version attribute for UE4 Install in App.config");
				}
				if (ChildNode.Attributes["ClangInstall"] == null)
				{
					throw new System.ApplicationException("Missing ClangInstall attribute for UE4 Install in App.config");
				}
				if (ChildNode.Attributes["XCodeInstall"] == null)
				{
					throw new System.ApplicationException("Missing XCodeInstall attribute for UE4 Install in App.config");
				}

				// @todo: Verify that the data is correctly formed and valid paths

				MyConfigObject.Add( new InstallMetadata()
				{ 
					Version = ChildNode.Attributes["Version"].Value,
					ClangInstallPath = ChildNode.Attributes["ClangInstall"].Value,
					XCodeInstallPath = ChildNode.Attributes["XCodeInstall"].Value
				});
			}
			return MyConfigObject;
		}		
	}

	/// <summary>
    /// 
    /// </summary>
	public class InstallMetadata
	{
		public string Version { get; set; }
		public string ClangInstallPath { get; set; }
		public string XCodeInstallPath { get; set; }
	}

}
