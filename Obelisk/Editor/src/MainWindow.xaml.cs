using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Interop;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Obelisk {

	/// <summary>
	/// Interaction logic for MainWindow.xaml
	/// </summary>
	public partial class MainWindow : Window {
		
		private Thread _thread;

		private bool _running = true;

		public MainWindow() {
			InitializeComponent();

			_thread = new Thread(
				() => {
					ObeliskEngine.Init();
					while (_running) {
						ObeliskEngine.Update();
						ObeliskEngine.Render();
					}
					ObeliskEngine.Shutdown();
				});
			
			_thread.Start();
		}

		private void MainWindow_OnClosing(object a_sender, CancelEventArgs a_e) {
			_running = false;
		}
	}

	public class ObeliskEngine {
		[DllImport("ObeliskEngine.dll", EntryPoint = "ObeliskApp_Init")]
		public static extern void Init();
		
		[DllImport("ObeliskEngine.dll", EntryPoint = "ObeliskApp_Shutdown")]
		public static extern void Shutdown();

		[DllImport("ObeliskEngine.dll", EntryPoint = "ObeliskApp_Update")]
		public static extern void Update();

		[DllImport("ObeliskEngine.dll", EntryPoint = "ObeliskApp_Render")]
		public static extern void Render();
	}
}

//HwndSource hwndSource = (HwndSource) PresentationSource.FromVisual(this);
//hwndSource.Handle;
