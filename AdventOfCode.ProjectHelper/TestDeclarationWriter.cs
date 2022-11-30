using System;
using System.IO;

namespace AdventOfCode.ProjectHelper
{
	public class TestClassDeclarationWriter : IDisposable
	{
		private StreamWriter _sw;
		private string _indent;

		public TestClassDeclarationWriter(string year, string day, StreamWriter sw)
		{
			_sw = sw;
			_indent = new string('\t', 1);

			// Declaration
			sw.WriteLine($"{_indent}TEST_CLASS(Year{year}_Day{day})");
			sw.WriteLine($"{_indent}{{");
		}

		public void Dispose()
		{
			_sw.WriteLine($"{_indent}}};");
		}
	}

	public class TestMethodDeclarationWriter : IDisposable
	{
		private StreamWriter _sw;
		private string _indent;

		public TestMethodDeclarationWriter(string testMethodType, string name, StreamWriter sw)
		{
			_sw = sw;
			_indent = new string('\t', 2);

			// Declaration
			sw.WriteLine($"{_indent}{testMethodType}({name})");
			sw.WriteLine($"{_indent}{{");
		}

		public void Dispose()
		{
			_sw.WriteLine($"{_indent}}};");
		}
	}
}