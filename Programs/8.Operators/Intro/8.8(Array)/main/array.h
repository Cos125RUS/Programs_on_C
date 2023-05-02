#pragma once
#include <iostream>

using namespace std;

class Array
{
	friend ostream& operator<<(ostream&, const Array&);
	friend istream& operator>>(istream&, Array&);

public:
	Array(int = 10);
	Array(const Array&);
	~Array();
	int getSize() const;
	const Array& operator=(const Array&);
	bool operator==(const Array&) const;
	bool operator!=(const Array& right) const { return !(*this == right); }
	int& operator[](int);
	const int& operator[](int)const;
	static int getArrayCount();

private:
	int size;
	int* ptr;
	static int arrayCount;
};

