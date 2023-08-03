#pragma once
#include <iostream>
#include <iomanip>
#include "Shape.h"
#include "Point.h"

using namespace std;

class Triangle : public Shape
{
public:
	Triangle(Point p1, Point p2, Point p3)
	{
		point1 = p1;
		point2 = p2;
		point3 = p3;
		line1 = sqrt(pow((p2.getX() - p1.getX()), 2) + pow((p2.getY() - p1.getY()), 2));
		line2 = sqrt(pow((p3.getX() - p2.getX()), 2) + pow((p3.getY() - p2.getY()), 2));
		line3 = sqrt(pow((p1.getX() - p3.getX()), 2) + pow((p1.getY() - p3.getY()), 2));
	}
	virtual double area() const
	{
		double pp = (line1 + line2 + line3) / 2;
		return 0;
	}
	virtual void printShapeName() const { cout << "Triangle: "; }
	virtual void print() const;
	virtual void setSymbol(char s) { Shape::setSymbol(s); }
	virtual void printSymbol() { Shape::printSymbol(); }
protected:
	Point point1;
	Point point2;
	Point point3;
	double line1;
	double line2;
	double line3;
};

