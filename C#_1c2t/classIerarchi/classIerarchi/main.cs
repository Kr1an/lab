using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;



namespace classIerarchi
{

	class main
	{
		private int[] mass;
		private int[][] mass2;
		public int this[int q, int j]
		{
			get
			{
				return mass2[q][j];
			}
		}
		public int this[int i]
		{
			get { return mass[i]; }
			set { }
		}
		static int testInt;
		static int TestInt { get; set; }
		public static void Main(String[] args)
		{

			
		}
	}
}
