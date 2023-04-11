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

#include "Interface.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Interface i(5);

    cout << "Интерфейс содержит: " << i.getValue() << " до setValue\n";
    i.setValue(10);
    cout << "Интерфейс содержит: " << i.getValue() << " после setValue\n";






    cout << "\n\n\n\n\n\n\n\n\n\n";
}