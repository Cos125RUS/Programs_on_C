#include "Emply.h"
#include "Date.h"
#include <cstring>
#include <string.h>
#include <iostream>

using namespace std;

Employee::Employee(const char* fname, const char* lname, int bmonth, int bday, int byear, int hmonth, int hday, int hyear)
	: birthDate(bmonth, bday, byear), hireDate(hmonth, hday, hyear)
{
	int length = strlen(fname);
	length = (length < 25 ? length : 24);
	strncpy_s(firstName, fname, length);
	firstName[length] = '\0';

	length = strlen(lname);
	length = (length < 25 ? length : 24);
	strncpy_s(lastName, lname, length);
	lastName[length] = '\0';

	cout << "Конструктор объекта Employee: " << firstName << ' ' << lastName << endl;
}

void Employee::print() const
{
	cout << lastName << ", " << firstName << "\nНанят: ";
	hireDate.print();
	cout << " День рождения: ";
	birthDate.print();
	cout << endl;
}

Employee::~Employee()
{
	cout << "Деструктор объекта Employee: " << lastName << ", " << firstName << endl;
}