// Basics.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <complex>
#include <iostream>
#include <vector>

#include "Header.h"

void TestingComplex()
{
	std::complex<double> a(2,2), b(3,3), c;

	c = a + b;

	std::cout << c << std::endl;

	auto d = sin(c);
	// dostupne funkcije pow, log, cos, tan, sqrt, exp;

	std::cout << d << std::endl;
}

void TestingInitializers()
{
	int a[5] = {1, 2, 3, 4, 5 };

	for( auto& x : a )
	{
		x *= 2;
		std::cout << x << std::endl;
	}

	for( auto x : a )
		std::cout << x << std::endl;


	//NE MOŽE!!!
	//for( auto x : {2 , 4, 6, 8, 10 } )
	//	std::cout << x << std::endl;

	// NE MOŽE!!!
	//std::vector<int> vec = { 1, 2, 3, 4, 5 };
}

void TestingCopying()
{
	std::vector<int> v1;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	auto v2 = v1;

	v2[0] = 500;
	for( auto x : v1 )
		std::cout << x << std::endl;

	auto v3(v1);
	v3[0] = 500;
	for( auto x : v1 )
		std::cout << x << std::endl;
}

class MovableVector
{
public:
	MovableVector(int i)
	{
	}
	MovableVector(MovableVector && a )
	{
	}
};

void TestingMoving()
{
	MovableVector a(1000);
	MovableVector b(1000);

	// this is error - http://stackoverflow.com/questions/31264984/c-compiler-error-c2280-attempting-to-reference-a-deleted-function-in-visual
	//a = std::move(b);
}

enum class Color { red, green, blue };



int _tmain(int argc, _TCHAR* argv[])
{
	//TestingComplex();
	//TestingInitializers();
	//TestingCopying();

	Color col = Color::green;

	//TestPair();
	//TestPairMoveSemantics();
	//TestPairReferences();
	
	//TestTuples();
	//TestTupleReferences();
	TestCreateTupleWithReferences();


	return 0;
}

