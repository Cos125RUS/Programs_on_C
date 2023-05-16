#include "Complex.h"
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

Complex::Complex(double r, double i) : real(r), imaginary(i) {}

Complex Complex::operator+(const Complex& operand2) const
{
	return Complex(real + operand2.real, imaginary + operand2.imaginary);
}

Complex Complex::operator-(const Complex& operand2) const
{
	return Complex(real - operand2.real, imaginary - operand2.imaginary);
}

Complex Complex::operator*(const Complex& operand2) const
{
	return Complex(real * operand2.real, imaginary * operand2.imaginary);
}

const Complex& Complex::operator=(const Complex &right)
{
	real = right.real;
	imaginary = right.imaginary;
	return *this;
}

bool Complex::operator==(const Complex& right) const
{
	if (real != right.real)
		return false;

	if (imaginary != right.imaginary)
		return false;

	return true;
}

void Complex::print() const
{ cout << '(' << real << ", " << imaginary << "*i)"; }

ostream& operator<<(ostream& output, const Complex& c)
{
    output << "(" << c.real << ", " << c.imaginary << "*i)";
    return output;
}

istream& operator>>(istream& input, Complex& c)
{
    input >> c.real;
    input >> c.imaginary;
    return input;
}