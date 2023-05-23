#include "Item.h"
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

Item::Item(int r, int d) 
{
	ratio = r;
	d < 0 ? degree = 0 : degree = d;
}

Item::Item(char* text)
{
	bool flag = false;
	int index;
	for (int i = 0; i < strlen(text); i++)
		if (text[i] == 'x')
		{
			flag = true;
			index = i;
			break;
		}
	if (flag)
	{
		if (text[index + 1] == '^')
		{
			char* ost;
			strtok_s(text, "x^", &ost);
			char* rat = &text[0];
			char* deg = new char[strlen(ost)];
			for (int i = 0; i < (strlen(ost) - 1); i++)
				deg[i] = ost[i + 1];
			deg[strlen(ost) - 1] = '\0';
			ratio = convertInt(rat);
			degree = convertInt(deg);
		}
		else
		{
			char* num = new char[index + 1];
			for (int i = 0; i < index; i++)
				num[i] = text[i];
			num[index] = '\0';
			ratio = convertInt(num);
			degree = 1;
		}
	}
	else
	{
		ratio = convertInt(text);
		degree = 0;
	}
}

Item Item::operator+(const Item& op2) const
{
	return Item(ratio + op2.ratio, degree);
}

Item Item::operator-(const Item& op2) const
{
	return Item(ratio - op2.ratio, degree);
}

Item Item::operator*(const Item& op2) const
{
	return Item(ratio * op2.ratio, degree);
}

const Item& Item::operator=(const Item& right)
{
	ratio = right.ratio;
	degree = right.degree;
	return *this;
}

ostream& operator<<(ostream& output, const Item& c)
{
	if (c.ratio > 1)
		output << c.ratio;
	if (c.ratio < 0)
		output << " - " << c.ratio * (-1);
	switch (c.degree)
	{
	case 1:
		output << "x";
		break;
	case 0:
		break;
	default:
		output << "x^" << c.degree;
		break;
	}

	return output;
}

istream& operator>>(istream& input, Item& c)
{
	char text[10];
	input >> text;
	c = Item(text);

	return input;
}

int Item::convertInt(char* text)
{
	int num = 0;
	for (int i = strlen(text) - 1, j = 0; i > 0; i--, j++)
		num += (text[i] - 48) * pow(10, j);
	text[0] == '-' ? num *= -1 : num += (text[0] - 48) * pow(10, strlen(text) - 1);

	return num;
}