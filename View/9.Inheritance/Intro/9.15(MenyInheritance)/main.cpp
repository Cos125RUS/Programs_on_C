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
#include "Derived.h"
#include "Base1.h"
#include "Base2.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Base1 b1(10), * base1Ptr = 0;
    Base2 b2('z'), * base2Ptr = 0;
    Derived d(7, 'A', 3.5);

    cout << "b1 int: " << b1.getData()
        << "\nb2 char: " << b2.getData()
        << "\nd as: " << d << endl << endl;

    cout << "Derived items:\nint = " << d.Base1::getData()
        << "\nchar = " << d.Base2::getData()
        << "\ndouble = " << d.getReal() << "\n\n";

    base1Ptr = &d;
    cout << "base1Ptr->getData(): " << base1Ptr->getData() << endl;

    base2Ptr = &d;
    cout << "base2Ptr->getData(): " << base2Ptr->getData() << endl;




    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}