#include <iostream>
#include "DateAndTime.h"

using namespace std;

DateAndTime::DateAndTime(int hr, int min, int sec, int m, int d, int y)
{
    setTime(hr, min, sec);
    setDate(m, d, y);
}

void DateAndTime::setTime(int h, int m, int s)
{
    setHour(h);
    setMinute(m);
    setSecond(s);
}

void DateAndTime::setHour(int h)
{
    hour = (h >= 0 && h < 24) ? h : 0;
    if (h == 24) nextDay();
}

void DateAndTime::setMinute(int m)
{
    minute = (m >= 0 && m < 60) ? m : 0;
    if (m == 60) setHour(hour + 1);
}

void DateAndTime::setSecond(int s)
{
    second = (s >= 0 && s < 60) ? s : 0;
    if (s == 60) setMinute(minute + 1);
}

int DateAndTime::getHour() { return hour; }
int DateAndTime::getMinute() { return minute; }
int DateAndTime::getSecond() { return second; }

void DateAndTime::printMilitary()
{
    cout << (hour < 10 ? "0" : "") << hour << ":" << (minute < 10 ? "0" : "") << minute
        << ":" << (second < 10 ? "0" : "") << second << "\t";
    printDay();
}

void DateAndTime::printStandard()
{
    cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":" << (minute < 10 ? "0" : "") << minute
        << ":" << (second < 10 ? "0" : "") << second << (hour < 12 ? " AM" : " PM") << "\t";
    printDay();
}

void DateAndTime::tick()
{
    setSecond(second + 1);
}

void DateAndTime::setDate(int m, int d, int y)
{
    year = (y >= 0) ? y : 0;
    month = (m >= 1 && m <= 12) ? m : 1;
    if (m == 13) setDate(month, day, year + 1);
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        day = (d >= 1 && d <= 31) ? d : 1;
        if (d == 32) setDate(month + 1, day, year);
        break;
    case 2:
        if (year % 4 == 0) {
            day = (d >= 1 && d <= 29) ? d : 1;
            if (d == 30) setDate(month + 1, day, year);
        }
        else
        {
            day = (d >= 1 && d <= 28) ? d : 1;
            if (d == 29) setDate(month + 1, day, year);
        }
        break;
    default:
        day = (d >= 1 && d <= 30) ? d : 1;
        if (d == 31) setDate(month + 1, day, year);
        break;
    }


}

void DateAndTime::nextDay()
{
    setDate(month, day + 1, year);
}

void DateAndTime::printDay()
{
    cout << month << '-' << day << '-' << year;
}