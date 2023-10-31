using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace AdventOfCode.ProjectHelper
{
	public enum DefaultCtor
	{
		Create,
		None
	}

	public class ClassDeclarationWriter : IDisposable
	{
		private StreamWriter _sw;
		private string _indent;

		// With base class:
		public ClassDeclarationWriter(string className, string baseClassName, string baseClassParam, DefaultCtor createCtor, StreamWriter sw)
		{
			_sw = sw;
			_indent = new string('\t', 1);

			// Declaration
			sw.WriteLine($"{_indent}class {className} : public {baseClassName}<{baseClassParam}>");
			sw.WriteLine($"{_indent}{{");

			// Constructor:
			if (createCtor == DefaultCtor.Create)
			{
				sw.WriteLine($"{_indent}public:");
				sw.WriteLine($"{_indent}\t{className}();");
				sw.WriteLine();
			}
		}

		// Without base class:
		public ClassDeclarationWriter(string className, DefaultCtor createCtor, StreamWriter sw)
		{
			_sw = sw;
			_indent = new string('\t', 1);

			// Declaration
			sw.WriteLine($"{_indent}class {className}");
			sw.WriteLine($"{_indent}{{");

			// Constructor:
			if (createCtor == DefaultCtor.Create)
			{
				sw.WriteLine($"{_indent}public:");
				sw.WriteLine($"{_indent}\t{className}();");
				sw.WriteLine();
			}
		}

		public void Dispose()
		{
			_sw.WriteLine($"{_indent}}};");
		}
	}
}
