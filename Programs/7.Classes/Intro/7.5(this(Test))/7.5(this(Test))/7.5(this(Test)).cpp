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

class Test
{
public:
    Test(int = 0);
    void print() const;
private:
    int x;
};

Test::Test(int a) { x = a; }
void Test::print() const
{
    cout << "\tx = " << x << "\n  this->x = " << this->x << "\n(*this).x = " << (*this).x << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    Test testObject(12);

    testObject.print();






    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}