#include "Point.h"
#include <iostream>

using namespace std;

Point::Point(int a, int b)
{
	x = a;
	y = b;

	cout << "Конструктор Point: [" << x << ", " << y << "]\n";
}

Point::~Point()
{
	cout << "Деструктор Point: [" << x << ", " << y << "]\n";
}