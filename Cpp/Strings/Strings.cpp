// Strings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class MyString
{
public:
	MyString(const char *value)
	{
	}
	~MyString()
	{
	}

	// uz ovakvu funkciju, možemo pristupati podacima preko data poitnera
	//operator char * () const
	//{
	//	return data;
	//}

	// uz ovakvu, možemo sprijeèiti pridruživanje MyStringa u char * ('initializing' : cannot convert from 'const MyString' to 'char *')
	operator const char * () const
	{
		return data;
	}
private:
	char * data;
};

int _tmain(int argc, _TCHAR* argv[])
{
	// konstruktori
	string s0;							//the empty string
	string s1 ("As simple as that!");		//construct from C-style string
	string s2 (s1);							//copy constr uctorAlmost always, the destructor is implicitly invoked.
	string s3(7, 'a');

	puts("Unesi niz stringova, Ctrl+Z za kraj");
	vector<string> lines;
	for (string s; getline(cin,s);)
		lines.push_back(s);
	
	// testing constness
	const MyString B("Hello World");

	// char * str = B;

	//str[1] = 'a';

	return 0;
}

