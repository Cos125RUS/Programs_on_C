#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int a;
    int* aPtr;

    a = 7;
    aPtr = &a;

    cout << "Адрес переменной <a> " << &a << "\nЗначение aPtr " << aPtr;

    cout << "\n\nЗначение <a> " << a << "\nЗначение *aPtr " << *aPtr;

    cout << "\n\nПокажем, что * и & инверсны друг другу.\n&*aPtr = " << &*aPtr
        << "\n*&aPtr = " << *&aPtr;











    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}