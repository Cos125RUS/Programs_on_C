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

    t.setHour(18).setMinute(33).setSecond(22);
    cout << "Military: ";
    t.printMilitary();
    cout << "\nStandard: ";
    t.printStandard();

    cout << "\n\nNew Standard: ";
    t.setTime(20, 20, 20).printStandard();
    cout << "\nMilitary: ";
    t.setTime(19, 19, 19).printMilitary();

    cout << "\n\n\nMilitary: ";
    t.setHour(11);
    t.setMinute(44);
    t.setSecond(55).printMilitary();




    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}