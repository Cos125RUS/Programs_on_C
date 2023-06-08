#pragma once
#include <iostream>
#include <iomanip>
#include "Point.h"

using namespace std;

class Square : public Point
{
	friend ostream& operator<<(ostream&, const Square&);
public:
	Square(double l = 0.0, int x = 0, int y = 0);
	void setLine(double);
	double getLine() const;
	double area() const;
	double perimeter() const;
	void printAllPoints();
protected:
	double line;
};

