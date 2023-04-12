#include "IntegerSet.h"
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

IntegerSet::IntegerSet(int indexs[], int len)
{
	for (int i = 0; i < len; i++)
		setArray(indexs[i]);
}

void IntegerSet::setArray(int i)
{
	if (i >= 0)
		array[i] = 1;
}

IntegerSet &IntegerSet::unionOfIntegerSet(IntegerSet set2)
{

	for (int i = 0; i < 100; i++)
		if (getIndex(i) || set2.getIndex(i))
			array[i] = 1;

	return *this;
}

bool IntegerSet::getIndex(int i)
{
	return array[i];
}

IntegerSet& IntegerSet::intersectionOfIntegerSet(IntegerSet set2)
{
	for (int i = 0; i < 100; i++)
		if (getIndex(i) && set2.getIndex(i))
			array[i] = 1;
		else
			array[i] = 0;

	return *this;
}

void IntegerSet::insertElement(int i)
{
	array[i] = 1;
}

void IntegerSet::deletElement(int i)
{
	array[i] = 0;
}

bool IntegerSet::isEqualTo(IntegerSet set2)
{
	for (int i = 0; i < 100; i++)
		if (getIndex(i) != set2.getIndex(i))
			return false;

	return true;
}

void IntegerSet::print()
{
	for (int i = 0; i < 100; i++)
	{
		if (i % 25 == 0)
			cout << endl;
		cout << array[i] << ' ';
	}
	cout << endl;
}

IntegerSet::~IntegerSet()
{
	//delete[] array;
}