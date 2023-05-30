#include "Cylinder.h"

Cylinder::Cylinder(double h, double r, int x, int y) : Circle(r, x, y) { setHeigth(h); }

void Cylinder::setHeigth(double h) { heigth = (h >= 0 ? h : 0); }

double Cylinder::getHeigth() const { return heigth; }

double Cylinder::area() const { return 2 * Circle::area() + 2 * 3.14159*radius* heigth; }

double Cylinder::volume() const { return Circle::area() * heigth; }

ostream& operator<<(ostream& output, const Cylinder& cy)
{
	output << static_cast<Circle>(cy) << "; Высота = " << cy.heigth << endl;

	return output;
}