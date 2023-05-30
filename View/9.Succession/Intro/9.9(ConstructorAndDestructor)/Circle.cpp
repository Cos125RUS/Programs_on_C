#include "Circle.h"
#include <iostream>

using namespace std;

Circle::Circle(double r, int a, int b) : Point(a, b)
{
	radius = r;

	cout << "Конструктор Circle: радиус равен " << radius << " [" << x << ", " << y << ']' << endl;
}


Circle::~Circle()
{
	cout << "Деструктор Circle: радиус равен " << radius << " [" << x << ", " << y << ']' << endl;
}