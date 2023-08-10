#include "CommissionWorker.h"
#include <iostream>

using namespace std;

CommissionWorker::CommissionWorker(const char* first, const char* last, Date* b, int dc, double s, double c, int q) 
	: Employee(first, last, b, dc)
{
	setSalary(s);
	setCommission(c);
	setQuantity(q);
}

void CommissionWorker::setSalary(double s)
{
	salary = s > 0 ? s : 0;
}

void CommissionWorker::setCommission(double c)
{
	commission = c > 0 ? c : 0;
}

void CommissionWorker::setQuantity(int q)
{
	quantity = q > 0 ? q : 0;
}

double CommissionWorker::earnings(int month) 
{
	return salary + commission * quantity + Employee::earnings(month);
}

void CommissionWorker::print() const
{
	cout << "\nCommission Worker: ";
	Employee::print();
}