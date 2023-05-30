#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include <cassert>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include "Circle.h"
#include "Point.h"
#include "Cylinder.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Point p(72, 115);
    cout << "x = " << p.getX() << "\ny = " << p.getY() << endl;
    p.setPoint(10, 10);
    cout << "new p: " << p << endl;

    cout << "-----------------------";

    Circle c(2.5, 37, 43);
    cout << "\nx = " << c.getX() << "\ny = " << c.getY() << "\nr = " << c.getRadius() << endl;
    c.setRadius(4.25);
    c.setPoint(2, 2);
    cout << "new c: " << c << "\nArea(c) = " << c.area() << endl;
    Point& pRef = c;
    cout << "\nCircal as Point: " << pRef << endl;

    cout << "-----------------------";

    Cylinder cy(5.7, 2.5, 12, 23);
    cout << "\nx = " << cy.getX() << "\ny = " << cy.getY() << "\nr = " << cy.getRadius() 
        << "\nh = " << cy.getHeigth() << endl;
    cy.setHeigth(10);
    cy.setRadius(4.25);
    cy.setPoint(2, 2);
    cout << "new cy: " << cy << "\nArea(cy) = " << cy.area() << endl;
    pRef = cy;
    cout << "\nCylinder as Point: " << pRef << endl;
    Circle& cRef = cy;
    cout << "\nCylinder as Circle: " << cRef << "\nArea(cRef) = " << cRef.area() << endl;


    cout << "\n\n\n\n\n\n\n\n\n\n";
}