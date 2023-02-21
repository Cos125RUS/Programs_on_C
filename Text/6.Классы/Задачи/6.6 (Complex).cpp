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

class Complex {
public:
    Complex(double = 0, double = 0);
    void print();
    void set(double, double);
    void sum(Complex, Complex);
    void dif(Complex , Complex );
private:
    double realPart;
    double imaginaryPart;
    char j = 'i';
};

Complex::Complex(double rp, double ip)
{
    realPart = rp; 
    imaginaryPart = ip;
}

void Complex::print()
{
    cout << realPart << " + " << imaginaryPart << j;
}

void Complex::set(double r, double i)
{
    realPart = r;
    imaginaryPart = i;
}

void Complex::sum(Complex num1, Complex num2)
{
    realPart = num1.realPart + num2.realPart;
    imaginaryPart = num1.imaginaryPart + num2.imaginaryPart;
}

void Complex::dif(Complex num1, Complex num2)
{
    realPart = num1.realPart - num2.realPart;
    imaginaryPart = num1.imaginaryPart - num2.imaginaryPart;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    Complex a(22, 12);
    Complex b(7, 5);
    a.print();
    cout << endl;
    b.print();
    cout << endl;
    Complex c;
    c.sum(a, b);
    c.print();
    cout << endl;
    c.dif(a, b);
    c.print();
    cout << endl;




    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}