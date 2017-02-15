#include "stdafx.h"

#include <memory>
#include <vector>
#include <iostream>
#include <string>

#include "Header.h"

using namespace std;


void func3(shared_ptr<A> inA)
{
	cout << "u funkciji use_count = " << inA.use_count() << endl;

	inA->f();
}

void TestSharedObjectInstance()
{
	// kreiramo objekt
	auto s = make_shared<A>();

	cout << "nakon kreiranja use_count = " << s.use_count() << endl;
	
	auto b = new B(s);

	cout << "nakon copy ctor-a use_count = " << s.use_count() << endl;

	B c(s);

	cout << "nakon drugog copy ctor-a use_count = " << s.use_count() << endl;

	func3(s);

	cout << "nakon slanja i povratka iz funkcije use_count = " << s.use_count() << endl;

	s->f();

	delete b;
}

void TestSharedInContainer()
{
	// creating 2 strings
	shared_ptr<string> pNico(new string("nico"));
	shared_ptr<string> pJutta(new string("jutta"));

	cout << "use_count for Nico before putting in container: " << pNico.use_count() << endl;
	cout << "use_count for Jutta before putting in container: " << pJutta.use_count() << endl;

	(*pNico)[0] = 'N';
	pJutta->replace(0,1,"J");

	vector<shared_ptr<string>> whoMadeCoffee;
	whoMadeCoffee.push_back(pJutta);
	whoMadeCoffee.push_back(pJutta);
	whoMadeCoffee.push_back(pNico);
	whoMadeCoffee.push_back(pJutta);
	whoMadeCoffee.push_back(pNico);

	cout << "use_count for Nico AFTER before putting in container: " << pNico.use_count() << endl;
	cout << "use_count for Jutta AFTER before putting in container: " << pJutta.use_count() << endl;

	//printallelements
	cout << "all elements: " << endl;
	for (auto ptr :whoMadeCoffee) {
		cout << *ptr << " ";
	}
	cout << endl;
	
	//overwriteanameagain
	*pNico ="Nicolai";
	
	cout << "all elements after change Nico -> Nicolai: " << endl;
	for (auto ptr :whoMadeCoffee) {
		cout << *ptr << " ";
	}
	
	cout << endl;
}