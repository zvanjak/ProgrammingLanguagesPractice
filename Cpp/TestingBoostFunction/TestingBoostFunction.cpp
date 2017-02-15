// TestingBoostFunction.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "boost\function.hpp"
#include "boost\bind.hpp"

struct int_div { 
	float operator()(int x, int y) const 
	{ 
		return ((float)x)/y; 
	}; 
};

float mul_ints(int x, int y) 
{ 
	return ((float)x) * y; 
}

struct X {
	int foo(int a)
	{
		return 2 * a;
	}
};

// Funkcija za integriranje kao dio strukture/klase uz overload operatora()
struct integrate_test_func {
	double operator()(double x) const 
	{ 
		return ((double)x*x); 
	}; 
};

// Samostalna funkcija za integriranje
double int_func(double x)
{
	return x * x;
}

// Funkcija za integriranje kao èlanska  funkcija klase
class TestClass
{
public:
	double int_func2(double x)
	{
		return x*x;
	}
};

double Integrate(boost::function<double (double x)> func, double low, double high)
{
	return (func(low) + func(high)) / 2.0;
}


void IllustrateCall()
{
	double r1 = Integrate(integrate_test_func(), 0, 1);
	double r2 = Integrate(int_func, 0, 1);

	TestClass tc;
	double r3 = Integrate(std::bind1st(std::mem_fun(&TestClass::int_func2), &tc), 0, 1);

	//double r4 = Integrate(&TestClass::int_func2, 0, 1);
}

int _tmain(int argc, _TCHAR* argv[])
{
	boost::function<float (int x, int y)> f;

	f = int_div();
	std::cout << f(5, 3) << std::endl;

	// pozivanje slobodne funkcije
	f = &mul_ints;
	std::cout << f(5, 3) << std::endl;

	// pozivanje èlanske funkcije
	boost::function<int (X*, int)> f2;
	f2 = &X::foo;
	X x;
	f2(&x, 5);

	// bindanje na èlansku funkciju
	boost::function<int (int)> f3;
	X x2;
	f3 = std::bind1st(std::mem_fun(&X::foo), &x2);
	f3(5); // Call x.foo(5)

	return 0;
}

