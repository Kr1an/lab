using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace classIerarchi
{
    class Man:InterfaceMan, IComparable<Man> ,IEquatable<Man>, IFormattable 
	{
		//hight, weight, age, sex,
		public const string TIMETABLE_UNKNOWN = "unknown";
		public const string SEX_FEMALE = "female";
		public const string SEX_MALE = "male";
		public const string SEX_UNKNOWN = "unknown";
		public const string NAME_UNKNOWN = "unknown";
		public const int VAR_UNINIT = -1;
		private const int DAYS_IN_WEEK = 7;

		private String sex;
		private float age;
		private float hight;
		private float weight;
		private String [] timeTable = new String [DAYS_IN_WEEK];
		private String firstName = Man.NAME_UNKNOWN;
		private String secondName= Man.NAME_UNKNOWN;

		public virtual void showInfo()
		{
			Console.Write("\tInfo about Man's object\n");
			Console.Write("Sex: " + Sex + " ;\n");
			Console.Write("First second names: " +FirstName + " " + SecondName+" ;\n");
			Console.Write("Age: "+ Age + " years;\n");
			Console.Write("Hight: " + Hight + "cm.;\n");
			Console.Write("Weight: " + Weight + "kg.;\n");
			Console.Write("\tTimeTable:\n");
			foreach (String tmp in this.timeTable)
			{
				if(tmp != Man.TIMETABLE_UNKNOWN)
					Console.WriteLine(tmp);
			}
			
		}

		public int CompareTo(Man other)
		{
			if(firstName != Man.NAME_UNKNOWN && other.firstName != Man.NAME_UNKNOWN	)
				return this.FirstName.CompareTo(other.FirstName);
			if (age != -1 && other.age != -1)
				return this.Age.CompareTo(other.Age);
			return this.Sex.CompareTo(other.Sex);
		}

		public bool Equals(Man other)
		{
			if (firstName != Man.NAME_UNKNOWN && other.firstName != Man.NAME_UNKNOWN)
				return this.Equals(other.FirstName);
			if (age != -1 && other.age != -1)
				return this.Age.Equals(other.Age);
			return this.Sex.Equals(other.Sex);
		}

		public string ToString(string format, IFormatProvider formatProvider)
		{
			return this.FirstName + " " + this.SecondName + " " + this.Age;
		}

		public String[] TimeTable { get { return this.timeTable; } }
		public String FirstName
		{
			get
			{
				return this.firstName;
			}
			set
			{
				this.firstName = value;
			}
		}

		public String SecondName
		{
			get
			{
				return this.secondName;
			}
			set
			{
				this.secondName = value;
			}
		}
		public string this[int i]
		{
			get
			{
				return timeTable[i];
			}
			set
			{
				timeTable[i] = value;
			}
		}

		public Man(String sex = Man.SEX_UNKNOWN, float age = Man.VAR_UNINIT, float hight = Man.VAR_UNINIT, float weight = Man.VAR_UNINIT)
		{
			this.sex = sex;
			this.age = age;
			this.hight = hight;
			this.weight = weight;

		}
		public float Weight
		{
			get
			{
				return this.weight;
			}
			set
			{
				if (value >= 0 && value <= 200)
					this.weight = value;
				else
					this.weight = -1;
			}
		}
		public float Hight
		{
			get
			{
				return this.hight;
			}
			set
			{
				if (value >= 0 && value <= 300)
					this.hight = value;
				else
					this.hight = -1;
			}
		}
		public float Age
		{
			get
			{
				return this.age;
			}
			set
			{
				if (value >= 0 && value <= 200)
					this.age = value;
				else
					this.age = -1;
			}
		}
		public String Sex
		{
			get
			{
				return this.sex;
			}
			set
			{
				if (String.Compare(value, Man.SEX_FEMALE) == 0 || String.Compare(value, Man.SEX_MALE) == 0)
				{
					this.sex = value;
				}
				else
				{
					this.sex = Man.SEX_UNKNOWN;
				}
			}
		}
	
    }
}
