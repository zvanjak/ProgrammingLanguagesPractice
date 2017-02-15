// ArraySumInDifferentWays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <iostream>
#include <numeric>
#include <functional>

using std::vector;

int array_sum1(vector<int> &data)
{
	int sum = 0;
	for (int i = 0; i < data.size(); i++)
		sum += data[i];
	
	return sum;
}

int array_sum2(vector<int> &data)
{
	int sum = 0;
	for (auto a : data)
		sum += a;

	return sum;
}

int array_sum3(vector<int> &data)
{
	return std::accumulate(begin(data), end(data), 0);
}

int array_sum_squares(vector<int> &data)
{
	return std::accumulate(begin(data), end(data), 0, [](int partial, int x){ return partial + x*x; });
}

int array_sum4_help(vector<int> data, int n)
{
	if (n >= data.size())
		return 0;
	else
		return data[n] + array_sum4_help(data, n + 1);
}

int array_sum4(vector<int> &data)
{
	return data[0] + array_sum4_help(data, 1);
}

int array_sum5(vector<int> &data)
{
	std::function<int(int)> lambda;
	lambda = [&lambda, &data](int n) {
		if (n == 0)
			return 0;
		else
			return data[n] + lambda(n - 1);
	};

	if (data.size() == 0)
		return 0;
	else
		return data[data.size() - 1] + lambda(data.size() - 1);
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> data(100);

	for (auto &x : data)
		x = rand() % 100;

	std::cout << "Sum 1 " << array_sum1(data) << std::endl;
	std::cout << "Sum 2 " << array_sum2(data) << std::endl;
	std::cout << "Sum 3 " << array_sum3(data) << std::endl;
	std::cout << "Sum 4 " << array_sum4(data) << std::endl;
	std::cout << "Sum 5 " << array_sum5(data) << std::endl;

	return 0;
}

