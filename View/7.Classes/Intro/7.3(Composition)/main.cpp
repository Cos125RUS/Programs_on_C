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
#include "Emply.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Employee e("Bob", "Jones", 7, 24, 1949, 3, 12, 1988);

    cout << endl;
    e.print();
    cout << "\nПроверка конструктора Date с неправильными значениями:\n";
    Date d(14, 35, 1944);
    cout << endl;






    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}