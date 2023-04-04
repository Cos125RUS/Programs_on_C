#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include <string.h>
#include <errno.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    long value1 = 200000, value2;
    long* lPtr;

    lPtr = &value1;

    cout << *lPtr << endl;

    value2 = *lPtr;
    cout << value2 << endl;

    cout << &value1 << endl;
    cout << lPtr << endl;







    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}