#include <iostream>
#include <locale>
#include "time.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Time t;

    int& hourRef = t.badSetHour(20);

    cout << "Часы перед установкой: " << hourRef;
    hourRef = 30;
    cout << "\nЧасы после установки неправильного значения: " << t.getHour();

    t.badSetHour(12) = 74;
    cout << "\n\n**************************************\n"
        << "ПЛОХАЯ ПРАКТИКА ПРОГРАММИРОВАНИЯ!!!\n"
        << "badSetHour как L-величина, часы: "
        << t.getHour()
        << "\n**************************************\n";



    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}