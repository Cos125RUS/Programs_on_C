#include "Hourly.h"
#include <iostream>

using namespace std;

HourlyWorker::HourlyWorker(const char* first, const char* last, double w, double h) : Employee(first, last)
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

double HourlyWorker::earnings() const
{
	if (hours <= 40)
		return wage * hours;
	else
		return 40 * wage + (hours - 40) * wage * 1.5;
}

void HourlyWorker::print() const
{
	cout << "\nHourly Worker:\t\t\t";
	Employee::print();
}