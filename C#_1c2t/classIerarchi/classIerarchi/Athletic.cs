using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace classIerarchi
{
	class Athletic : Sportsman, InterfaceDifferentSports
	{
		public const String sport = "Athletic";
		public override void showInfo()
		{
			Console.Write("\tInfo about Athletic's object\n");
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
		public Athletic(String sex = Man.SEX_UNKNOWN, float age = Man.VAR_UNINIT, float hight = Man.VAR_UNINIT, float weight = Man.VAR_UNINIT, float carrerDuration = Man.VAR_UNINIT):base( sex, age, hight, weight, carrerDuration )
		{
			
		}
	}
}
