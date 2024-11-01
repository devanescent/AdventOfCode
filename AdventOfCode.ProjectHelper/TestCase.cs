using System.Collections.Generic;
using System.ComponentModel;

namespace AdventOfCode.ProjectHelper
{
	public class TestCase : INotifyPropertyChanged
	{
		// Because the helper tool is only supposed to be used once per day,
		// the created test cases are only for part 1
		public int Part { get; private set; } = 1;

		private int _testNo;
		public int TestNo
		{
			get => _testNo;
			set
			{
				_testNo = value;
				PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof(TestNo)));
			}
		}

		public List<string> Data { get; set; }
		public bool InlineData { get; set; } = false;	// Single line of input can be inlined within the test method

		public string Result { get; set; }

		public event PropertyChangedEventHandler PropertyChanged;
	}
}
