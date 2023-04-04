#include <iostream>
#include <locale>
#include "time.h"

using namespace std;

void incrementMinetes(Time&, const int);

int main()
{
    setlocale(LC_ALL, "Russian");

    Time t;

    t.setHour(17);
    t.setMinute(34);
    t.setSecond(25);

    cout << "Результаты установки всех правильных значений:\n"
        << "    Часы: " << t.getHour()
        << "    Минуты: " << t.getMinute()
        << "    Секунды: " << t.getSecond();

    t.setHour(234);
    t.setMinute(43);
    t.setSecond(6373);

    cout << "\n\nПопытка установки неправильных значений:\n"
        << "    Часы: " << t.getHour()
        << "    Минуты: " << t.getMinute()
        << "    Секунды: " << t.getSecond() << "\n\n";

    t.setTime(11, 58, 0);
    incrementMinetes(t, 3);


    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

void incrementMinetes(Time &tt, const int count)
{
    cout << "Увеличение минут на " << count
        << "\nНачальное время: ";
    tt.printStandard();

    for (int i = 0; i < count; i++)
    {
        tt.setMinute((tt.getMinute() + 1) % 60);

        if (tt.getMinute() == 0)
            tt.setHour((tt.getHour() + 1) % 24);

        cout << "\nmiute + 1: ";
        tt.printStandard();
    }

    cout << endl;
}