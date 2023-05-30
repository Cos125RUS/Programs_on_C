#include "Polinomials.h"
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

Polinomials::Polinomials(Item e[], int s)
{
	int max = 0;
	for (int i = 0; i < s; i++)
		if (e[i].getDegree() > max)
			max = e[i].getDegree();
	size = max + 1;
	equation = new Item[size];
	for (int i = 0; i < size; i++)
		equation[i] = Item(0, 0);
	for (int i = 0; i < s; i++)
	{
		equation[e[i].getDegree()] = e[i];
	}
}

Polinomials Polinomials::operator+(const Polinomials& op2) const
{
	int newSize;
	size > op2.size ? newSize = size : newSize = op2.size;
	Item* newEquation = new Item[newSize];
	for (int i = 0; i < newSize; i++)
		newEquation[i] = equation[i] + op2.equation[i];
	return Polinomials(newEquation, newSize);
}

Polinomials Polinomials::operator-(const Polinomials& op2) const
{
	int newSize;
	size > op2.size ? newSize = size : newSize = op2.size;
	Item* newEquation = new Item[newSize];
	for (int i = 0; i < newSize; i++)
		newEquation[i] = equation[i] - op2.equation[i];
	return Polinomials(newEquation, newSize);
}

Polinomials Polinomials::operator*(const Polinomials& op2) const
{
	int newSize;
	size > op2.size ? newSize = size : newSize = op2.size;
	Item* newEquation = new Item[newSize];
	for (int i = 0; i < newSize; i++)
		newEquation[i] = equation[i] * op2.equation[i];
	return Polinomials(newEquation, newSize);
}

const Polinomials& Polinomials::operator=(const Polinomials op2)
{
	size = op2.size;
	equation = op2.equation;
	return *this;
}

ostream& operator<<(ostream& output, const Polinomials& c)
{
	output << c.equation[c.size - 1];
	for (int i = c.size - 2; i >= 0; i--)
	{
		if (c.equation[i].getRatio() > 0)
			output << " + ";
		output << c.equation[i];
	}
	output << " = 0";
		
	return output;
}

istream& operator>>(istream& input, Polinomials& c)
{
	char text[100];
	input >> text;

	char* zero;
	strtok_s(text, "=", &zero);
	char* func = &text[0];

	c.size = 1;
	for (int i = 0; i < strlen(func); i++)
		if ((func[i] == '+') || (func[i] == '-'))
			c.size++;

	int lastIndex = 0, count = 0;
	for (int i = 0; i < strlen(func); i++)
	{
		if (func[i] == '+')
		{
			c.equation[count++] = c.convertItem(func, &i, &lastIndex);
		}
		if (func[i] == '-')
		{
			c.equation[count] = c.convertItem(func, &i, &lastIndex);
			c.equation[count++].setRatio(-1);
		}
	}

	return input;
}

Item Polinomials::convertItem(char* func, int* i, int* lastIndex)
{
	int len = *i - *lastIndex;
	char* item = new char[len];
	for (int j = 0; j < len; j++)
		item[j] = func[*lastIndex + j];
	lastIndex = i;
	return Item(item);
}