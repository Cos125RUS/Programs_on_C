#include "Circle.h"
#include <iostream>

using namespace std;

Circle::Circle(double r, int a, int b) : Point(a, b)
{
	radius = r;

	cout << "����������� Circle: ������ ����� " << radius << " [" << x << ", " << y << ']' << endl;
}


Circle::~Circle()
{
	cout << "���������� Circle: ������ ����� " << radius << " [" << x << ", " << y << ']' << endl;
}