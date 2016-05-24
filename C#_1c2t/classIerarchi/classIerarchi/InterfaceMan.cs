using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace classIerarchi
{
	interface InterfaceMan
	{
		void showInfo();
		String[] TimeTable { get; }
		String FirstName{ get; set; }
		String SecondName { get; set; }
		string this[int i]
		{
			get;
			set;
		}
		float Weight { get; set; }
		float Hight	{ get; set; }
		float Age { get; set; }
		String Sex { get; set; }
	}
}
