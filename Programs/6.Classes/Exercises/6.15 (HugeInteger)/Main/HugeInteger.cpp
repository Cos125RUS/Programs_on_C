#include "HugeInteger.h"
#include <iostream>

using namespace std;

HugeInteger::HugeInteger(const char* num)
{
	if (check(num))
		set(num);
}

HugeInteger::~HugeInteger(){ }

bool HugeInteger::check(const char* num)
{
	for (int i = 0; num[i] != '\0'; i++)
		if (!isdigit(num[i]))
		{
			cout << "Not a number!\n";
			return false;
		}
	return true;
}

void HugeInteger::set(const char* num)
{
	int len = strlen(num);
	for (int i = 0; i < len; i++)
		numbers[length - 1 - i] = static_cast<int>(num[len - 1 - i]) - 48;
}

void HugeInteger::outputHugeInteger()
{
	int index;
	for (index = 0; numbers[index] == 0; index++);
	for (int i = index; i < length; i++)
		if (numbers[i] >= 0)
			cout << numbers[i];
		else
			cout << "-";
	cout << endl;
}

void HugeInteger::inputHugeInteger(const char* num)
{
	if (check(num))
	{
		toZero();
		set(num);
	}
}

void HugeInteger::toZero()
{
	for (int i = 0; i < length, numbers[i] = 0; i++);
}

void HugeInteger::addHugeInteger(HugeInteger num)
{
	int *addNumbers = num.get();
	int lustIndex = 0;
	for (lustIndex; numbers[lustIndex] == 0 && addNumbers[lustIndex] == 0; lustIndex++);
	for (int i = length - 1; i > lustIndex - 1; i--)
	{
		numbers[i] += addNumbers[i];
		if (numbers[i] > 9)
			numbers[i - 1]++;
	}
}

void HugeInteger::substractHugeInteger(HugeInteger num)
{
	int* subNumbers = num.get();
	int lustIndex = 0;
	for (lustIndex; numbers[lustIndex] == 0 && subNumbers[lustIndex] == 0; lustIndex++);
	int* max;
	int* min;
	int j = lustIndex - 1;
	while (numbers[j] == subNumbers[j]) j++;
	if (numbers[j] > subNumbers[j])
	{
		max = numbers;
		min = subNumbers;
	}
	else
	{
		max = subNumbers;
		min = numbers;
	}
	for (int i = length - 1; i > lustIndex - 1; i--)
	{
		max[i] -= min[i];
		if (max[i] < 0)
		{
			max[i] = 10 - max[i];
			max[i - 1]--;
		}
	}
	if (numbers[j] < subNumbers[j])
	{
		while (max[j] == 0) j++;
		max[j - 1] = -1;
	}
	for (int i = 0; i < length; numbers[i] = max[i++]);
}

int* HugeInteger::get()
{
	return numbers;
}