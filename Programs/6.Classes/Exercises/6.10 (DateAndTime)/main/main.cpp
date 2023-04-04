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

#include "DateAndTime.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    DateAndTime dnt(23,59,45,12,31,2022);

    for (int i = 0; i < 200; i++)
    {
        dnt.tick();
        dnt.printStandard();
        cout << endl;
    }






    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}