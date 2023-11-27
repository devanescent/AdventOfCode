using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.IO;
using System.Linq;

namespace AdventOfCode.ProjectHelper
{
	public enum ProcessorTemplateType
	{
		None,
		StringStream
	}

	public enum ProcessorChoiceType
	{
		Custom,
		IntProcessor_ValuesAsDigit,
		IntProcessor_ValuePerLine,
		IntProcessor_ValuesAsCommaSeparatedLine,
		IntProcessor_ValuesAsSpaceSeparatedLine,
	}

	public record ProcessorTemplateTypeVM(ProcessorTemplateType TemplateType, string DisplayName);
	public record ProcessorChoiceTypeVM(ProcessorChoiceType ChoiceType, string DisplayName);

	public class MainViewModel : INotifyPropertyChanged
	{
		public event PropertyChangedEventHandler PropertyChanged;

		public int Year { get; set; }
		public int Day { get; set; }
		public string Title { get; set; }

		private bool _useNumericResult = true;

		public bool UseNumericResult
		{
			get { return _useNumericResult; }
			set { _useNumericResult = value; PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof(UseNumericResult))); }
		}

		public DaySTLIncludes DaySTL { get; set; } = new DaySTLIncludes();

		public List<ProcessorChoiceTypeVM> ProcessorChoiceList { get; } = new()
		{
			new ProcessorChoiceTypeVM(ProcessorChoiceType.Custom, "Custom"),
			new ProcessorChoiceTypeVM(ProcessorChoiceType.IntProcessor_ValuesAsDigit, "Int processor (values as digits in single line)"),
			new ProcessorChoiceTypeVM(ProcessorChoiceType.IntProcessor_ValuePerLine, "Int processor (value per line)"),
			new ProcessorChoiceTypeVM(ProcessorChoiceType.IntProcessor_ValuesAsCommaSeparatedLine, "Int processor (values as comma-separated line)"),
			new ProcessorChoiceTypeVM(ProcessorChoiceType.IntProcessor_ValuesAsSpaceSeparatedLine, "Int processor (values as space-separated line)"),
		};

		private ProcessorChoiceType? _selectedProcessorChoice = null;
		public ProcessorChoiceType? ProcessorChoice
		{
			get => _selectedProcessorChoice;
			set
			{
				_selectedProcessorChoice = value;
				IsCustomProcessor = _selectedProcessorChoice == ProcessorChoiceType.Custom;
				PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof(IsCustomProcessor)));
			}
		}
		public bool IsCustomProcessor { get; set; }

		public string Processor { get; set; }
		public string Result { get; set; }
		public string ResultListName { get; set; }
		public string Context { get; set; }
		public bool CreateContextType { get; set; } = true;
		public bool CreateResultType { get; set; } = true;
		public ProcessorSTLIncludes ProcSTL { get; set; } = new ProcessorSTLIncludes();
		public ResultOptions ResultOptions { get; set; } = new ResultOptions();

		public List<ProcessorTemplateTypeVM> ProcessorTemplates { get; } = new()
		{
			new ProcessorTemplateTypeVM(ProcessorTemplateType.None, "None"),
			new ProcessorTemplateTypeVM(ProcessorTemplateType.StringStream, "StringStream"),
		};

		private ProcessorTemplateType _selectedTemplate = ProcessorTemplateType.None;
		public ProcessorTemplateType SelectedProcessorTemplate
		{
			get => _selectedTemplate;
			set
			{
				_selectedTemplate = value;
				switch (_selectedTemplate)
				{
					case ProcessorTemplateType.StringStream:
						ProcSTL.UseStringStream = true;
						break;
				}
			}
		}

		public ObservableCollection<TestCase> TestCaseList { get; set; } = new ObservableCollection<TestCase>() { new TestCase() { TestNo = 1 } };

		public MainViewModel()
		{
			Day = DateTime.Today.Day;
			Year = DateTime.Today.Year;
		}

		public void CreateFiles()
		{
			string solutionDirPath = @$"..\..\AdventOfCode{Year}.Solutions\Day{Day:D2}";
			string testDirPath = @$"..\..\AdventOfCode{Year}.Tests";

			Directory.CreateDirectory(solutionDirPath);

			// To add created files to projects:
			ProjectFilesUpdater prjUpdater = new ProjectFilesUpdater(Year, Day);

			// Main files:
			DayFileCreator dayFileCreator = new DayFileCreator()
					.ForDay(Day, Year)
					.WithTitle(Title)
					.WithResult(UseNumericResult ? DayResultType.Numeric : DayResultType.String);

			if (ProcessorChoice != null)
			{
				if (ProcessorChoice != ProcessorChoiceType.Custom)
				{
					switch (ProcessorChoice)
					{
						case ProcessorChoiceType.IntProcessor_ValuesAsDigit:
							dayFileCreator.WithProcessor("IntProcessor<IntProcessingMode::ValuesAsDigits>", "int", ResultListName, "IntProcessor");
							break;
						case ProcessorChoiceType.IntProcessor_ValuePerLine:
							dayFileCreator.WithProcessor("IntProcessor<IntProcessingMode::ValuePerLine>", "int", ResultListName, "IntProcessor");
							break;
						case ProcessorChoiceType.IntProcessor_ValuesAsCommaSeparatedLine:
							dayFileCreator.WithProcessor("IntProcessor<IntProcessingMode::ValuesAsCommaSeparatedLine>", "int", ResultListName, "IntProcessor");
							break;
						case ProcessorChoiceType.IntProcessor_ValuesAsSpaceSeparatedLine:
							dayFileCreator.WithProcessor("IntProcessor<IntProcessingMode::ValuesAsSpaceSeparatedLine>", "int", ResultListName, "IntProcessor");
							break;
					}
				}
				else if (ProcessorChoice == ProcessorChoiceType.Custom && !string.IsNullOrEmpty(Processor))
				{
					dayFileCreator.WithProcessor(Processor, Result, ResultListName);

					if (!string.IsNullOrEmpty(Context))
						dayFileCreator.WithContext(Context);
				}
			}

			using (FileStream dayHeaderFile = File.Create(@$"{solutionDirPath}\Day{Day:D2}_{dayFileCreator.TitleWithoutBlanks}.h"))
			{
				dayFileCreator.CreateHeader(dayHeaderFile);
				prjUpdater.AddHeaderFile(Path.GetFileName(dayHeaderFile.Name));
			}

			using (FileStream daySourceFile = File.Create(@$"{solutionDirPath}\Day{Day:D2}_{dayFileCreator.TitleWithoutBlanks}.cpp"))
			{
				dayFileCreator.CreateSource(daySourceFile, DaySTL);
				prjUpdater.AddSourceFile(Path.GetFileName(daySourceFile.Name));
			}

			List<string> lines = File.ReadAllLines(@$"{solutionDirPath}\..\Solutions{Year}.h").ToList();
			dayFileCreator.AddToSolutionHeader(lines);
			File.WriteAllLines(@$"{solutionDirPath}\..\Solutions{Year}.h", lines.ToArray());


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
			if (ProcessorChoice == ProcessorChoiceType.Custom && !string.IsNullOrEmpty(Processor))
			{
				ProcessorCreator processorCreator = new ProcessorCreator()
				.ForDay(Day, Year)
				.WithProcessor(Processor, Result, CreateResultType, ResultListName)
				.WithResultOptions(ResultOptions);

				if (!string.IsNullOrEmpty(Context))
					processorCreator.WithContext(Context, CreateContextType);

				processorCreator.WithTemplate(SelectedProcessorTemplate);

				if (CreateResultType && !string.IsNullOrWhiteSpace(Result))
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

				if (CreateContextType && !string.IsNullOrWhiteSpace(Context))
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
