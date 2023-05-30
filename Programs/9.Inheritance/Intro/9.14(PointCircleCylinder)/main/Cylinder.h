#pragma once
#include <iostream>
#include "Circle.h"

using namespace std;

class Cylinder: public Circle
{
	friend ostream& operator<<(ostream&, const Cylinder&);
public:
	Cylinder(double h = 0.0, double r = 0.0, int x = 0, int y = 0);
	void setHeigth(double);
	double getHeigth() const;
	double area() const;
	double volume() const;
protected:
	double heigth;
};

