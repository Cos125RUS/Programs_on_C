#pragma once
#include <iostream>

using namespace std;

class Point
{
	friend ostream& operator<<(ostream&, const Point&);
	friend istream& operator>>(istream&, Point&);
public:
	Point(int = 0, int = 0);
	void parseString(char[], int);
	void setPoint(int, int);
	int getX() const { return x; }
	int getY() const { return y; }
	virtual void print() const { cout << '[' << x << ", " << y << ']'; }
private:
	int getNum(char[], int*, char);
	int x, y;
};

