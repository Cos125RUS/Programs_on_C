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
#include <cstring>
#include "Point.h"
#include "Circle.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    {
        Point p(11, 22);
    }
    cout << endl;
    Circle circle1(4.5, 72, 29);
    cout << endl;
    Circle circle2(10, 5, 5);
    cout << endl;





    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}