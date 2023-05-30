#pragma once
#include <iostream>
#include "Base1.h"
#include "Base2.h"

using std::ostream;

class Derived :
	public Base1, public Base2
{
	friend ostream& operator<<(ostream&, const Derived&);
public:
	Derived(int, char, double);
	double getReal() const;
private:
	double real;
};

