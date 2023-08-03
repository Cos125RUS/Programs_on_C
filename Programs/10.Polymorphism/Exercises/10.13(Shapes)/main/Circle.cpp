#include "Circle.h"
#include <iostream>

using namespace std;

Circle::Circle(double r, int a, int b) : Point(a, b) { setRadius(r); }

void Circle::setRadius(double r) { radius = (r >= 0 ? r : 0); }

double Circle::getRadius() const { return radius; }

double Circle::area() const { return 3.14159 * radius * radius; }

void Circle::print() const
{
	Point::print();
	cout << "; Radius = " << radius;
}