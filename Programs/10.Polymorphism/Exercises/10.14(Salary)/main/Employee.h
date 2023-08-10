#pragma once
#include "Date.h"

class Employee
{
public:
	Employee(const char*, const char*, Date*, int);
	~Employee();
	const char* getFirstName() const;
	const char* getLastName() const;
	Date* getBirthday() const;
	int getDepartmentCode() const;

	virtual double earnings(int);
	virtual void print() const;

private:
	char* firstName;
	char* lastName;
	Date* birthday;
	int departmentCode;
};

