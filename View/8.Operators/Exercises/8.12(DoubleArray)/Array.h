#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Array
{
	friend ostream& operator<<(ostream&, const Array&);
	friend istream& operator>>(istream&, Array&);

public:
	Array(int = 10, int = 10);
	Array(const Array&);
	~Array();
	int getSizeRows() const;
	int getSizeColumns() const;
	int& operator()(int, int);
	const int& operator()(int, int)const;

private:
	int sizeRow;
	int sizeColumn;
	int** ptr;
};
