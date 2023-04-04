#include "Date.h"
#include <iostream>

using namespace std;

Date::Date(int mn, int dy, int yr)
{
    if (mn > 0 && mn < 12)
        month = mn;
    else
    {
        month = 1;
        cout << "Месяц " << mn << " неправильный. Установлен месяц 1.\n";
    }

    year = yr;
    day = checkDay(dy);

    cout << "Конструктор объекта Date ";
    print();
    cout << endl;
}

void Date::print() const
{
    cout << month << '-' << day << '-' << year;
}

Date::~Date()
{
    cout << "Деструктор Date ";
    print();
    cout << endl;
}

int Date::checkDay(int testDay)
{
    static const int daysMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

    if (testDay > 0 && testDay <= daysMonth[month])
        return testDay;

    if (month == 2 && testDay == 29 && (year % 400 == 0 || year % 4 == 0 && year % 100 != 0))
        return testDay;

    cout << "День " << testDay << " непрвильный. Установлен день 1.\n";

    return 1;
}