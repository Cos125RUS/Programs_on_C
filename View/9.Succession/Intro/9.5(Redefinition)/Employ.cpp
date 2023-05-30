#include "Employ.h"
#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

Employee::Employee(const char* first, const char* last)
{
	firstName = new char[strlen(first) + 1];
	assert(firstName != 0);
	strcpy_s(firstName, strlen(first) + 1, first);

	lastName = new char[strlen(last) + 1];
	assert(lastName != 0);
	strcpy_s(lastName, strlen(last) + 1, last);
}

void Employee::print() const { cout << firstName << ' ' << lastName; }

Employee::~Employee()
{
	delete[] firstName;
	delete[] lastName;
}