using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
	class Program
	{
		static void Main(string[] args)
		{
			var ana = new { a = 34, b = "qwe", c = true };
			Console.WriteLine(ana.a);
			NewFloatType obj = new NewFloatType((float)45.23);
			NewFloatType obj1 = new NewFloatType((float)45.23);
			Dictionary<String, String> dic1 = new Dictionary<string, string>();
			dic1.Add("qwe", "йцу");
			dic1.Add("asd", "фыв");
			Console.WriteLine(dic1["qwe"]);
			dic1.Remove("qwe");
			Console.WriteLine(dic1["qwe"]);
			NewFloatType obj3 = obj + obj1;
			Console.WriteLine(obj.ToString());
			float temp = (float)obj3;
			Console.WriteLine(temp);
			obj.testEvent += obj.message;
			try
			{
				obj.count(0);
			}
			catch (Exception ex)
			{
				Console.WriteLine("Exception");
			}
			//obj.testEvent += obj.message;
			
		}
	}
}
