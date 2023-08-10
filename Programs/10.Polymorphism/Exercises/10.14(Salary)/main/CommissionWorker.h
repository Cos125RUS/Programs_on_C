#pragma once
#include "Employee.h"

class CommissionWorker : public Employee
{
public:
	CommissionWorker(const char*, const char*, Date*, int, double = 0.0, double = 0.0, int = 0);
	void setSalary(double);
	void setCommission(double);
	void setQuantity(int);
	virtual double earnings(int);
	virtual void print() const;
private:
	double salary;
	double commission;
	int quantity;
};

