#include "Point.h"

Point::Point(int a, int b) { setPoint(a, b); }

void Point::setPoint(int a, int b)
{
	x = a;
	y = b;
}

void Point::print() const
{
	cout << '[' << x << ", " << y << ']';
}