using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
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
}
