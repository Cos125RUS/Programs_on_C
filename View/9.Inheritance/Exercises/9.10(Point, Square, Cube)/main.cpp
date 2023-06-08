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
#include "Square.h"
#include "Cube.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Point p(72, 115);
    cout << "x = " << p.getX() << "\ny = " << p.getY() << endl;
    p.setPoint(10, 10);
    cout << "new p: " << p << endl;

    cout << "\n-----------------------------------\n";

    Square s(5, 12, 10);
    cout << s;

    cout << "\n-----------------------------------\n";

    Cube c(5, 12, 10, 8);
    cout << c;


    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}