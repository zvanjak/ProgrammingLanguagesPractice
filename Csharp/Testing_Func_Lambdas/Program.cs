using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Testing_Func_Lambdas
{
	class Program
	{
		public static double Integrate(Func<double, double> inFunc, double a, double b)
		{
			return (inFunc(a) + inFunc(b)) / 2.0;
		}
		static void Main(string[] args)
		{
			Integrate(Math.Sin, 0, 1);

			Integrate((a) => a * a, 0, 1);
		}
	}
}
