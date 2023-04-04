#pragma once
#include "Date.h"

class Employee
{
public:
	Employee(const char*, const char*, int, int, int, int, int, int);
	void print() const;
	~Employee();
private:
	char firstName[25];
	char lastName[25];
	const Date birthDate;
	const Date hireDate;
};

