#include <iostream>
#include <locale>

using namespace std;

class Date {
public:
    Date(int = 1, int = 1, int = 1990);
    void print();
private:
    int month;
    int day;
    int year;
};

Date::Date(int m, int d, int y)
{
    month = m;
    day = d;
    year = y;
}

void Date::print()
{
    cout << month << '-' << day << '-' << year;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    Date date1(7, 4, 1933), date2;

    cout << "date1 = ";
    date1.print();
    cout << "\ndate2 = ";
    date2.print();

    date2 = date1;
    cout << "\n\ndate2 = date1\ndate2 = ";
    date2.print();






    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}