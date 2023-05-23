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
#include "RationalNumber.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    RationalNumber rn1(2, 3), rn2(3, 4), rn3(2, 3), rn4;
    cout << rn1 << endl << rn2 << endl;
    cout << "rn1 + rn2 = " << rn1 + rn2 << endl;
    cout << "rn1 - rn2 = " << rn1 - rn2 << endl;
    cout << "rn1 * rn2 = " << rn1 * rn2 << endl;
    cout << "rn1 / rn2 = " << rn1 / rn2 << endl;
    cout << rn1 << " == " << rn2 << " ? " << (rn1 == rn2) << endl;
    cout << rn1 << " != " << rn2 << " ? " << (rn1 != rn2) << endl;
    cout << rn1 << " > " << rn2 << " ? " << (rn1 > rn2) << endl;
    cout << rn1 << " < " << rn2 << " ? " << (rn1 < rn2) << endl;
    cout << rn1 << " == " << rn3 << " ? " << (rn1 == rn3) << endl;
    cout << "rn4 > ";
    cin >> rn4;
    cout << "rn4 = " << rn4 << endl;
    rn4 = rn2;
    cout << "rn4 = rn2 = " << rn4 << endl;






    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
}