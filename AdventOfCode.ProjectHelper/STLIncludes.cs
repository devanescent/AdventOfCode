using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace AdventOfCode.ProjectHelper
{
	public class DaySTLIncludes
	{
		public bool UseStdAlgorithm { get; set; }
		public bool UseStdDeque { get; set; }
		public bool UseStdMap { get; set; }
		public bool UseStdNumeric { get; set; }
		public bool UseStdSet { get; set; }
		public bool UseStdStack { get; set; }
	}

	public class ProcessorSTLIncludes
	{
		public bool UseStdAlgorithm { get; set; }
		public bool UseRegex { get; set; }
		public bool UseStringStream { get; set; }
	}
}
