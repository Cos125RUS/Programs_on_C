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

#include "building.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int duration;

    cout << "Введите время моделирования: ";
    cin >> duration;
    cin.ignore;

    Building office;
    cout << "\n*** НАЧАЛО МОДЕЛИРОВАНИЯ ***\n\n";
    office.runSimulation;
    cout << "*** ЗАВЕРШЕНИЕ МОДЕЛИРОВАНИЯ ***\n";








    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}