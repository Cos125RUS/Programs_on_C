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

class Count
{
    friend void setX(Count&, int);
public:
    Count() { x = 0; }
    void print() const { cout << x << endl; }
private:
    int x;
};

void setX(Count& c, int val) { c.x = val; }

int main()
{
    setlocale(LC_ALL, "Russian");

    Count counter;

    cout << "counter.x после создания: ";
    counter.print();
    cout << "counter.x после setX: ";
    setX(counter, 8);
    counter.print();






    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}