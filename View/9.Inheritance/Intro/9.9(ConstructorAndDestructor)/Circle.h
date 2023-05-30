#pragma once
#include "Point.h"

using namespace std;

class Circle : public Point
{
public:
	Circle(double r = 0.0, int x = 0, int y = 0);
	~Circle();
protected:
	double radius;
};

