#include <iostream>
#include <locale>
#include "time.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Time t1,
        t2(2),
        t3(21, 34),
        t4(12, 25, 42),
        t5(27, 74, 99);

    cout << "Варианты:\n\nВсе аргументы по умолчанию:\n";
    t1.printMilitary();
    cout << "\n";
    t1.printStandard();

    cout << "\n\nЧасы заданы. Минуты и секунды по умолчанию:\n";
    t2.printMilitary();
    cout << "\n";
    t2.printStandard();

    cout << "\n\nЧасы и минуты заданы. Секунды по умолчанию:\n";
    t3.printMilitary();
    cout << "\n";
    t3.printStandard();

    cout << "\n\nЧасы, минуты и секунды заданы:\n";
    t4.printMilitary();
    cout << "\n";
    t4.printStandard();

    cout << "\n\nВсе значения заданы неверно:\n";
    t5.printMilitary();
    cout << "\n";
    t5.printStandard();






    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}
