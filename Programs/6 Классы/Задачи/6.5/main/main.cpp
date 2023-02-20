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

#include "time.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Time t;
    t.time(15, 20, 30);
    t.printTime();






    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}