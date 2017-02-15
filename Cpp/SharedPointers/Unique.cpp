#include "stdafx.h"

#include <memory>
#include <iostream>

#include "Header.h"

using namespace std;



unique_ptr<A> func(unique_ptr<A> inA)
{
	inA->f();

	return inA;
}

void func2(unique_ptr<A> &refA)
{
	refA->f();
}

void testUnique()
{
	std::unique_ptr<A> ptr(new A());

	// func(ptr);			// ovo ne radi jer nema copy constructor
	ptr = func(move(ptr));

	func2(ptr);
}