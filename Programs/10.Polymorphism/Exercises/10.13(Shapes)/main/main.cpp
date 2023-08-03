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
#include "Shape.h"
#include "Square.h"
#include "Rectangle.h"

using namespace std;

void virtualViaPointer(const Shape*);
void virtualViaReference(const Shape&);

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2);

    Point point(7, 11);
    Circle circle(3.5, 22, 8);
    Square square(5, 5, 5);
	Rectangle rectangle(7, 5, 6, 8);

    point.printShapeName();
    point.print();
    point.setSymbol('#');
    point.printSymbol();
    cout << '\n';

    circle.printShapeName();
    circle.print();
    circle.setSymbol('%');
    circle.printSymbol();
    cout << '\n';

    square.printShapeName();
    square.print();
    square.setSymbol('@');
    square.printSymbol();
    cout << '\n';

    rectangle.printShapeName();
    rectangle.print();
    rectangle.setSymbol('!');
    rectangle.printSymbol();
    cout << '\n';

    Shape* arrayOfShapes[4];
    arrayOfShapes[0] = &point;
    arrayOfShapes[1] = &circle;
    arrayOfShapes[2] = &square;
    arrayOfShapes[3] = &rectangle;

    cout << "---------------virtualViaPointer-------------------\n";
    for (int i = 0; i < sizeof(arrayOfShapes)/sizeof(*arrayOfShapes); i++)
    {
        virtualViaPointer(arrayOfShapes[i]);
    }

    cout << "---------------virtualViaReference-------------------\n";
    for (int i = 0; i < sizeof(arrayOfShapes) / sizeof(*arrayOfShapes); i++)
    {
        virtualViaReference(*arrayOfShapes[i]);
    }



    cout << "\n\n\n\n\n\n\n\n\n\n";
}

void virtualViaPointer(const Shape* baseClassPtr)
{
    baseClassPtr->printShapeName();
    baseClassPtr->print();
    cout << "\nAria = " << baseClassPtr->area() << "\n\n";
}

void virtualViaReference(const Shape& baseClassRef)
{
    baseClassRef.printShapeName();
    baseClassRef.print();
    cout << "\nAria = " << baseClassRef.area() << "\n\n";
}