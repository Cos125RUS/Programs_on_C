#include <iostream>
#include <cassert>
#include <cstring>
#include "Employee.h"

using namespace std;

Employee::Employee(const char* first, const char* last, Date* b, int dc)
{
	firstName = new char[strlen(first) + 1];
	assert(firstName != 0);
	strcpy_s(firstName, strlen(first) + 1, first);

	lastName = new char[strlen(last) + 1];
	assert(lastName != 0);
	strcpy_s(lastName, strlen(last) + 1, last);

	birthday = b;
	departmentCode = dc;
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

Date* Employee::getBirthday() const
{
	return birthday;
}

int Employee::getDepartmentCode() const
{
	return departmentCode;
}

double Employee::earnings(int month)
{
	return birthday->getMonth() == month ? 100.0 : 0.0;
}

void Employee::print() const
{
	cout << firstName << ' ' << lastName << ' ' << *birthday << ' ' << "Department Code: " << departmentCode;
}