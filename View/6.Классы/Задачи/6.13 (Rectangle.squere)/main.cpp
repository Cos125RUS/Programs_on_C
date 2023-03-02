#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#include "Rectangle.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Rectangle rec(1,1,1,5,5,5,5,1);

    cout << "Length = " << rec.getLength() << endl << "Width = " << rec.getWidth() << endl
        << "Area = " << rec.area() << endl << "Perimeter = " << rec.perimeter() << endl
        << "Square - " << ((rec.square() == 1) ? "True": "False") << endl;






    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}