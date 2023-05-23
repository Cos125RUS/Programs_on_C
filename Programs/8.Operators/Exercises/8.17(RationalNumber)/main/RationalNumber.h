#pragma once
#include <iostream>

using namespace std;

class RationalNumber
{
	friend ostream& operator<<(ostream&, const RationalNumber&);
	friend istream& operator>>(istream&, RationalNumber&);

public:
	RationalNumber(int = 1, int = 1);
	RationalNumber operator+(const RationalNumber&) const;
	RationalNumber operator-(const RationalNumber&) const;
	RationalNumber operator*(const RationalNumber&) const;
	RationalNumber operator/(const RationalNumber&) const;
	const RationalNumber& operator=(const RationalNumber&);
	bool operator==(const RationalNumber&) const;
	bool operator!=(const RationalNumber& right) const { return !(*this == right); }
	bool operator>(const RationalNumber&) const;
	bool operator<(const RationalNumber& right) const { return !(*this > right); }
private:
	int numerator;
	int denominator;
	void reduction();
	int nod(int, int[]);
};

