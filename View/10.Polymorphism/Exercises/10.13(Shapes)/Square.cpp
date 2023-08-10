#include "Square.h"
#include <iostream>

using namespace std;

void Square::print() const
{
	Point::print();
	cout << "; Side = " << side;
}

