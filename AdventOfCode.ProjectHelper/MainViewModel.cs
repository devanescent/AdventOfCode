using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Windows.Data;

namespace AdventOfCode.ProjectHelper
{
	public class TextToLinesConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			List<string> lines = value as List<string>;
			if (lines != null && lines.Count > 0)
				return string.Join(Environment.NewLine, lines);
			else
				return string.Empty;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			string text = value as string;

			if (!string.IsNullOrEmpty(text))
				return text.Split(Environment.NewLine).ToList();
			else
				return new List<string>();
		}
	}

	public class MainViewModel
	{
		public string Year { get; set; }
		public string Day { get; set; }
		public string Title { get; set; }

		public DaySTLIncludes DaySTL { get; set; } = new DaySTLIncludes();
		
		public string Processor { get; set; }
		public string Result { get; set; }
		public string Context { get; set; }
		public bool CreateContextType { get; set; }
		public bool CreateResultType { get; set; }
		public ProcessorSTLIncludes ProcSTL { get; set; } = new ProcessorSTLIncludes();
		public ResultOptions ResultOptions { get; set; } = new ResultOptions();

		public ObservableCollection<TestCase> TestCaseList { get; set; } = new ObservableCollection<TestCase>() { new TestCase() };

		public void CreateFiles()
		{
			string TitleWithoutBlanks = string.Concat(Title.Where(c => c != ' '));

			string DayBaseInclude = "Day";
			if (Processor != string.Empty) DayBaseInclude += "T";
			if (Context != string.Empty) DayBaseInclude += "C";

			string solutionDirPath = @$"..\..\AdventOfCode{Year}.Solutions\Day{Day}";
			string testDirPath = @$"..\..\AdventOfCode{Year}.Tests";

			Directory.CreateDirectory(solutionDirPath);


			ProjectFilesUpdater prjUpdater = new ProjectFilesUpdater(Year, Day);

			// Main files:
			DayFileCreator DayFileCreator = new DayFileCreator()
					.ForDay(Day, Year)
					.WithTitle(Title)
					.WithProcessor(Processor, Result)
					.WithTestCases(TestCaseList.ToList());

			using (FileStream dayHeaderFile = File.Create(@$"{solutionDirPath}\Day{Day}_{TitleWithoutBlanks}.h"))
			{
				DayFileCreator.CreateHeader(dayHeaderFile);
				prjUpdater.AddHeaderFile(Path.GetFileName(dayHeaderFile.Name));
			}

			using (FileStream daySourceFile = File.Create(@$"{solutionDirPath}\Day{Day}_{TitleWithoutBlanks}.cpp"))
			{
				DayFileCreator.CreateSource(daySourceFile, DaySTL);
				prjUpdater.AddSourceFile(Path.GetFileName(daySourceFile.Name));
			}

			using (FileStream testFile = File.Create(@$"{testDirPath}\Day{Day}_Test.cpp"))
			{
				DayFileCreator.CreateTest(testFile);
				prjUpdater.AddTestFile(Path.GetFileName(testFile.Name));
			}

			// Processor:
			if (!string.IsNullOrEmpty(Processor))
			{
				ProcessorCreator ProcessorCreator = new ProcessorCreator()
				.ForDay(Day, Year)
				.WithProcessor(Processor, Result, CreateResultType)
				.WithResultOptions(ResultOptions)
				.WithContext(Context, CreateContextType);

				if (CreateResultType)
				{
					using (FileStream processingResultFile = File.Create(@$"{solutionDirPath}\{Result}.h"))
					{
						ProcessorCreator.CreateHeaderResult(processingResultFile);
						prjUpdater.AddHeaderFile(Path.GetFileName(processingResultFile.Name));
					}
				}

				using (FileStream ProcessorHeaderFile = File.Create(@$"{solutionDirPath}\{Processor}.h"))
				{
					ProcessorCreator.CreateHeader(ProcessorHeaderFile);
					prjUpdater.AddHeaderFile(Path.GetFileName(ProcessorHeaderFile.Name));
				}

				using (FileStream ProcessorSourceFile = File.Create(@$"{solutionDirPath}\{Processor}.cpp"))
				{
					ProcessorCreator.CreateSource(ProcessorSourceFile, ProcSTL);
					prjUpdater.AddSourceFile(Path.GetFileName(ProcessorSourceFile.Name));
				}

				if (!string.IsNullOrEmpty(Context))
				{
					using (FileStream ContextFile = File.Create(@$"{solutionDirPath}\{Context}.h"))
					{
						ProcessorCreator.CreateContext(ContextFile);
						prjUpdater.AddHeaderFile(Path.GetFileName(ContextFile.Name));
					}
				}
			}

			prjUpdater.Save();
		}
	}
}
