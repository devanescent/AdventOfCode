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
			if (lines != null && lines.Any())
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
		public int Year { get; set; }
		public int Day { get; set; }
		public string Title { get; set; }

		public DaySTLIncludes DaySTL { get; set; } = new DaySTLIncludes();
		
		public string Processor { get; set; }
		public string Result { get; set; }
		public string Context { get; set; }
		public bool CreateContextType { get; set; } = true;
		public bool CreateResultType { get; set; } = true;
		public ProcessorSTLIncludes ProcSTL { get; set; } = new ProcessorSTLIncludes();
		public ResultOptions ResultOptions { get; set; } = new ResultOptions();

		public ObservableCollection<TestCase> TestCaseList { get; set; } = new ObservableCollection<TestCase>() { new TestCase() };

		public MainViewModel()
		{
			Day = DateTime.Today.Day;
			Year = DateTime.Today.Year;
		}

		public void CreateFiles()
		{
			// Capitalize each word and join without blanks
			string _titleWithoutBlanks = string.Join("", 
				Title.Split(' ').Select(word => { return char.ToUpper(word[0]) + word.Substring(1); })
			);

			string solutionDirPath = @$"..\..\AdventOfCode{Year}.Solutions\Day{Day:D2}";
			string testDirPath = @$"..\..\AdventOfCode{Year}.Tests";

			Directory.CreateDirectory(solutionDirPath);

			// To add created files to projects:
			ProjectFilesUpdater prjUpdater = new ProjectFilesUpdater(Year, Day);

			// Main files:
			DayFileCreator dayFileCreator = new DayFileCreator()
					.ForDay(Day, Year)
					.WithTitle(Title);

			if (!string.IsNullOrEmpty(Processor))
				dayFileCreator.WithProcessor(Processor, Result);

			if (!string.IsNullOrEmpty(Context))
				dayFileCreator.WithContext(Context);

			using (FileStream dayHeaderFile = File.Create(@$"{solutionDirPath}\Day{Day:D2}_{_titleWithoutBlanks}.h"))
			{
				dayFileCreator.CreateHeader(dayHeaderFile);
				prjUpdater.AddHeaderFile(Path.GetFileName(dayHeaderFile.Name));
			}

			using (FileStream daySourceFile = File.Create(@$"{solutionDirPath}\Day{Day:D2}_{_titleWithoutBlanks}.cpp"))
			{
				dayFileCreator.CreateSource(daySourceFile, DaySTL);
				prjUpdater.AddSourceFile(Path.GetFileName(daySourceFile.Name));
			}

			if (TestCaseList.Any())
			{
				using (FileStream testFile = File.Create(@$"{testDirPath}\Day{Day:D2}_Test.cpp"))
				{
					dayFileCreator.WithTestCases(TestCaseList.ToList());
					dayFileCreator.CreateTest(testFile);
					prjUpdater.AddTestFile(Path.GetFileName(testFile.Name));
				}
			}
			
			// Processor:
			if (!string.IsNullOrEmpty(Processor))
			{
				ProcessorCreator processorCreator = new ProcessorCreator()
				.ForDay(Day, Year)
				.WithProcessor(Processor, Result, CreateResultType)
				.WithResultOptions(ResultOptions);

				if (!string.IsNullOrEmpty(Context))
					processorCreator.WithContext(Context, CreateContextType);

				if (CreateResultType)
				{
					using (FileStream processingResultFile = File.Create(@$"{solutionDirPath}\{Result}.h"))
					{
						processorCreator.CreateHeaderResult(processingResultFile);
						prjUpdater.AddHeaderFile(Path.GetFileName(processingResultFile.Name));
					}
				}

				using (FileStream ProcessorHeaderFile = File.Create(@$"{solutionDirPath}\{Processor}.h"))
				{
					processorCreator.CreateHeader(ProcessorHeaderFile);
					prjUpdater.AddHeaderFile(Path.GetFileName(ProcessorHeaderFile.Name));
				}

				using (FileStream ProcessorSourceFile = File.Create(@$"{solutionDirPath}\{Processor}.cpp"))
				{
					processorCreator.CreateSource(ProcessorSourceFile, ProcSTL);
					prjUpdater.AddSourceFile(Path.GetFileName(ProcessorSourceFile.Name));
				}

				if (CreateContextType)
				{
					using (FileStream ContextFile = File.Create(@$"{solutionDirPath}\{Context}.h"))
					{
						processorCreator.CreateContext(ContextFile);
						prjUpdater.AddHeaderFile(Path.GetFileName(ContextFile.Name));
					}
				}
			}

			prjUpdater.Save();
		}
	}
}
