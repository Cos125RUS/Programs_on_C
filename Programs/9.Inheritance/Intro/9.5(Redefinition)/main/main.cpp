#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include <cassert>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <cstring>
#include "hourly.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    HourlyWorker h("Bob", "Smith", 40.0, 10.0);
    h.print();







    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}