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

    Time wakeUp(6, 45, 0);
    const Time noon(12, 0, 0);

    wakeUp.setHour(18);
    //noon.setHour(12);

    wakeUp.getHour();

    noon.getMinute();
    noon.printMilitary();
    //noon.printStandard();





    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}