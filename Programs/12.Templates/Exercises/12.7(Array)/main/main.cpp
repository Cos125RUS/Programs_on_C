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
#include "array.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");


    Array<int> integers1(7), integers2;

    cout << "integer1 size = " << integers1.getSize() << "\ninteger1: " << integers1 << endl;
    cout << "integer2 size = " << integers2.getSize() << "\ninteger2: " << integers2 << endl;

    cout << "\nEnter 17 numbers: ";
    cin >> integers1 >> integers2;
    cout << "\ninteger1: " << integers1 << endl;
    cout << "\ninteger2: " << integers2 << endl;

    cout << "\nintegers1 equesl integers2 ?\n";
    if (integers1 != integers2)
        cout << "integers1 != integers2\n";

    Array<int> integers3(integers1);

    cout << "\ninteger3 size = " << integers3.getSize() << "\ninteger3: " << integers3 << endl;

    cout << "\nintegers1 = integers2\n";
    integers1 = integers2;
    cout << "integer1: " << integers1 << endl;
    cout << "integer2: " << integers2 << endl;

    cout << "\nintegers1 equesl integers2 ?\n";
    if (integers1 == integers2)
        cout << "integers1 == integers2\n";

    cout << "\nintegers1[5] = " << integers1[5] << endl;

    cout << "\nintegers1[5] = 1000\n";
    integers1[5] = 1000;
    cout << "integers1 = " << integers1 << endl;



    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}