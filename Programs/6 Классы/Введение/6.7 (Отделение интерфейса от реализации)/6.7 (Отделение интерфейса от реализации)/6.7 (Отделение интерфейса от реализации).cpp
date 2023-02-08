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

#include "Time.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Time t;

    cout << "Start Time Military: ";
    t.printMilitary();
    cout << "\nStart Time Standard: ";
    t.printStandard();

    t.setTime(13, 27, 6);
    cout << "\n\nTime Military after set: ";
    t.printMilitary();
    cout << "\nTime Standard after set: ";
    t.printStandard();

    t.setTime(99, 99, 99);
    cout << "\n\nUnright Set Time Military: ";
    t.printMilitary();
    cout << "\nUnright Set Time Standard: ";
    t.printStandard();






    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}
