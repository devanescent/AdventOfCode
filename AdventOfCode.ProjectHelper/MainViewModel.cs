using System.IO;
using System.Linq;

namespace AdventOfCode.ProjectHelper
{
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

		public void CreateFiles()
		{
			string TitleWithoutBlanks = string.Concat(Title.Where(c => c != ' '));

			string DayBaseInclude = "Day";
			if (Processor != string.Empty) DayBaseInclude += "T";
			if (Context != string.Empty) DayBaseInclude += "C";

			string dirPath = @$"..\..\AdventOfCode{Year}.Solutions\Day{Day}";
			Directory.CreateDirectory(dirPath);


			ProjectFilesUpdater prjUpdater = new ProjectFilesUpdater(Year, Day);

			// Main files:
			DayFileCreator DayFileCreator = new DayFileCreator()
					.ForDay(Day, Year)
					.WithTitle(Title)
					.WithProcessor(Processor, Result);

			using (FileStream DayHeaderFile = File.Create(@$"{dirPath}\Day{Day}_{TitleWithoutBlanks}.h"))
			{
				DayFileCreator.CreateHeader(DayHeaderFile);
				prjUpdater.AddHeaderFile(Path.GetFileName(DayHeaderFile.Name));
			}

			using (FileStream DaySourceFile = File.Create(@$"{dirPath}\Day{Day}_{TitleWithoutBlanks}.cpp"))
			{
				DayFileCreator.CreateSource(DaySourceFile, DaySTL);
				prjUpdater.AddSourceFile(Path.GetFileName(DaySourceFile.Name));
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
					using (FileStream processingResultFile = File.Create(@$"{dirPath}\{Result}.h"))
					{
						ProcessorCreator.CreateHeaderResult(processingResultFile);
						prjUpdater.AddHeaderFile(Path.GetFileName(processingResultFile.Name));
					}
				}

				using (FileStream ProcessorHeaderFile = File.Create(@$"{dirPath}\{Processor}.h"))
				{
					ProcessorCreator.CreateHeader(ProcessorHeaderFile);
					prjUpdater.AddHeaderFile(Path.GetFileName(ProcessorHeaderFile.Name));
				}

				using (FileStream ProcessorSourceFile = File.Create(@$"{dirPath}\{Processor}.cpp"))
				{
					ProcessorCreator.CreateSource(ProcessorSourceFile, ProcSTL);
					prjUpdater.AddSourceFile(Path.GetFileName(ProcessorSourceFile.Name));
				}

				if (!string.IsNullOrEmpty(Context))
				{
					using (FileStream ContextFile = File.Create(@$"{dirPath}\{Context}.h"))
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
