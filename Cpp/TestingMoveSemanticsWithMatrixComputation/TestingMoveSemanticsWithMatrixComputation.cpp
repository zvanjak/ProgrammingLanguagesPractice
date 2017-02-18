// TestingMoveSemanticsWithMatrixComputation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Matrix
{
public:
	Matrix(int row, int col) : _rowNum(row), _colNum(col)
	{
		_ptr = new int*[row];
		for (int i = 0; i < row; i++)
			_ptr[i] = new int[col];
	}

private:
	int _rowNum, _colNum;
	int **_ptr;
};
int main()
{
    return 0;
}

