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
#include "Shape.h"

using namespace std;

void virtualViaPointer(const Shape*);
void virtualViaReference(const Shape&);

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2);

    Point point(7, 11);
    Circle circle(3.5, 22, 8);
    Cylinder cylinder(10, 3.3, 10, 10);

    point.printShapeName();
    point.print();
    cout << '\n';

    circle.printShapeName();
    circle.print();
    cout << '\n';

    cylinder.printShapeName();
    cylinder.print();
    cout << "\n\n";

    Shape* arrayOfShapes[3];
    arrayOfShapes[0] = &point;
    arrayOfShapes[1] = &circle;
    arrayOfShapes[2] = &cylinder;

    cout << "---------------virtualViaPointer-------------------\n";
    for (int i = 0; i < 3; i++)
    {
        virtualViaPointer(arrayOfShapes[i]);
    }

    cout << "---------------virtualViaReference-------------------\n";
    for (int i = 0; i < 3; i++)
    {
        virtualViaReference(*arrayOfShapes[i]);
    }



    cout << "\n\n\n\n\n\n\n\n\n\n";
}

void virtualViaPointer(const Shape* baseClassPtr)
{
    baseClassPtr->printShapeName();
    baseClassPtr->print();
    cout << "\nAria = " << baseClassPtr->area() << "\nVolume = " << baseClassPtr->volume() << "\n\n";
}

void virtualViaReference(const Shape& baseClassRef)
{
    baseClassRef.printShapeName();
    baseClassRef.print();
    cout << "\nAria = " << baseClassRef.area() << "\nVolume = " << baseClassRef.volume() << "\n\n";
}