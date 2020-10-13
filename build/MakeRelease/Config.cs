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
			List<Install> MyConfigObject = new List<Install>();

			foreach (XmlNode ChildNode in Section.ChildNodes)
			{
				foreach (XmlAttribute Attrib in ChildNode.Attributes)
				{
					MyConfigObject.Add(new Install() { Version = Attrib.Value });
				}
			}
			return MyConfigObject;
		}		
	}

	public class Install
	{
		public string Version { get; set; }
	}

}
