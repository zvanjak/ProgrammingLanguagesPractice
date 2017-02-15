#include "stdafx.h"

#include <utility>
#include <string>
#include <iostream>
#include <functional>

#include "Header.h"

using namespace std;

void TestPair()
{
	std::pair<int, std::string> p(42, "Pero");

	auto q = std::make_pair(42, "Ante");

	cout << p.first << " " << p.second << endl;

	// q = p;				// ovaj assignment NE RADI!!!!!
	p = q;
}

void TestPairMoveSemantics()
{
	string a("Ante"), b("Marko");
	
	char *pch = &(a[0]);

	cout << "a = " << a << ", b = " << b << endl;
	cout << "&a = " << (int *) pch << endl;

	auto p = make_pair(std::move(a), std::move(b));

	cout << "a = " << a << "(prazan string)" << endl;
	cout << "p.first = " << p.first << ", p.second = " << p.second << endl;
	cout << "&p.first = " << (int *) (&p.first[0]) << endl;
}

void TestPairReferences()
{
	int broj = 0;

	pair<int&, int&> p(std::ref(broj), std::ref(broj));

	auto q = std::make_pair(std::ref(broj), std::ref(broj));

	++q.first;
	++q.second;

	++p.first;
	++p.second;

	cout << "broj = " << broj;
}