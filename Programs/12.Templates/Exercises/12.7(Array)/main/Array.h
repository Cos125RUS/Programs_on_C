#pragma once
#include <iostream>

using namespace std;

template<class T>
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
	T& operator[](int);
	const T& operator[](int)const;

private:
	int size;
	T* ptr;
};

