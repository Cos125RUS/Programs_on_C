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

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Point* pointPtr = 0, p(30, 50);
    Circle* circlePtr = 0, c(2.7, 120, 89);

    cout << "Точка p: " << p << "\nОкружность c: " << c << '\n';

    pointPtr = &c;
    cout << "\nОкружность с (через *pointPtr): " << *pointPtr << endl << endl;

    circlePtr = static_cast<Circle*>(pointPtr);
    cout << "\nОкружность c (через *circlePtr): " << *circlePtr
        << "\nПлощадь с (через circlePtr): " << circlePtr->area() << endl;

    pointPtr = &p;

    circlePtr = static_cast<Circle*>(pointPtr);
    cout << "\nТочка р (через *circePtr): " << *circlePtr
        << "\nПлощадь объекта circlePtr указывает на: " << circlePtr->area() << endl;






    cout << "\n\n\n\n\n\n\n\n\n\n";
}