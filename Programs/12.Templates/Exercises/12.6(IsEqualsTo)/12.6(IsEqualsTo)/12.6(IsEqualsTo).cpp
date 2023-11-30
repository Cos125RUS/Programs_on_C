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

using namespace std;


template<typename T>
bool isEqualsTo(T arg1, T arg2)
{
    return arg1 == arg2;
};

class MyObj
{
public:
    MyObj(int v) { value = v; }
    bool operator==(const MyObj& right) const { return value == right.value; }
private:
    int value;
};

int main()
{
    setlocale(LC_ALL, "Russian");

    int a = 12, b = 13, c = 12;
    MyObj o1(12), o2(13), o3(12);
    cout << isEqualsTo(a, b) << endl << isEqualsTo(a, c) << endl
        << isEqualsTo(o1,o2) << endl << isEqualsTo(o1, o3) << endl;






    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}