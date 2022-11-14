using System;
using System.Collections.Generic;
using System.Linq;
using System.Xml.Linq;

namespace AdventOfCode.ProjectHelper
{
	public class ProjectFilesUpdater
	{
		private string _day;
		private string _year;
		private string _prjPath;

		XDocument _prjFile;
		XDocument _prjFileFilters;
		public ProjectFilesUpdater(string year, string day)
		{
			_year = year;
			_day = day;

			// Open project files:
			_prjPath = @$"..\..\AdventOfCode{year}.Solutions";
			_prjFile = XDocument.Load(@$"{_prjPath}\AdventOfCode{year}.Solutions.vcxproj");
			_prjFileFilters = XDocument.Load(@$"{_prjPath}\AdventOfCode{year}.Solutions.vcxproj.filters");

			// ItemGroup that contains list of filters:
			XElement proj = _prjFileFilters.Root;
			var itemGroups = proj.Elements().Where(x => x.Name.LocalName == "ItemGroup");
			var filterGroup = itemGroups.First(elem => elem.Elements().Any(d => d.Name.LocalName == "Filter"));

			// Create a new filter entry and add it to the group:
			XElement newFilter = CreateFilterEntry(proj.GetDefaultNamespace(), "Filter", $"Day{day}", "UniqueIdentifier", $"{{{Guid.NewGuid()}}}");
			filterGroup.Add(newFilter);
		}

		public void AddSourceFile(string srcFile)
		{
			// Add to project:
			XElement sourceGroup = FindElementByChildNames(_prjFile, "ItemGroup", "ClCompile");
			XElement newSourceEntry = new XElement(_prjFile.Root.GetDefaultNamespace() + "ClCompile");
			newSourceEntry.Add(new XAttribute("Include", @$"Day{_day}\{srcFile}"));
			sourceGroup.Add(newSourceEntry);

			// Add to project filters:
			XElement filterGroup = FindElementByChildNames(_prjFileFilters, "ItemGroup", "ClCompile");
			XElement newFilter = CreateFilterEntry(_prjFileFilters.Root.GetDefaultNamespace(), "ClCompile", @$"Day{_day}\{srcFile}", "Filter", $"Day{_day}");
			filterGroup.Add(newFilter);
		}

		public void AddHeaderFile(string headerFile)
		{
			// Add to project:
			XElement headerGroup = FindElementByChildNames(_prjFile, "ItemGroup", "ClInclude");
			XElement newHeaderEntry = new XElement(_prjFile.Root.GetDefaultNamespace() + "ClInclude");
			newHeaderEntry.Add(new XAttribute("Include", @$"Day{_day}\{headerFile}"));
			headerGroup.Add(newHeaderEntry);

			// Add to project filters:
			XElement filterGroup = FindElementByChildNames(_prjFileFilters, "ItemGroup", "ClInclude");

			XElement newFilter = CreateFilterEntry(_prjFileFilters.Root.GetDefaultNamespace(), "ClInclude", @$"Day{_day}\{headerFile}", "Filter", $"Day{_day}");
			filterGroup.Add(newFilter);
		}



		public void Save()
		{
			_prjFile.Save(@$"{_prjPath}\AdventOfCode{_year}.Solutions.vcxproj");
			_prjFileFilters.Save(@$"{_prjPath}\AdventOfCode{_year}.Solutions.vcxproj.filters");
		}

		private XElement FindElementByChildNames(XDocument doc, string groupName, string childName)
		{
			XElement proj = doc.Root;
			var itemGroups = proj.Elements().Where(x => x.Name.LocalName == groupName);
			return itemGroups.First(elem => elem.Elements().Any(d => d.Name.LocalName == childName));
		}

		// Creates an entry of the following form:
		// <{elementName} Include={includeAttrib}>
		//   <{contentName}>{contentValue}</{contentName}>
		// </{elementName}>
		private XElement CreateFilterEntry(XNamespace defNamespace, string elementName, string includeAttrib, string contentName, string contentValue)
		{
			XElement newFilterEntry = new XElement(defNamespace + elementName);
			newFilterEntry.Add(new XAttribute("Include", includeAttrib));
			newFilterEntry.Add(new XElement(defNamespace + "Filter", contentValue));
			return newFilterEntry;
		}
	}
}
