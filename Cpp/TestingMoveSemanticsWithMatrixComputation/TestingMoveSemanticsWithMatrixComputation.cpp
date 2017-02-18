// TestingMoveSemanticsWithMatrixComputation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Matrix
{
public:
	Matrix(int row, int col) : _rowNum(row), _colNum(col)
	{
		puts("In ctor");
		_ptr = new int*[row];
		for (int i = 0; i < row; i++)
			_ptr[i] = new int[col];
	}
	Matrix(const Matrix& b) : _rowNum(b._rowNum), _colNum(b._colNum)
	{
		puts("In copy ctor");
		_ptr = new int*[b._rowNum];
		for (int i = 0; i < b._rowNum; i++)
			_ptr[i] = new int[b._colNum];
	}
	~Matrix()
	{
		puts("In destructor");
		for (int i = 0; i < _rowNum; i++)
			delete[]_ptr[i];

		delete[]_ptr;
	}

	Matrix& operator=(const Matrix &b)
	{
		puts("In operator =");
		// free existing storage

		return *this;
	}
	Matrix operator+(const Matrix &b)
	{
		puts("In addition");
		Matrix ret(*this);

		// add b

		return *this;
	}
	Matrix operator-(const Matrix &b)
	{
		puts("In substraction");

		Matrix ret(*this);

		// sub b

		return *this;
	}
	Matrix operator*(const Matrix &b)
	{
		puts("In multiplication");

		Matrix ret(*this);

		// mul

		return *this;
	}

private:
	int _rowNum, _colNum;
	int **_ptr;
};
int main()
{
	Matrix a(2, 2), b(2, 2), c(2, 2), d(2, 2), e(2, 2), res(2, 2);

	res = a * (b + c) *(d + e);

    return 0;
}

