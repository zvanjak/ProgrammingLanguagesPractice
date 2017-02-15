void TestUnique();

void TestSharedObjectInstance();
void TestSharedInContainer();

void TestWeakPtr();
void TestWeakPtr2();
void TestWeakPtr3();

#include <memory>
#include <iostream>


class A
{
public:
	A()	 { std::cout << "ctor" << std::endl; }
	~A() { std::cout << "destructor" << std::endl; }

	void f() { std::cout << "A::f() called" << std::endl; }
};


class B 
{
public:
	B(std::shared_ptr<A> inA)
	{
		refA = inA;
	}

private:
	std::shared_ptr<A> refA;
};
