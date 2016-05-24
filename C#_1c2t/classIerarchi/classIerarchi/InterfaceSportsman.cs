using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace classIerarchi
{
	interface InterfaceSportsman : InterfaceMan
	{
		float CarrerDuration{ get; set; }
		void showCarrerDuration();
		String LastCompitition { set; }
	}
	
}
