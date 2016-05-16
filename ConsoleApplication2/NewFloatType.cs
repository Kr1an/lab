using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{

	class NewFloatType : IFormattable , IEquatable<NewFloatType>
	{
		 
		public delegate void testDelegate(int i);
		
		public event testDelegate testEvent;

		public void count(int i)
		{
			if (i == 0)
			{
				testEvent(i);
			}
		}

		public void message(int i)
		{
			Console.WriteLine("testDelegate event" + i);
			return;
		}
		public float newFloat { get; set; }

		public NewFloatType(float newFloat)
		{
			this.newFloat = newFloat;
		}

		public string ToString(string format, IFormatProvider formatProvider)
		{
			return Convert.ToString(this.newFloat);
		}

		public bool Equals(NewFloatType other)
		{
			return this.newFloat.Equals(other.newFloat);
		}
		public bool Equals(NewFloatType other, int place)
		{
			String[] str1 = new string[2];
			char[] temp = new char[1];
			temp[0] = '.';

			str1 = Convert.ToString(this.newFloat).Split(temp, StringSplitOptions.RemoveEmptyEntries);
			Console.WriteLine(str1[0] + "  " + str1[1]);
			return true;
		}

		static public NewFloatType operator +(NewFloatType firstNum, NewFloatType secNum)
		{
			return new NewFloatType(firstNum.newFloat + secNum.newFloat);
		}
		static public NewFloatType operator -(NewFloatType firstNum, NewFloatType secNum)
		{
			return new NewFloatType(firstNum.newFloat - secNum.newFloat);
		}
		static public NewFloatType operator /(NewFloatType firstNum, NewFloatType secNum)
		{
			return new NewFloatType(firstNum.newFloat / secNum.newFloat);
		}
		static public NewFloatType operator *(NewFloatType firstNum, NewFloatType secNum)
		{
			return new NewFloatType(firstNum.newFloat * secNum.newFloat);
		}
		static public NewFloatType operator !(NewFloatType secNum)
		{
			return ((secNum.newFloat>0)?(new NewFloatType(0)):(new NewFloatType(1)));
		}
		static public NewFloatType operator ++(NewFloatType firstNum)
		{
			return new NewFloatType(firstNum.newFloat+1);
		}
		static public NewFloatType operator --(NewFloatType firstNum)
		{
			return new NewFloatType(firstNum.newFloat-1);
		}

		public static implicit operator double(NewFloatType v)
		{
			return v.newFloat;
		}
		public static implicit operator int(NewFloatType v)
		{
			return (int)v.newFloat;
		}
		public static explicit operator float(NewFloatType v)
		{
			return (float)v.newFloat;
		}
	}
}
