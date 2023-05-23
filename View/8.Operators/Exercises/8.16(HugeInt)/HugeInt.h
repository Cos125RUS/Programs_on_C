#pragma once
#include <iostream>

using namespace std;

class HugeInt
{
	friend ostream& operator<<(ostream&, const HugeInt&);

public:
	HugeInt(long = 0);
	HugeInt(const char*);
	HugeInt operator+(const HugeInt&);
	HugeInt operator+(int);
	HugeInt operator+(const char *);

private:
	short integer[30];
	//static int count;
};

