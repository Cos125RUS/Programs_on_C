#include "Point.h"
#include <iostream>

using namespace std;

Point::Point(int a, int b)
{
	x = a;
	y = b;

	cout << "����������� Point: [" << x << ", " << y << "]\n";
}

Point::~Point()
{
	cout << "���������� Point: [" << x << ", " << y << "]\n";
}