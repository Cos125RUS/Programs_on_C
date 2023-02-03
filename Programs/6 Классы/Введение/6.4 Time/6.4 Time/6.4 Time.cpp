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

struct Time {
    int hour;
    int minute;
    int second;
};

void printMilitary(const Time &t) {
    cout << (t.hour < 10 ? "0" : "") << t.hour << ":" << (t.minute < 10 ? "0" : "") << t.minute
        << ":" << (t.second < 10 ? "0" : "") << t.second;
};
void printStandard(const Time& t) {
    cout << ((t.hour == 0 || t.hour == 12) ? 12 : t.hour % 12) << ":" << (t.minute < 10 ? "0" : "") << t.minute
        << ":" << (t.second < 10 ? "0" : "") << t.second << (t.hour < 12 ? " AM" : " PM");
};

int main()
{
    setlocale(LC_ALL, "Russian");

    Time dinnerTime;

    dinnerTime.hour = 18;
    dinnerTime.minute = 30;
    dinnerTime.second = 0;

    cout << "Dinner in ";
    printMilitary(dinnerTime);
    cout << " by military\nAnd this is: ";
    printStandard(dinnerTime);
    cout << " by standard";
    

    dinnerTime.hour = 29;
    dinnerTime.minute = 73;

    cout << "\n\nInvalible values: ";
    printMilitary(dinnerTime);


    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}