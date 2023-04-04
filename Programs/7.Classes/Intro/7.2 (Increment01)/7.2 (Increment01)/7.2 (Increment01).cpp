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

class Increment {
public:
    Increment(int c = 0, int i = 1);
    void addIncrement() { count += increment; }
    void print() const;

private:
    int count;
    const int increment;
};

Increment::Increment(int c, int i) : increment(i) { count = c; }
void Increment::print() const
{
    cout << "count = " << count << " , increment = " << increment << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    Increment value(10, 5);

    cout << "First: ";
    value.print();

    for (int j = 0; j < 3; j++) {
        value.addIncrement();
        cout << "After " << j + 1 << ": ";
        value.print();
    }







    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}