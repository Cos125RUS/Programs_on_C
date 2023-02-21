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

class Count {
public:
    int x;
    void print() { cout << x << endl; }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    Count counter,
        * counterPtr = &counter,
        & counterRef = counter;

    cout << "x = 7\tcounter.x = ";
    counter.x = 7;
    counter.print();

    cout << "x = 8\tcounterRef.x = ";
    counterRef.x = 8;
    counterRef.print();

    cout << "x = 10\tcounterPtr -> x = ";
    counterPtr -> x = 10;
    counter.print();




    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}