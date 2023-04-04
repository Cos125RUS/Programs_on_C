#include <iostream>
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	if (isTriangle(x1, y1, x2, y2, x3, y3, x4, y4))
		setPoint(x1, y1, x2, y2, x3, y3, x4, y4);
}

void Rectangle::setPoint(double xx1, double yy1, double xx2, double yy2, double xx3, double yy3, double xx4, double yy4)
{
	x1 = (xx1 >= 0.0 && xx1 <= 20.0) ? xx1 : 1.0;
	x2 = (xx2 >= 0.0 && xx2 <= 20.0) ? xx2 : 1.0;
	x3 = (xx3 >= 0.0 && xx3 <= 20.0) ? xx3 : 1.0;
	x4 = (xx4 >= 0.0 && xx4 <= 20.0) ? xx4 : 1.0;
	y1 = (yy1 >= 0.0 && yy1 <= 20.0) ? yy1 : 1.0;
	y2 = (yy2 >= 0.0 && yy2 <= 20.0) ? yy2 : 1.0;
	y3 = (yy3 >= 0.0 && yy3 <= 20.0) ? yy3 : 1.0;
	y4 = (yy4 >= 0.0 && yy4 <= 20.0) ? yy4 : 1.0;
}

bool Rectangle::isTriangle(double xx1, double yy1, double xx2, double yy2, double xx3, double yy3, double xx4, double yy4)
{
	return (xx1 == xx2 && xx3 == xx4 && yy1 == yy4 && yy2 == yy3);
}

bool Rectangle::square() 
{ 
	return (x4 - x1) == (y2 - y1);
}

double Rectangle::getLength() { return x4 - x1; }
double Rectangle::getWidth() { return y2 - y1; }

double Rectangle::perimeter() { return 2 * (x4 - x1) + 2 * (y2 - y1); }
double Rectangle::area() { return (x4 - x1) * (y2 - y1); }
