#pragma once
#include <iostream>
#include "Circle.h"

using namespace std;

class Cylinder : public Circle
{
public:
	Cylinder(double h = 0.0, double r = 0.0, int x = 0, int y = 0);
	void setHeigth(double);
	double getHeigth() const;
	virtual double area() const;
	virtual double volume() const;
	virtual void printShapeName() const { cout << "Cylinder: "; }
	virtual void print() const;
protected:
	double heigth;
};

