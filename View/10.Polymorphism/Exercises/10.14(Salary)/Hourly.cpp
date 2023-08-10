#include "Hourly.h"
#include <iostream>

using namespace std;

HourlyWorker::HourlyWorker(const char* first, const char* last, Date* b, int dc, double w, double h) : Employee(first, last, b, dc)
{
	setWage(w);
	setHours(h);
}

void HourlyWorker::setWage(double w)
{
	wage = w > 0 ? w : 0;
}

void HourlyWorker::setHours(double h)
{
	hours = h >= 0 && h < 168 ? h : 0;
}

double HourlyWorker::earnings(int month) 
{
	if (hours <= 40)
		return wage * hours + Employee::earnings(month);
	else
		return 40 * wage + (hours - 40) * wage * 1.5 + Employee::earnings(month);
}

void HourlyWorker::print() const
{
	cout << "\nHourly Worker:\t";
	Employee::print();
}