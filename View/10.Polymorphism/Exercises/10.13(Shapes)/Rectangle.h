#pragma once
#include <iostream>
#include <iomanip>
#include "Point.h"

using namespace std;

class Rectangle : public Point
{
public:
	Rectangle(int w = 0, int h = 0, int x = 0, int y = 0) : Point(x, y) 
	{ 
		setWidth(w); 
		setHeight(h);
	}
	void setWidth(int w) { width = (w >= 0 ? w : 0); }
	void setHeight(int h) { height = (h >= 0 ? h : 0); }
	int getWidth() const { return width; }
	int getHeight() const { return height; }
	virtual double area() const { return width * height; }
	virtual void printShapeName() const { cout << "Rectangle: "; }
	virtual void print() const
	{
		Point::print();
		cout << "; Width = " << width << "; Height = " << height;
	}
	virtual void setSymbol(char s) { Point::setSymbol(s); }
	virtual void printSymbol() { Point::printSymbol(); }
protected:
	int width;
	int height;
};

