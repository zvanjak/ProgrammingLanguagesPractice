// Lambdas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_modulo(const vector<int>& v, ostream& os, int m)
{
	for_each(begin(v), end(v), [&os, m](int x) { if( x % m == 0) os << x << endl; } 
	);
}

void g(double y)
{
	auto z1 = [=](int x){ return x+y; };						//return type is double
	
	//auto z2 = [=,y]{ if (y) return 1; else return 2; };		//error : body too complicated for return type deduction
	
	auto z3 =[y]() { return 1; };							//return type is int
	
	//auto z4 = [=,y]()−>int { if (y) return 1; else return 2; }	//OK: explicit return type
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec(100);

	for( int i=0; i<100; i++ )
		vec.push_back(rand() % 500);

	sort(vec.begin(), vec.end());

	sort(vec.begin(), vec.end(), [](int x, int y) { return abs(x) > abs(y); });

	bool sensitive = true;
	sort(vec.begin(),vec.end(), [sensitive](int x, int y) { return sensitive ? x<y : abs(x)<abs(y); } );

	return 0;
}

