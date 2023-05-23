#include "RationalNumber.h"
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

RationalNumber::RationalNumber(int n, int d)
{
	numerator = n;
	if (d < 0) d = -d;
	d == 0 ? denominator = 1 : denominator = d;
	reduction();
}

void RationalNumber::reduction()
{
	int n = numerator, d = denominator;
	int* nDivider = new int[n / 2];
	int* dDivider = new int[d / 2];
	int sizeN = nod(n, nDivider);
	int sizeD = nod(d, dDivider);
	for (int i = 0, j = 0; i < sizeN; i++)
		for (int j = 0; j < sizeD; j++)
		{
			if (nDivider[i] != 0 && (nDivider[i] == dDivider[j]))
			{
				numerator /= nDivider[i];
				denominator /= nDivider[i];
				nDivider[i] = 0;
				dDivider[j] = 0;
				break;
			}
		}
}

int RationalNumber::nod(int num, int arr[])
{
	int i = 2, count = 0;
	while (num > 1)
		if (num % i == 0)
		{
			num = num / i;
			arr[count] = i;
			count++;
		}
		else
			i++;
	int* newArr = new int[count];
	for (int j = 0; j < count; j++)
		newArr[j] = arr[j];
	arr = newArr;
	return count;
}

RationalNumber RationalNumber::operator+(const RationalNumber& operand2) const
{
	int sumNumerator, sumDenomenator;
	if (denominator == operand2.denominator)
	{
		sumDenomenator = denominator;
		sumNumerator = numerator + operand2.numerator;
	}
	else
	{
		sumDenomenator = denominator * operand2.denominator;
		sumNumerator = numerator* operand2.denominator + operand2.numerator* denominator;
	}
	return RationalNumber(sumNumerator, sumDenomenator);
}

RationalNumber RationalNumber::operator-(const RationalNumber& operand2) const
{
	int sumNumerator, sumDenomenator;
	if (denominator == operand2.denominator)
	{
		sumDenomenator = denominator;
		sumNumerator = numerator - operand2.numerator;
	}
	else
	{
		sumDenomenator = denominator * operand2.denominator;
		sumNumerator = numerator * operand2.denominator - operand2.numerator * denominator;
	}
	return RationalNumber(sumNumerator, sumDenomenator);
}

RationalNumber RationalNumber::operator*(const RationalNumber& operand2) const
{
	return RationalNumber(numerator * operand2.numerator, denominator * operand2.denominator);
}

RationalNumber RationalNumber::operator/(const RationalNumber& operand2) const
{
	return (*this) * RationalNumber(operand2.denominator, operand2.numerator);
}

const RationalNumber& RationalNumber::operator=(const RationalNumber& right)
{
	numerator = right.numerator;
	denominator = right.denominator;
	return *this;
}

bool RationalNumber::operator==(const RationalNumber& right) const
{
	if (numerator != right.numerator)
		return false;

	if (denominator != right.denominator)
		return false;

	return true;
}

bool RationalNumber::operator>(const RationalNumber& right) const
{
	if (denominator == right.denominator)
		return numerator > right.numerator;
	else
		return (numerator * right.denominator) > (right.numerator * denominator);
}

ostream& operator<<(ostream& output, const RationalNumber& c)
{
	output << c.numerator << "/" << c.denominator;
	return output;
}

istream& operator>>(istream& input, RationalNumber& c)
{
	char text[20];
	input >> text;
	char* den;
	strtok_s(text, "/", &den);
	char* num = &text[0];
	int n = 0, d = 0;
	for (int i = strlen(num) - 1, j = 0; i >= 0; i--, j++)
		n += (num[i] - 48) * pow(10, j);
	for (int i = strlen(den) - 1, j = 0; i >= 0; i--, j++)
		d += (den[i] - 48) * pow(10, j);

	c.numerator = n;
	c.denominator = d;
	return input;
}