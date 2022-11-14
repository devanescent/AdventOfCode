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
	}
}
