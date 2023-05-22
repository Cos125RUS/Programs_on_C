#include "HugeInt.h"
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

//int HugeInt::count = 0;

HugeInt::HugeInt(long val)
{
	int i;

	for (i = 0; i <= 29; i++)
		integer[i] = 0;

	for (i = 29; val != 0 && i >= 0; i--)
	{
		integer[i] = val % 10;
		val /= 10;
	}
}

HugeInt::HugeInt(const char* string)
{
	int i, j;

	for (i = 0; i <= 29; i++)
		integer[i] = 0;

	for (i = 30 - strlen(string), j = 0; i <= 29; i++, j++)
		if (isdigit(string[j]))
			integer[i] = string[j] - '0';
}

HugeInt HugeInt::operator+(const HugeInt& op2)
{
	HugeInt temp;
	int carry = 0;

	for (int i = 29; i >= 0; i--)
	{
		temp.integer[i] = integer[i] + op2.integer[i] + carry;

		if (temp.integer[i] > 9)
		{
			temp.integer[i] %= 10;
			carry = 1;
		}
		else
			carry = 0;
	}

	return temp;
}

HugeInt HugeInt::operator+(int op2)
{ return *this + HugeInt(op2); }

HugeInt HugeInt::operator+(const char *op2)
{ return *this + HugeInt(op2); }

ostream& operator<<(ostream& output, const HugeInt& num)
{
	int i;

	for (i = 0; (num.integer[i] == 0) && (i <= 29); i++);

	if (i == 30)
		output << 0;
	else
		for (; i <= 29; i++)
			output << num.integer[i];

	return output;
}