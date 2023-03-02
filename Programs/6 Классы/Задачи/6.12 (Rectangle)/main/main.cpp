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

    Rectangle rec(5.0, 7.0);

    cout << "Length = " << rec.getLength() << endl << "Width = " << rec.getWidth() << endl
        << "Area = " << rec.area() << endl << "Perimeter = " << rec.perimeter();







    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}