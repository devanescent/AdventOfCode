using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace AdventOfCode.ProjectHelper
{
	public class NamespaceWriter : IDisposable
	{
		private StreamWriter _sw;
		public NamespaceWriter(string fullNamespaceName, StreamWriter sw)
		{
			_sw = sw;
			sw.WriteLine($"namespace {fullNamespaceName}");
			sw.WriteLine("{");
		}

		public void Dispose()
		{
			_sw.WriteLine("}");
		}
	}
}
