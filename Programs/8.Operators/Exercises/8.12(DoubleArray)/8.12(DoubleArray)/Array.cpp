#include "Array.h"
#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include <cassert>
#include <string.h>
#include <errno.h>
#include <ctype.h>

using namespace std;

Array::Array(int rows, int columns)
{
	sizeRow = (rows > 0 ? rows : 10);
	sizeColumn = (columns > 0 ? columns : 10);
	ptr = new int* [sizeRow];
	for (int i = 0; i < sizeRow; i++)
	{
		ptr[i] = new int[sizeColumn];
		assert(ptr[i] != 0);
		for (int j = 0; j < sizeColumn; j++)
			ptr[i][j] = 0;
	}
}

Array::Array(const Array& init) : sizeRow(init.sizeRow), sizeColumn(init.sizeColumn)
{
	ptr = new int* [sizeRow];
	for (int i = 0; i < sizeRow; i++)
	{
		ptr[i] = new int[sizeColumn];
		assert(ptr[i] != 0);
		for (int j = 0; j < sizeColumn; j++)
			ptr[i][j] = init.ptr[i][j];
	}
}

Array::~Array()
{
	for (int i = 0; i < sizeRow; i++)
		delete[] ptr[i];
}

int Array::getSizeRows() const { return sizeRow; }
int Array::getSizeColumns() const { return sizeColumn; }

int& Array::operator()(int row, int column)
{
	assert(0 <= row && row < sizeRow);
	assert(0 <= column && column < sizeColumn);

	return ptr[row][column];
}

const int& Array::operator()(int row, int column) const
{
	assert(0 <= row && row < sizeRow);
	assert(0 <= column && column < sizeColumn);

	return ptr[row][column];
}

istream& operator>>(istream& input, Array& a)
{
	for (int i = 0; i < a.sizeRow; i++)
		for (int j = 0; j < a.sizeColumn; j++)
			input >> a.ptr[i][j];

	return input;
}

ostream& operator<<(ostream& output, const Array& a)
{
	for (int i = 0; i < a.sizeRow; i++)
	{
		for (int j = 0; j < a.sizeColumn; j++)
			output << ' ' << a.ptr[i][j];
		cout << endl;
	}

	return output;
}