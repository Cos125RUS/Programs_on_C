#include "hourly.h"
#include <iostream>
#include <iomanip>

using namespace std;

HourlyWorker::HourlyWorker(const char* first, const char* last, double initHours, double initWage) 
	: Employee(first, last)
{
	hours = initHours;
	wage = initWage;
}

double HourlyWorker::getPay() const { return wage * hours; }

void HourlyWorker::print() const
{
	cout << "HourlyWorker::print() do...\n\n";
	Employee::print();

	cout << " - рабочий с почасовой оплатой $" << setiosflags(ios::fixed | ios::showpoint)
		<< setprecision(2) << getPay() << endl;
}