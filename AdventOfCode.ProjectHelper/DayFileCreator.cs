using System.IO;
using System.Linq;
using System.Text;

namespace AdventOfCode.ProjectHelper
{
	public class DayFileCreator
	{
		private string _day = string.Empty;
		private string _year = string.Empty;

		private string _title = string.Empty;
		private string _classNameWithoutBlanks;

		private string _processorName = string.Empty;
		private string _resultName = string.Empty;
		private string _contextName = string.Empty;

		private string _baseClassName;
		private string _baseClassParameter = string.Empty;

		public DayFileCreator() { }

		public DayFileCreator ForDay(string day, string year)
		{
			_day = day;
			_year = year;
			return this;
		}

		public DayFileCreator WithTitle(string title)
		{
			_title = title;
			_classNameWithoutBlanks = string.Concat(title.Where(c => c != ' '));
			return this;
		}


		public DayFileCreator WithProcessor(string processorName, string resultName)
		{
			_processorName = processorName;
			_resultName = resultName;
			_baseClassName = "DayT";
			_baseClassParameter = $"<{processorName}>";
			return this;
		}

		public DayFileCreator WithContext(string contextName)
		{
			_contextName = contextName;
			_baseClassName = "DayTC";
			return this;
		}

		public Result CreateHeader(Stream outStream)
		{
			if (string.IsNullOrEmpty(_year) || string.IsNullOrEmpty(_day))
				return Result.Error("No valid date (year and / or day missing)!");

			if (string.IsNullOrEmpty(_title))
				return Result.Error("No valid title!");

			using (StreamWriter sw = new StreamWriter(outStream, Encoding.UTF8))
			{
				AddHeaderIncludes(sw);
				AddBlank(sw);

				using (_ = new NamespaceWriter($"AdventOfCode::Year{_year}::Day{_day}", sw))
				{
					AddCommentDecorator(sw);
					using (_ = new ClassDeclarationWriter(_classNameWithoutBlanks, _baseClassName, _baseClassParameter, DefaultCtor.Create, sw))
					{
						if (!string.IsNullOrEmpty(_processorName))
							sw.WriteLine("\tprotected:");

						AddSolutionMethod(sw, 1);
						AddSolutionMethod(sw, 2);
					}
				}
			}

			return Result.OK();
		}

		public Result CreateSource(Stream outStream, DaySTLIncludes stlIncludes)
		{
			if (string.IsNullOrEmpty(_year) || string.IsNullOrEmpty(_day))
				return Result.Error("No valid date (year and / or day missing)!");

			if (string.IsNullOrEmpty(_title))
				return Result.Error("No valid title!");

			using (StreamWriter sw = new StreamWriter(outStream, Encoding.UTF8))
			{
				AddSourceIncludes(sw, stlIncludes);
				AddBlank(sw);

				using (_ = new NamespaceWriter($"AdventOfCode::Year{_year}::Day{_day}", sw))
				{
					AddConstructorImpl(sw);
					AddBlank(sw);
					AddSolutionMethodImpl(sw, 1);
					AddBlank(sw);
					AddSolutionMethodImpl(sw, 2);
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
			sw.WriteLine($"#include \"{_baseClassName}.h\"");

			if (_processorName != string.Empty)
				sw.WriteLine($"#include \"{_processorName}.h\"");
		}

		private void AddCommentDecorator(StreamWriter sw)
		{
			string indent = new string('\t', 1);

			sw.WriteLine($"{indent}// ---------------------------------------------------------------------------");
			sw.WriteLine($"{indent}// Day{_day}: {_title}");
			sw.WriteLine($"{indent}// ---------------------------------------------------------------------------");
		}

		private void AddSolutionMethod(StreamWriter sw, int part)
		{
			// Solution method:
			if (_processorName != string.Empty)
			{
				if (_contextName != string.Empty)
					sw.WriteLine($"\t\tuint64_t ExecutePart{part}(std::vector<{_resultName}> input, {_contextName} context) override;");
				else
					sw.WriteLine($"\t\tuint64_t ExecutePart{part}(std::vector<{_resultName}> input) override;");
			}
			else
				sw.WriteLine($"\t\tuint64_t GetResultOnPart{part}(std::vector<std::string> input) override;");
		}

		private void AddSourceIncludes(StreamWriter sw, DaySTLIncludes stlIncludes)
		{
			sw.WriteLine($"#include \"Day{_day}_{_classNameWithoutBlanks}.h\"");
			if (stlIncludes.UseStdAlgorithm) sw.WriteLine($"#include <algorithm>");
			if (stlIncludes.UseStdDeque) sw.WriteLine($"#include <deque>");
			if (stlIncludes.UseStdMap) sw.WriteLine($"#include <map>");
			if (stlIncludes.UseStdNumeric) sw.WriteLine($"#include <numeric>");
			if (stlIncludes.UseStdSet) sw.WriteLine($"#include <set>");
			if (stlIncludes.UseStdStack) sw.WriteLine($"#include <stack>");
		}

		private void AddConstructorImpl(StreamWriter sw)
		{
			sw.WriteLine($"\t{_classNameWithoutBlanks}::{_classNameWithoutBlanks}() : {_baseClassName}({_day}, \"{_title}\") {{ }}");
		}

		private void AddSolutionMethodImpl(StreamWriter sw, int part)
		{
			if (_processorName != string.Empty)
			{
				if (_contextName != string.Empty)
					sw.WriteLine($"\tuint64_t {_classNameWithoutBlanks}::ExecutePart{part}(std::vector<{_resultName}> input, {_contextName} context)");
				else
					sw.WriteLine($"\tuint64_t {_classNameWithoutBlanks}::ExecutePart{part}(std::vector<{_resultName}> input)");
			}
			else
				sw.WriteLine($"\tuint64_t GetResultOnPart{part}(std::vector<std::string> input)");

			sw.WriteLine("\t{");
			sw.WriteLine("\t\treturn uint64_t();");
			sw.WriteLine("\t}");
		}
	}
}
