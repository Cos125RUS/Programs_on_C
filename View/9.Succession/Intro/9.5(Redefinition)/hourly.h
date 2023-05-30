#pragma once
#include "Employ.h"
class HourlyWorker : public Employee
{
public:
	HourlyWorker(const char*, const char*, double, double);
	double getPay() const;
	void print() const;
private:
	double wage;
	double hours;
};

