#pragma once
#include <iostream>
#include <iomanip>
#include "Point.h"

using namespace std;

class Square : public Point
{
public:
	Square(int s = 0, int x = 0, int y = 0) : Point(x, y) { setSide(s); }
	void setSide(int s) { side = (s >= 0 ? s : 0); }
	int getSide() const { return side; }
	virtual double area() const { return side * side; }
	virtual void printShapeName() const { cout << "Square: "; }
	virtual void print() const;
	virtual void setSymbol(char s) { Point::setSymbol(s); }
	virtual void printSymbol() { Point::printSymbol(); }
protected:
	int side;
};

