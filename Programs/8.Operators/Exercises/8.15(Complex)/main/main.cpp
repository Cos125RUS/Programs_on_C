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
#include "Complex.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Complex x, y(4.3, 8.2), z(3.3, 1.1);

    cout << "x = ";
    x.print();
    cout << "\ny = ";
    y.print();
    cout << "\nz = ";
    z.print();

    x = y + z;
    cout << "\nx = y + z = ";
    y.print();
    cout << " + ";
    z.print();
    cout << " = ";
    x.print();

    x = y - z;
    cout << "\nx = y - z = ";
    y.print();
    cout << " - ";
    z.print();
    cout << " = "; 
    x.print();

    x = y * z;
    cout << "\nx = y * z = ";
    y.print();
    cout << " * ";
    z.print();
    cout << " = ";
    x.print();
    cout << endl << endl;

    cout << "Enter 2 nums: ";
    cin >> x;
    cout << "x = " << x << endl << endl;

    x = y;
    cout << "x = y = " << x << endl;

    cout << "x equels y ? " << endl;
    if (x == y) cout << "x == y\n";
    else cout << "x != y\n";

    cout << "x equels z ? " << endl;
    if (x == z) cout << "x == z\n";
    else cout << "x != z\n";
}