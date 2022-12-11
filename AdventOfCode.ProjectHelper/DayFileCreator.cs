using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;

namespace AdventOfCode.ProjectHelper
{
	public class TestCase
	{
		public int Part { get; set; }
		public List<string> Data { get; set; }
		public string Result { get; set; }
	}

	public class DayFileCreator
	{
		private int _day;
		private int _year;

		private string _title = string.Empty;
		public string TitleWithoutBlanks { get; private set; }

		private string _processorName = string.Empty;
		private string _resultName = string.Empty;
		private string _contextName = string.Empty;

		private string _baseClassName;
		private string _baseClassParameter = string.Empty;

		private List<TestCase> _testCases = new List<TestCase>();


		public DayFileCreator() { }

		public DayFileCreator ForDay(int day, int year)
		{
			_day = day;
			_year = year;
			_baseClassName = "Day";
			return this;
		}

		public DayFileCreator WithTitle(string title)
		{
			_title = title;

			// Capitalize each word and join without blanks
			TitleWithoutBlanks = string.Join("",
				title.Split(' ').Select(word => { return char.ToUpper(word[0]) + word.Substring(1); })
			);
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

		public DayFileCreator WithTestCases(List<TestCase> testCaseList)
		{
			_testCases= testCaseList;
			return this;
		}

		public Result CreateHeader(Stream outStream)
		{
			if (_year == 0 || _day == 0)
				return Result.Error("No valid date (year and / or day missing)!");

			if (string.IsNullOrEmpty(_title))
				return Result.Error("No valid title!");

			using (StreamWriter sw = new StreamWriter(outStream, Encoding.UTF8))
			{
				AddHeaderIncludes(sw);
				AddBlank(sw);

				using (_ = new NamespaceWriter($"AdventOfCode::Year{_year}::Day{_day:D2}", sw))
				{
					AddCommentDecorator(sw);
					using (_ = new ClassDeclarationWriter(TitleWithoutBlanks, _baseClassName, _baseClassParameter, DefaultCtor.Create, sw))
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
			if (_year == 0 || _day == 0)
				return Result.Error("No valid date (year and / or day missing)!");

			if (string.IsNullOrEmpty(_title))
				return Result.Error("No valid title!");

			using (StreamWriter sw = new StreamWriter(outStream, Encoding.UTF8))
			{
				AddSourceIncludes(sw, stlIncludes);
				AddBlank(sw);

				using (_ = new NamespaceWriter($"AdventOfCode::Year{_year}::Day{_day:D2}", sw))
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

		public Result CreateTest(Stream outStream)
		{
			if (_year == 0 || _day == 0)
				return Result.Error("No valid date (year and / or day missing)!");

			if (string.IsNullOrEmpty(_title))
				return Result.Error("No valid title!");

			using (StreamWriter sw = new StreamWriter(outStream, Encoding.UTF8))
			{
				// AddSourceIncludes(sw, stlIncludes);
				sw.WriteLine("#include \"stdafx.h\"");
				sw.WriteLine($"#include \"Day{_day:D2}\\Day{_day:D2}_{TitleWithoutBlanks}.h\"");
				AddBlank(sw);

				sw.WriteLine("using namespace Microsoft::VisualStudio::CppUnitTestFramework;");
				sw.WriteLine($"using namespace AdventOfCode::Year{_year}::Day{_day:D2};");
				AddBlank(sw);

				using (_ = new NamespaceWriter($"AdventOfCode::Year{_year}::Tests", sw))
				{
					using (_ = new TestClassDeclarationWriter(_year, _day, sw))
					{
						sw.WriteLine("\tprivate:");

						for (int i = 1; i <= _testCases.Count; ++i)
						{
							sw.WriteLine($"\t\tstatic std::vector<std::string> inputData{i};");
						}	
						AddBlank(sw);
						sw.WriteLine("\tpublic:");

						// Initialize input data:
						using (_ = new TestMethodDeclarationWriter("TEST_CLASS_INITIALIZE", "Init", sw))
						{
							for (int i = 1; i <= _testCases.Count; ++i)
							{
								sw.WriteLine($"\t\t\tinputData{i} = std::vector<std::string>");
								sw.WriteLine("\t\t\t{");

								foreach (string inputLine in _testCases[i - 1].Data)
									sw.WriteLine($"\t\t\t\t\"{inputLine}\"" + (inputLine != _testCases[i - 1].Data.Last() ? "," : ""));

								sw.WriteLine("\t\t\t};");
								AddBlank(sw);
							}
						}

						// Check Examples:
						AddTestCase(sw, 1);
						AddTestCase(sw, 2);
					}

					// Static initializers:
					for (int i = 1; i <= _testCases.Count; ++i)
					{
						sw.WriteLine($"\tstd::vector<std::string> Year{_year}_Day{_day:D2}::inputData{i} = std::vector<std::string>();");
					}
				}
			}

			return Result.OK();
		}

		public void AddToSolutionHeader(List<string> lines)
		{
			// Insert include statement after the end of the existing include block:
			int lastInclude = lines.IndexOf(lines.Last(l => l.StartsWith("#include")));
			lines.Insert(lastInclude + 1, $"#include \"Day{_day:D2}\\Day{_day:D2}_{TitleWithoutBlanks}.h\"");

			// Insert case for this day before the 'default' case:
			int defaultCase = lines.IndexOf(lines.Single(l => l.Contains("default:\treturn nullptr;")));
			lines.Insert(defaultCase, $"\t\t\t\tcase {_day:D2}:\treturn std::make_unique<Day{_day:D2}::{TitleWithoutBlanks}>();");
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
			sw.WriteLine($"{indent}// Day{_day:D2}: {_title}");
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
			sw.WriteLine($"#include \"Day{_day:D2}_{TitleWithoutBlanks}.h\"");
			if (stlIncludes.UseStdAlgorithm) sw.WriteLine($"#include <algorithm>");
			if (stlIncludes.UseStdDeque) sw.WriteLine($"#include <deque>");
			if (stlIncludes.UseStdMap) sw.WriteLine($"#include <map>");
			if (stlIncludes.UseStdNumeric) sw.WriteLine($"#include <numeric>");
			if (stlIncludes.UseStdSet) sw.WriteLine($"#include <set>");
			if (stlIncludes.UseStdStack) sw.WriteLine($"#include <stack>");
		}

		private void AddConstructorImpl(StreamWriter sw)
		{
			sw.WriteLine($"\t{TitleWithoutBlanks}::{TitleWithoutBlanks}() : {_baseClassName}({_day}, \"{_title}\") {{ }}");
		}

		private void AddSolutionMethodImpl(StreamWriter sw, int part)
		{
			if (_processorName != string.Empty)
			{
				if (_contextName != string.Empty)
					sw.WriteLine($"\tuint64_t {TitleWithoutBlanks}::ExecutePart{part}(std::vector<{_resultName}> input, {_contextName} context)");
				else
					sw.WriteLine($"\tuint64_t {TitleWithoutBlanks}::ExecutePart{part}(std::vector<{_resultName}> input)");
			}
			else
				sw.WriteLine($"\tuint64_t {TitleWithoutBlanks}::GetResultOnPart{part}(std::vector<std::string> input)");

			sw.WriteLine("\t{");
			sw.WriteLine("\t\treturn uint64_t();");
			sw.WriteLine("\t}");
		}

		private void AddTestCase(StreamWriter sw, int part)
		{
			int testCaseNo = 1;
			foreach(TestCase tc in _testCases.Where(tc => tc.Part == part))
			{
				using (_ = new TestMethodDeclarationWriter("TEST_METHOD", $"CheckExample{testCaseNo}_Part{part}", sw))
				{
					sw.WriteLine("\t\t\t// Arrange:");
					sw.WriteLine($"\t\t\t{TitleWithoutBlanks} sut;");

					sw.WriteLine("\t\t\t// Act:");

					int inputDataNo = _testCases.IndexOf(tc) + 1;
					sw.WriteLine($"\t\t\tuint64_t result = sut.GetResultOnPart{part}(inputData{inputDataNo});");

					sw.WriteLine("\t\t\t// Assert:");
					sw.WriteLine($"\t\t\tAssert::AreEqual({tc.Result}ull, result);");

					++testCaseNo;
				}
				AddBlank(sw);
			}
		}
	}
}
