using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace AdventOfCode.ProjectHelper
{
	public class ProcessorCreator
	{
		private string _day = string.Empty;
		private string _year = string.Empty;

		private string _processorName = string.Empty;
		private string _resultName = string.Empty;
		private string _contextName = string.Empty;
		private bool _createContextType = false;

		public ProcessorCreator() { }

		public ProcessorCreator ForDay(string day, string year)
		{
			_day = day;
			_year = year;
			return this;
		}

		public ProcessorCreator WithProcessor(string processorName, string resultName)
		{
			_processorName = processorName;
			_resultName = resultName;
			return this;
		}

		public ProcessorCreator WithContext(string contextName, bool createType)
		{
			_contextName = contextName;
			_createContextType = createType;
			return this;
		}

		public Result CreateHeaderResult(Stream outStream)
		{
			using (StreamWriter sw = new StreamWriter(outStream, Encoding.UTF8))
			{
				sw.WriteLine("#pragma once");
				AddBlank(sw);

				using (_ = new NamespaceWriter($"AdventOfCode::Year{_year}::Day{_day}", sw))
				{
					using (_ = new ClassDeclarationWriter(_resultName, DefaultCtor.None, sw))
					{ }
				}
			}

			return Result.OK();
		}

		public Result CreateHeader(Stream outStream)
		{
			using (StreamWriter sw = new StreamWriter(outStream, Encoding.UTF8))
			{
				AddHeaderIncludes(sw);
				AddBlank(sw);

				using (_ = new NamespaceWriter($"AdventOfCode::Year{_year}::Day{_day}", sw))
				{
					string processorBaseClassName, processorBaseClassParam;
					if (_contextName != string.Empty)
					{
						processorBaseClassName = "InputProcessorWithContextBase";
						processorBaseClassParam = $"<{_resultName}, {_contextName}>";
					}
					else
					{
						processorBaseClassName = "InputProcessorBase";
						processorBaseClassParam = $"<{_resultName}>";
					}

					using (_ = new ClassDeclarationWriter(_processorName, processorBaseClassName, processorBaseClassParam, DefaultCtor.None, sw))
					{
						AddProcessingMethod(sw);
					}
				}
			}

			return Result.OK();
		}

		public Result CreateSource(Stream outStream, ProcessorSTLIncludes stlIncludes)
		{
			using (StreamWriter sw = new StreamWriter(outStream, Encoding.UTF8))
			{
				AddSourceIncludes(sw, stlIncludes);
				AddBlank(sw);

				using (_ = new NamespaceWriter($"AdventOfCode::Year{_year}::Day{_day}", sw))
				{
					AddProcessingMethodImpl(sw);
				}
			}

			return Result.OK();
		}

		public Result CreateContext(Stream outStream)
		{
			using (StreamWriter sw = new StreamWriter(outStream, Encoding.UTF8))
			{
				sw.WriteLine("#pragma once");
				AddBlank(sw);

				using (_ = new NamespaceWriter($"AdventOfCode::Year{_year}::Day{_day}", sw))
				{
					using (_ = new ClassDeclarationWriter(_contextName, DefaultCtor.None, sw))
					{ }
				}
			}

			return Result.OK();
		}

		private void AddBlank(StreamWriter sw)
		{
			sw.WriteLine();
		}

		private void AddHeaderIncludes(StreamWriter sw)
		{
			sw.WriteLine("#pragma once");

			if (_contextName != string.Empty)
				sw.WriteLine("#include \"InputProcessorWithContext.h\"");
			else
				sw.WriteLine("#include \"InputProcessor.h\"");

			sw.WriteLine($"#include \"{_resultName}.h\"");

			if (_createContextType)
				sw.WriteLine($"#include \"{_contextName}.h\"");
		}

		private void AddSourceIncludes(StreamWriter sw, ProcessorSTLIncludes stlIncludes)
		{
			sw.WriteLine($"#include \"{_processorName}.h\"");

			if (stlIncludes.UseStdAlgorithm) sw.WriteLine($"#include <algorithm>");
			if (stlIncludes.UseRegex) sw.WriteLine($"#include <regex>");
			if (stlIncludes.UseStringStream) sw.WriteLine($"#include <sstream>");
		}

		private void AddProcessingMethod(StreamWriter sw)
		{
			// Processing method:
			sw.WriteLine("\tpublic:");
			if (_contextName != string.Empty)
				sw.WriteLine($"\t\tstd::pair<std::vector<{_resultName}>, {_contextName}> Process(std::vector<std::string> input) override;");
			else
				sw.WriteLine($"\t\tstd::vector<{_resultName}> Process(std::vector<std::string> input) override;");
		}

		private void AddProcessingMethodImpl(StreamWriter sw)
		{
			string processingReturnType;
			if (_contextName != string.Empty)
				processingReturnType = $"std::pair<std::vector<{_resultName}>, {_contextName}>";
			else
				processingReturnType = $"std::vector<{_resultName}>";

			// Processing method:
			sw.WriteLine($"\t{processingReturnType} {_processorName}::Process(std::vector<std::string> input)");
			sw.WriteLine("\t{");
			sw.WriteLine($"\t\treturn {processingReturnType}();");
			sw.WriteLine("\t}");
		}
	}
}
