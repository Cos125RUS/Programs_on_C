#pragma once
#include <iostream>

using namespace std;

class Shape
{
public:
	virtual double area() const { return 0.0; }

	virtual void printShapeName() const = 0;
	virtual void print() const = 0;

	virtual void setSymbol(char s) { symbol = s; }
	virtual void printSymbol() { cout << "\nSymbol - " << symbol; }
private:
	char symbol;
};

