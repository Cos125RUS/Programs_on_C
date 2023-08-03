#pragma once
#include <iostream>
#include "Shape.h"

using namespace std;

class Point : public Shape
{
public:
	Point(int = 0, int = 0);
	void setPoint(int, int);
	int getX() const { return x; }
	int getY() const { return y; }
	virtual void printShapeName() const { cout << "Point: "; }
	virtual void print() const;
private:
	int x, y;
};

