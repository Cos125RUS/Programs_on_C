#include "Derived.h"

Derived::Derived(int i, char c, double f)
	:Base1(i), Base2(c), real(f) {};

double Derived::getReal() const { return real; }

ostream& operator<<(ostream& output, const Derived& d)
{
	output << "\tint = " << d.value
		<< "\n\tchar = " << d.letter
		<< "\n\tdouble = " << d.real;
	
	return output;
}