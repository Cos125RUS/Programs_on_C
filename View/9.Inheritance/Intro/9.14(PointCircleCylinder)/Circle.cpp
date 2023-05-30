#include "Circle.h"

Circle::Circle(double r, int a, int b) : Point(a, b) { setRadius(r); }

void Circle::setRadius(double r) { radius = (r >= 0 ? r : 0); }

double Circle::getRadius() const { return radius; }

double Circle::area() const { return 3.14159 * radius * radius; }

ostream& operator<<(ostream& output, const Circle& c)
{
	output << "Центр = " << static_cast<Point>(c) << "; Радиус = "
		<< setiosflags(ios::fixed | ios::showpoint) << setprecision(2) << c.radius;

	return output;
}