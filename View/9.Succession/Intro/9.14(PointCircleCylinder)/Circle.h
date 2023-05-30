#pragma once
#include <iostream>
#include <iomanip>
#include "Point.h"

using namespace std;

class Circle : public Point
{
	friend ostream& operator<<(ostream&, const Circle&);
public:
	Circle(double r = 0.0, int x = 0, int y = 0);
	void setRadius(double);
	double getRadius() const;
	double area() const;
protected:
	double radius;
};

