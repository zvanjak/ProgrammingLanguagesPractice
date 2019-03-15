// Containers_and_Algorithms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

struct Entry {
	string name;
	int number;
};

ostream& operator<<(ostream& os, const Entry& e)
{
	return os << "{\"" << e.name << "\", " << e.number << "}";
}

istream& operator>>(istream& is, Entry& e)
//read { "name" , number } pair. Note: formatted with { " " , and }
{
	char c, c2;
	if (is>>c && c=='{' && is>>c2 && c2=='"') {		//start with a { "
		string name;								//the default value of a string is the empty string: ""
		while (is.get(c) && c!='"')					//anything before a " is part of the name
			name+=c;
		
		if (is>>c && c==',') {
			int number = 0;
			if (is>>number>>c && c=='}') {			//read the number and a }
				e.name = name;
				e.number = number;					//assign to the entry
				return is;
			}
		}
	}
	is.setf(ios_base::failbit);			//register the failure in the stream

	return is;
}
void func2()
{
	vector<int> nums(20);

	for(int i=0; i<20; i++ )
		nums[i] = i;

	copy (nums.begin(), nums.end(), ostream_iterator<int>(cout," "));
    cout << endl;

	auto endIter = remove_if(begin(nums), end(nums), [](int x) { return x%2 == 0; } );
	copy (nums.begin(), nums.end(), ostream_iterator<int>(cout," "));
    cout << endl;

	nums.erase(endIter, nums.end());
	copy (nums.begin(), nums.end(), ostream_iterator<int>(cout," "));
    cout << endl;
}

bool isPrime(int x)
{
	for( int i=2; i<=sqrt(x); i++ )
		if( x % i == 0 )
			return false;

	return true;
}

void func1()
{
	vector<int> numbers(30);
	vector<int> origNumbers(30);

	for(int i=0; i<30; i++ )
		numbers[i] = rand() % 30;

	copy(begin(numbers), end(numbers), origNumbers.begin());

	sort(begin(numbers), end(numbers));
	// sort(begin(numbers), end(numbers), [](int x, int y) { return abs(x) > abs(y); } );

	cout << "Orig numbers" << endl;
	for_each(begin(numbers), end(numbers), [](int x) { cout << x << endl; });

	// idemo sad izvaditi sve unique i sve one koji su duplici u zasebne kolekcije
	// PRVI nacin - rezervirati mjesta unaprijed
	vector<int> uniqueNumbers(30);
	unique_copy(begin(numbers), end(numbers), uniqueNumbers.begin());
	//for_each(begin(uniqueNumbers), end(uniqueNumbers), [](int x) { cout << x << endl; });

	// DRUGI nacin - koristiti back_inserter
	uniqueNumbers.clear();
	unique_copy(begin(numbers), end(numbers), back_inserter(uniqueNumbers));
	//cout << "Unique numbers" << endl;
	//for_each(begin(uniqueNumbers), end(uniqueNumbers), [](int x) { cout << x << endl; });

	// idemo sad vidjeti kako bi izvukli one koji su dupli
	vector<int> dupliNumbers;
	set_difference(begin(numbers), end(numbers), begin(uniqueNumbers), end(uniqueNumbers), back_inserter(dupliNumbers));
	cout << "Dupliæi" << endl;
	for_each(begin(dupliNumbers), end(dupliNumbers), [](int x) { cout << x << endl; });

	// idemo sad iskopirati sve oni koji su prim brojevi
	vector<int> primNumbers;
	copy_if(begin(uniqueNumbers), end(uniqueNumbers), back_inserter(primNumbers), [](int x) { return isPrime(x); } );
	cout << "Prosti brojevi" << endl;
	for_each(begin(primNumbers), end(primNumbers), [](int x) { cout << x << endl; });


}

int _tmain(int argc, _TCHAR* argv[])
{
	//vector<Entry> phone_book = {
	//	{"David Hume",123456},
	//	{"Karl Popper",234567},
	//	{"Bertrand Ar thur William Russell",345678}
	//};
	
	Entry tempInit[] = {
		{"David Hume",123456},
		{"Karl Popper",234567},
		{"Bertrand Arthur William Russell",345678}
	};

	vector<Entry> phone_book(&tempInit[0], &tempInit[2]);

	//func1();
	func2();

	return 0;
}

