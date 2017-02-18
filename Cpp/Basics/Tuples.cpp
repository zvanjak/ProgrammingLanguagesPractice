#include "stdafx.h"

#include <tuple>
#include <string>
#include <iostream>

#include "Header.h"

using namespace std;

void TestTuples()
{
	tuple<string, int, int, float> t;

	tuple<int, float, string> t1(10, 3.14, "Pero");

	cout << get<0>(t1) << endl;
	cout << get<1>(t1) << endl;
	cout << get<2>(t1) << endl;

	auto p = make_tuple(20, 2.71, "Ante");

	t1 = p;
}

void TestTupleReferences()
{
	int a = 10;
	float b = 3.14F;
	string c = "Pero";
	
	tuple<int&, float&, string&> t1{a, b, c };

	a = 20;

	cout << get<0>(t1) << endl;

	get<0>(t1) = 30;

	cout << a << endl;
}

void TestTupleRef2()
{
	std::string s;
	
	auto x =std::make_tuple(s);			//x is of type tuple<string>
	std::get<0>(x) ="my value";			//modifies x but not s
	
	auto y =std::make_tuple(ref(s));	//y is of type tuple<string&>, thus y refers to s
	std::get<0>(y) ="my value";			//modifies y
}

void TestCreateTupleWithReferences()
{
	std::tuple <int,float,std::string> t(77,1.1,"more light");
	
	int i;
	float f;
	std::string s;
	
	std::tie(i,f,s) = t;		//assigns values of t to i, f, and s

	cout << i << ", " << f << ", " << s << endl;

	i = 88;

	cout << "tuple[i] = " << get<0>(t) << endl;
}