#include "Square.h"
#include <iostream>

using namespace std;

Square::Square(double l, int a, int b) : Point(a, b) { setLine(l); }

void Square::setLine(double l) { line = (l >= 0 ? l : 0); }

double Square::getLine() const { return line; }

double Square::area() const { return line * line; }

double Square::perimeter() const { return 4 * line; }

void Square::printAllPoints()
{
	cout << "(" << x << "," << y << ") (" << x + line << "," << y << ")\n("
		<< x << "," << y - line << ") (" << x + line << ", " << y - line << endl;
}

ostream& operator<<(ostream& output, const Square& s)
{
	output << static_cast<Point>(s) << "\t(" << s.x + s.line << "," << s.y << ")\n("
		<< s.x << "," << s.y - s.line << ")\t(" << s.x + s.line << ", " << s.y - s.line << ")" << endl;

	return output;
}