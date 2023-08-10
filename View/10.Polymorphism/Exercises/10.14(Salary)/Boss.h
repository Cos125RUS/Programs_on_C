#pragma once
#include "Employee.h"

class Boss : public Employee
{
public:
	Boss(const char*, const char*, Date*, int, double = 0.0);
	void setWeeklySalary(double);
	virtual double earnings(int);
	virtual void print() const;
private:
	double weeklySalary;
};

