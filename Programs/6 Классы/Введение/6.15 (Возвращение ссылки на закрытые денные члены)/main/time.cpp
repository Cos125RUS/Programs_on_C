#include <iostream>

#include "time.h"

using namespace std;

Time::Time(int hr, int min, int sec)
{
    setTime(hr, min, sec);
}

void Time::setTime(int h, int m, int s)
{
    hour = (h >= 0 && h < 24) ? h : 0;
    minute = (m >= 0 && m < 60) ? m : 0;
    second = (s >= 0 && s < 60) ? s : 0;
}

int Time::getHour() { return hour; }

int &Time::badSetHour(int hh) 
{ 
    hour = (hh >= 0 && hh < 24) ? hh : 0;

    return hour; 
}
