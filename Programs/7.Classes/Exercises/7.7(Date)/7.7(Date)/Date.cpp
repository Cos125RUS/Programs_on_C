#include "Date.h"
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
#include <time.h>

using namespace std;

Date::Date(int mn, int dy, int yr)
{
    if (mn > 0 && mn < 13)
        month = mn;
    else
        month = 1;

    year = yr;
    day = checkDay(dy);
}

Date::Date(int dy, int yr)
{
    month = 1;
    year = yr;
    day = checkDay(dy);
}

Date::Date()
{
    time_t t = time(0);
    tm now;
    localtime_s(&now, &t);
    month = 1 + now.tm_mon;
    year = 1900 + now.tm_year;
    day = now.tm_mday;
}

void Date::print() const
{
    const char* allMonth[] = { " ", "€нварь", "февраль", "март" , "апрель" , "май" , "июнь" ,
        "июль" , " август" , "сент€брь" , "окт€брь" , "но€брь" , "декабрь" };

    cout << day << ' ' << year << endl;
    cout << month << '/' << day << '/' << year % 100 << endl;

    cout << allMonth[month] << ' ' << day << ", " << year << endl;
}

Date::~Date() {}

int Date::checkDay(int testDay)
{
    static const int daysMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

    if (testDay > 0 && testDay <= daysMonth[month])
        return testDay;

    if (month == 2 && testDay == 29 && (year % 400 == 0 || year % 4 == 0 && year % 100 != 0))
        return testDay;

    return 1;
}