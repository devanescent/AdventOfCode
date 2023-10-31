using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

using System.IO;
using System.Xml;
using System.Xml.Linq;

namespace AdventOfCode.ProjectHelper
{
	/// <summary>
	/// Interaction logic for MainWindow.xaml
	/// </summary>
	public partial class MainWindow : Window
	{
		MainViewModel mvm = new MainViewModel();
		public MainWindow()
		{
			InitializeComponent();
			DataContext = mvm;
		}

		private void CreateFiles_Click(object sender, RoutedEventArgs e)
		{			
			mvm.CreateFiles();
			MessageBox.Show("Files created successfully!", "Create files", MessageBoxButton.OK);
			Application.Current.Shutdown();
		}

		private void DeleteTextCase_Click(object sender, RoutedEventArgs e)
		{
			Control ctrl = sender as Control;
			TestCase tc = ctrl.DataContext as TestCase;

			mvm.TestCaseList.Remove(tc);

			// Reassign test numbers:
			for (int i = 0; i < mvm.TestCaseList.Count; ++i)
				mvm.TestCaseList[i].TestNo = i + 1;
		}

		private void AddTestCase_Click(object sender, RoutedEventArgs e)
		{
			int testNo = 1;
			if (mvm.TestCaseList.Any())
				testNo = mvm.TestCaseList.Max(tc => tc.TestNo) + 1;

			mvm.TestCaseList.Add(new TestCase() { TestNo = testNo });
		}
	}
}
