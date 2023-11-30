#pragma once
#include <iostream>

using namespace std;

template<class T>
class Array
{
	//friend ostream& operator<<(ostream&, const Array&);
	//friend istream& operator>>(istream&, Array&);

public:
	Array(int = 10);
private:
	int size;
	T* ptr;
};

