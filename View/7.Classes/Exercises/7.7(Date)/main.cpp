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
#include "Date.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");



    Date* day1 = new Date(12, 23, 1945);
    Date* day2 = new Date(11, 1992);
    Date* day3 = new Date();
    day1->print();
    day2->print();
    day3->print();

  

    cout << "\n\n\n\n\n\n\n\n\n\n";
}