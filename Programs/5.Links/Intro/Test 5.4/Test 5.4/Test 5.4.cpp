#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int cubeByValue(int);

void cubeByReference(int*);

int main()
{
    setlocale(LC_ALL, "Russian");

    int number = 5;

    cout << "Исходное значение числа: " << number;
    number = cubeByValue(number);
    cout << "\nЗначение числа из cubeByValue: " << number;

    number = 5;
    cubeByReference(&number);
    cout << "\nЗначение числа после cubeByReference: " << number;


          


    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

int cubeByValue(int n)
{
    return n * n * n;
}

void cubeByReference(int *nPtr)
{
    *nPtr = *nPtr * *nPtr * *nPtr;
}