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
#include "Polinomials.h"
#include "Item.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Item arr1[3] = { Item(-2,3), Item(-4,1), Item(7,0) };
    Polinomials p1(arr1, 3);

    cout << p1 << endl << endl;

    Item i0(32, 0), i1(12, 1), i2(3, 2), i3(1,3);
    Item arr2[4] = { i0, i1, i2, i3 };
    Polinomials p2(arr2, 4);
    cout << p2 << endl << endl;

    Polinomials p3 = p2 + p1;
    cout << p3 << endl << endl;



    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}