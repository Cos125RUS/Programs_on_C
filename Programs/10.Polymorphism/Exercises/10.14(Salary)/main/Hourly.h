#pragma once
#include "Employee.h"

class HourlyWorker : public Employee
{
public:
	HourlyWorker(const char*, const char*, Date*, int, double = 0.0, double = 0.0);
	void setWage(double);
	void setHours(double);
	virtual double earnings(int);
	virtual void print() const;
private:
	double wage;
	double hours;
};

