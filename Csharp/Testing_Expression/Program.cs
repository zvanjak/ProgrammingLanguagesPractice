using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Linq.Expressions;

namespace Testing_Expression
{
	class Program
	{
		static void Main(string[] args)
		{
			Expression<Func<double, double>> a = x => x * x;

			Console.WriteLine("Value = {0}", a.Compile()(2) );
		}
	}
}
