#pragma once
#include <iostream>

using namespace std;

class Complex
{
	friend ostream& operator<<(ostream&, const Complex&);
	friend istream& operator>>(istream&, Complex&);

public:
	Complex(double = 0.0, double = 0.0);
	Complex operator+(const Complex&) const;
	Complex operator-(const Complex&) const;
	Complex operator*(const Complex&) const;
	const Complex &operator=(const Complex&);
	bool operator==(const Complex&) const;
	bool operator!=(const Complex& right) const { return !(*this == right); }
	void print() const;
private:
	double real;
	double imaginary;
};

