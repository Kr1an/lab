using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace classIerarchi
{
	class CompititionList
	{
		public String NameOfCompitition;
		public CompititionList(String value)
		{
			this.NameOfCompitition = value;
		}
	};
	class Sportsman : Man , InterfaceSportsman
	{
		public const int AGE_MAX = 80;
		private float carrerDuration;
		
		private List<CompititionList> compititionList;

		
		public String LastCompitition
		{
			set
			{
				compititionList.Add(new CompititionList(value));
			}
		}

		public void ShowCompititionList()
		{
			Console.Write("\tCompititionList:\n");
			foreach (CompititionList tmp in compititionList)
			{
				if (tmp.NameOfCompitition != Man.TIMETABLE_UNKNOWN)
					Console.WriteLine(tmp.NameOfCompitition);
			}
		}

		public override void showInfo()
		{
			Console.Write("\tInfo about Sportsman's object\n");
			Console.Write("Sex: " + Sex + " ;\n");
			Console.Write("First second names: " + FirstName + " " + SecondName + " ;\n");
			Console.Write("Age: " + Age + " years;\n");
			Console.Write("Hight: " + Hight + "cm.;\n");
			Console.Write("Weight: " + Weight + "kg.;\n");
			Console.Write("CarrerDuration: " + CarrerDuration + " ;\n");
			Console.Write("\tTimeTable:\n");
			foreach (String tmp in TimeTable)
			{
				if (tmp != Man.TIMETABLE_UNKNOWN)
					Console.WriteLine(tmp);
			}

		}

		public Sportsman(String sex = Man.SEX_UNKNOWN, float age = Man.VAR_UNINIT, float hight = Man.VAR_UNINIT, float weight = Man.VAR_UNINIT, float carrerDuration = Man.VAR_UNINIT):base( sex, age, hight, weight )
		{
			CarrerDuration = carrerDuration;
		}
		public float CarrerDuration
		{
			get
			{
				return this.carrerDuration;
			}
			set
			{
				if(value >=0 && value <= ((this.Age!=Sportsman.VAR_UNINIT)?(this.Age):(Sportsman.AGE_MAX)))
				{
					this.Age = value;
				}
				else
				{
					this.Age = Sportsman.VAR_UNINIT;
				}
			}
		}
		public void showCarrerDuration()
		{
			Console.Write("CarrerDuration: " + CarrerDuration);
		}


	}
}
