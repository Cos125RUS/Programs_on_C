#include "Emply.h"
#include <cstring>
#include <string.h>
#include <iostream>
#include <cassert>

using namespace std;

int Employee::count = 0;

int Employee::getCount() { return count; }

Employee::Employee(const char* first, const char* last)
{
	int length = strlen(first);
	length = (length < 25 ? length : 24);
	strncpy_s(firstName, first, length);
	firstName[length] = '\0';

	length = strlen(last);
	length = (length < 25 ? length : 24);
	strncpy_s(lastName, last, length);
	lastName[length] = '\0';

	++count;

	cout << "Конструктор Employee для " << firstName << ' ' << lastName << " вызван." << endl;
}

Employee::~Employee()
{
	cout << "Деструктор Employee: " << lastName << ", " << firstName << endl;
	delete[] firstName;
	delete[] lastName;
	--count;
}

const char* Employee::getFirstName() const { return firstName; }
const char* Employee::getLastName() const { return lastName; }