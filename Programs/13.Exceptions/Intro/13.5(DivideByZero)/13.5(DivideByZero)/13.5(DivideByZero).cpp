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
#include <csetjmp>

using namespace std;

class DivideByZeroException
{
public:
    DivideByZeroException() : message ("Попытка деления на ноль") {}
    const char* what() const { return message; }
private:
    const char* message;
};

double quotient(int numerator, int denominator)
{
    if (denominator == 0)
        throw DivideByZeroException();

    return static_cast<double> (numerator) / denominator;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int num1, num2;
    double res;

    cout << "Enter two numbers: ";
    while (cin >> num1 >> num2)
    {
        try
        {
            res = quotient(num1, num2);
            cout << "Result = " << res << endl;
        }
        catch (DivideByZeroException ex)
        {
            cout << "Error: " << ex.what() << endl;
        }
        cout << "\nEnter two numbers: ";

    }







    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}