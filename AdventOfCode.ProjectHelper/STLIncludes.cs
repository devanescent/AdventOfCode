using System.ComponentModel;

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

	public class ProcessorSTLIncludes : INotifyPropertyChanged
	{
		private bool _stdAlgorithm, _regex, _stringStream;
		public bool UseStdAlgorithm
		{
			get => _stdAlgorithm;
			set
			{
				_stdAlgorithm = value;
				PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof(UseStdAlgorithm)));
			}
		}
		public bool UseRegex
		{
			get => _regex;
			set
			{
				_regex = value;
				PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof(UseRegex)));
			}
		}
		public bool UseStringStream
		{
			get => _stringStream;
			set
			{
				_stringStream = value;
				PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof(UseStringStream)));
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;
	}
}
