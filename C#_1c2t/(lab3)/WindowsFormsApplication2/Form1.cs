using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ClassLibrary1;

namespace WindowsFormsApplication2
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}
		string[] files, paths;

		private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
		{
			axWindowsMediaPlayer1.URL = paths[listBox1.SelectedIndex];
		}

		private void Form1_Load(object sender, EventArgs e)
		{

		}

		private void button6_Click(object sender, EventArgs e)
		{
			if (openFileDialog1.ShowDialog() == System.Windows.Forms.DialogResult.OK)
			{
				files = openFileDialog1.SafeFileNames;
				paths = openFileDialog1.FileNames;
				for (int i = 0; i < files.Length; i++)
				{
					listBox1.Items.Add(files[i]);
				}
			}

		}

		private void button5_Click(object sender, EventArgs e)
		{
			
			axWindowsMediaPlayer1.Ctlcontrols.pause();
		}

		private void tableLayoutPanel1_Paint(object sender, PaintEventArgs e)
		{

		}

		private void timer1_Tick(object sender, EventArgs e)
		{
			label1.Text = ClassLibrary1.dllClass.recentTime();
		}

		private void button4_Click(object sender, EventArgs e)
		{
			listBox1.Items.Clear();
			axWindowsMediaPlayer1.Ctlcontrols.stop();
			

		}
	}
}
