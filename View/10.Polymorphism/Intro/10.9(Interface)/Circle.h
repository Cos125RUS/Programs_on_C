#pragma once
#include <iostream>
#include <iomanip>
#include "Point.h"

using namespace std;

class Circle : public Point
{
public:
	Circle(double r = 0.0, int x = 0, int y = 0);
	void setRadius(double);
	double getRadius() const;
	virtual double area() const;
	virtual void printShapeName() const { cout << "Circle: "; }
	virtual void print() const;
protected:
	double radius;
};

