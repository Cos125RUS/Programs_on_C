#include <iostream>
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(double length, double width)
{
	setLength(length);
	setWidth(width);
}

void Rectangle::setLength(double l)
{
	length = (l >= 0.0 && l <= 20.0) ? l : 1.0;
}

void Rectangle::setWidth(double w)
{
	width = (w >= 0.0 && w <= 20.0) ? w : 1.0;
}

double Rectangle::getLength() { return length; }
double Rectangle::getWidth() { return width; }

double Rectangle::perimeter() { return 2 * width + 2 * length; }
double Rectangle::area() { return width * length; }