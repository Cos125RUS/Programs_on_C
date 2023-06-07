#pragma once
#include <iostream>
#include "Square.h"

using namespace std;

class Cube : public Square
{
	friend ostream& operator<<(ostream&, const Cube&);
public:
	Cube(double l = 0.0, int x = 0, int y = 0, int z = 0);
	double area() const;
	double volume() const;
protected:
	int z;
};

