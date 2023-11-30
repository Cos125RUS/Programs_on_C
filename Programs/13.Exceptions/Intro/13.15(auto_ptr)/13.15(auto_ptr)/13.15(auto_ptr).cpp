#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include <cassert>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <cstring>
#include <csetjmp>
#include <exception>
#include <stdexcept>
#include <new>
#include <stdlib.h>
#include <memory>

using namespace std;

class Integer
{
public:
    Integer(int i = 0) : value(i) { cout << "Конструктор Integer " << value << endl; };
    ~Integer() { cout << "Деструктор Integer " << value << endl << endl << endl << endl; };
    void setInteger(int i) { value = i; }
    int getInteger() const { return value; }
private:
    int value;
};

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Create new auto_ptr as pointer to Integer\n";

    auto_ptr<Integer> ptrToInteger(new Integer(7));

    cout << "Use auto_ptr\n";
    ptrToInteger->setInteger(99);
    cout << "After setInteger " << (*ptrToInteger).getInteger() << "\nEnd of program\n";







    return 0;
}