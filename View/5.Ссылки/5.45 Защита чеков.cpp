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

using namespace std;

void protect(double* sum, char* cheque)
{
    int integer = *sum;
    double f = (*sum * 100 - integer * 100) ;
    int fractional = (int)ceil(f);
    
    int star = 5;
    int a = integer;
    while (a > 9)
    {
        a /= 10;
        star--;
    }

    int thousand = 0;
    if (integer > 999)
    {
        star--;
        thousand = integer / 1000;
        integer %= 1000;
    }

    int i = 0;
    for (i, star; star > 0; i++, star--)
        cheque[i] = '*';

    if (thousand > 0)
    {
        if (thousand > 9)
        {
            cheque[i++] = thousand / 10 +48;
            cheque[i++] = thousand % 10 +48;
        }
        else cheque[i++] = thousand + 48;
    
        cheque[i++] = ',';
    }

    if (integer > 99)
    {
        cheque[i++] = integer / 100 + 48;
        integer %= 100;
    }
    else 
        if (thousand > 0)
            cheque[i++] = 48;

    if (integer > 9)
    {
        cheque[i++] = integer / 10 + 48;
        integer %= 10;
    }
    else 
        if (thousand > 0)
            cheque[i++] = 48;

    cheque[i++] = integer + 48;
    cheque[i++] = '.';

    if (fractional > 9)
    {
        cheque[i++] = fractional / 10 + 48;
        fractional %= 10;
    }
    else cheque[i++] = 48;

    if (fractional > 0)
        cheque[i] = fractional + 48;
    else cheque[i] = 48;
};

void main()
{
    setlocale(LC_ALL, "Russian");

    double sum;
    char cheque[12] = "";

    cout << "Enter the sum: ";
    cin >> sum;
    protect(&sum, cheque);
    cout << cheque;




    cout << "\n\n\n\n\n\n\n\n\n\n";
}