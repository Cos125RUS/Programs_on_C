#include <iostream>
#include <locale>

using namespace std;

class Date {
public:
    Date(int = 1, int = 1, int = 1990);
    void print();
    void setDate(int, int, int);
    void nextDay();
private:
    int month;
    int day;
    int year;
};

Date::Date(int m, int d, int y)
{
    setDate(m, d, y);
}

void Date::setDate(int m, int d, int y)
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

void Date::nextDay()
{
    setDate(month, day+1,year);
}

void Date::print()
{
    cout << month << '-' << day << '-' << year;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    Date date1(11, 23, 1933);


    for (int i = 0; i < 200; i++)
    {
        date1.nextDay();
        date1.print();
        cout << "\n";
    }




    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}