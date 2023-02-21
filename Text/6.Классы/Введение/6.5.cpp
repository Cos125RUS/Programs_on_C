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

using namespace std;

class Time {
public:
    Time();
    void setTime(int, int, int);
    void printMilitary();
    void printStandard();
private:
    int hour;
    int minute;
    int second;
};

Time::Time() { hour = minute = second = 0; }

void Time::setTime(int h, int m, int s)
{
    hour = (h >= 0 && h < 24) ? h : 0;
    minute = (m >= 0 && m < 60) ? m : 0;
    second = (s >= 0 && s < 60) ? s : 0;
}

void Time::printMilitary()
{
    cout << (hour < 10 ? "0" : "") << hour << ":" << (minute < 10 ? "0" : "") << minute
        << ":" << (second < 10 ? "0" : "") << second;
};

void Time::printStandard() 
{
    cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":" << (minute < 10 ? "0" : "") << minute
        << ":" << (second < 10 ? "0" : "") << second << (hour < 12 ? " AM" : " PM");
};

int main()
{
    setlocale(LC_ALL, "Russian");

    Time t;

    cout << "Start Time Military: ";
    t.printMilitary();
    cout << "\nStart Time Standard: ";
    t.printStandard();

    t.setTime(13, 27, 6);
    cout << "\n\nTime Military after set: ";
    t.printMilitary();
    cout << "\nTime Standard after set: ";
    t.printStandard();

    t.setTime(99, 99, 99);
    cout << "\n\nUnright Set Time Military: ";
    t.printMilitary();
    cout << "\nUnright Set Time Standard: ";
    t.printStandard();




    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}