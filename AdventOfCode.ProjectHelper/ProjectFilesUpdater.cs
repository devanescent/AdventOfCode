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
		private string _solutionPrjPath;
		private string _testPrjPath;

		XDocument _solutionPrjFile;
		XDocument _solutionPrjFileFilters;

		XDocument _testPrjFile;
		XDocument _testPrjFileFilters;
		public ProjectFilesUpdater(string year, string day)
		{
			_year = year;
			_day = day;

			// Open project files:
			_solutionPrjPath = @$"..\..\AdventOfCode{year}.Solutions";
			_testPrjPath = @$"..\..\AdventOfCode{year}.Tests";

			_solutionPrjFile = XDocument.Load(@$"{_solutionPrjPath}\AdventOfCode{year}.Solutions.vcxproj");
			_solutionPrjFileFilters = XDocument.Load(@$"{_solutionPrjPath}\AdventOfCode{year}.Solutions.vcxproj.filters");

			_testPrjFile = XDocument.Load(@$"{_testPrjPath}\AdventOfCode{year}.Tests.vcxproj");
			_testPrjFileFilters = XDocument.Load(@$"{_testPrjPath}\AdventOfCode{year}.Tests.vcxproj.filters");

			// ItemGroup that contains list of filters:
			XElement proj = _solutionPrjFileFilters.Root;
			var itemGroups = proj.Elements().Where(x => x.Name.LocalName == "ItemGroup");
			var filterGroup = itemGroups.First(elem => elem.Elements().Any(d => d.Name.LocalName == "Filter"));

			// Create a new filter entry and add it to the group:
			XElement newFilter = CreateFilterEntry(proj.GetDefaultNamespace(), "Filter", $"Day{day}", "UniqueIdentifier", $"{{{Guid.NewGuid()}}}");
			filterGroup.Add(newFilter);
		}

		public void AddHeaderFile(string headerFile)
		{
			// Add to project:
			XElement headerGroup = FindElementByChildNames(_solutionPrjFile, "ItemGroup", "ClInclude");
			XElement newHeaderEntry = new XElement(_solutionPrjFile.Root.GetDefaultNamespace() + "ClInclude");
			newHeaderEntry.Add(new XAttribute("Include", @$"Day{_day}\{headerFile}"));
			headerGroup.Add(newHeaderEntry);

			// Add to project filters:
			XElement filterGroup = FindElementByChildNames(_solutionPrjFileFilters, "ItemGroup", "ClInclude");

			XElement newFilter = CreateFilterEntry(_solutionPrjFileFilters.Root.GetDefaultNamespace(), "ClInclude", @$"Day{_day}\{headerFile}", "Filter", $"Day{_day}");
			filterGroup.Add(newFilter);
		}

		public void AddSourceFile(string srcFile)
		{
			// Add to project:
			XElement sourceGroup = FindElementByChildNames(_solutionPrjFile, "ItemGroup", "ClCompile");
			XElement newSourceEntry = new XElement(_solutionPrjFile.Root.GetDefaultNamespace() + "ClCompile");
			newSourceEntry.Add(new XAttribute("Include", @$"Day{_day}\{srcFile}"));
			sourceGroup.Add(newSourceEntry);

			// Add to project filters:
			XElement filterGroup = FindElementByChildNames(_solutionPrjFileFilters, "ItemGroup", "ClCompile");
			XElement newFilter = CreateFilterEntry(_solutionPrjFileFilters.Root.GetDefaultNamespace(), "ClCompile", @$"Day{_day}\{srcFile}", "Filter", $"Day{_day}");
			filterGroup.Add(newFilter);
		}

		public void AddTestFile(string testFile)
		{
			// Add to project:
			XElement sourceGroup = FindElementByChildNames(_testPrjFile, "ItemGroup", "ClCompile");
			XElement newSourceEntry = new XElement(_testPrjFile.Root.GetDefaultNamespace() + "ClCompile");
			newSourceEntry.Add(new XAttribute("Include", $"{testFile}"));
			sourceGroup.Add(newSourceEntry);

			// Add to project filters:
			XElement filterGroup = FindElementByChildNames(_testPrjFileFilters, "ItemGroup", "ClCompile");
			XElement newFilter = CreateFilterEntry(_testPrjFileFilters.Root.GetDefaultNamespace(), "ClCompile", $"{testFile}", "Filter", $"Source Files");
			filterGroup.Add(newFilter);
		}

		public void Save()
		{
			_solutionPrjFile.Save(@$"{_solutionPrjPath}\AdventOfCode{_year}.Solutions.vcxproj");
			_solutionPrjFileFilters.Save(@$"{_solutionPrjPath}\AdventOfCode{_year}.Solutions.vcxproj.filters");

			_testPrjFile.Save(@$"{_testPrjPath}\AdventOfCode{_year}.Tests.vcxproj");
			_testPrjFileFilters.Save(@$"{_testPrjPath}\AdventOfCode{_year}.Tests.vcxproj.filters");
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
