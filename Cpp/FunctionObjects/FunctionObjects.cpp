// FunctionObjects.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <list>
#include <iostream>
#include <string>

using namespace std;

template<typename Container, typename Value>
Value sum(const Container& c, Value v)
{
	for(auto x : c )
		v += x;
	return v;
}

template<typename T> class Less_than
{
	const T val;
public:
	Less_than(const T& in) : val(in) {}
	bool operator()(const T& x) const { return x < val; }
};

template<typename C, typename P>
int count(const C& c, P pred)
{
	int cnt = 0;
	for( auto x : c )
		if( pred(x) )
			++cnt;

	return cnt;
}

void f(const vector<int>& vec, const list<string>& lst, int x, const string& s)
{
	cout << "number of values less than " << x << ": " << count(vec,Less_than<int>(x)) << '\n';
	cout << "number of values less than " << s << ": " << count(lst,Less_than<string>(s)) << '\n';
}

void f2(const vector<int>& vec, const list<string>& lst, int x, const string& s)
{
	cout << "number of values less than " << x << ": " << count(vec,[&](int a) {return a < x;} ) << '\n';
	cout << "number of values less than " << s << ": " << count(lst,Less_than<string>(s)) << '\n';
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> a;
	list<string>  b;

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	b.push_back("Ante");
	b.push_back("Buba");
	b.push_back("Zvone");

	int res1 = sum(a, 0); cout << res1 << endl;

	Less_than<int> lti(10);
	Less_than<string> lts("Zvone");

	f(a, b, 2, "LePrd");

	return 0;
}

