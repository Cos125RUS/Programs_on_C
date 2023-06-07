#include "Point.h"
#include <iostream>

Point::Point(int a, int b) { setPoint(a, b); }

void Point::setPoint(int a, int b)
{
	x = a;
	y = b;
}

ostream& operator<<(ostream& output, const Point& p)
{
	output << '(' << p.x << ", " << p.y << ')';

	return output;
}