#include <iostream>
#include <cassert>
#include <cstring>
#include "Employee.h"

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

Employee::~Employee()
{
	delete[] firstName;
	delete[] lastName;
}

const char* Employee::getFirstName() const
{
	return firstName;
}

const char* Employee::getLastName() const
{
	return lastName;
}

void Employee::print() const
{
	cout << firstName << ' ' << lastName;
}