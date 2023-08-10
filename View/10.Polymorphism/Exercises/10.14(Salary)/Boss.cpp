#include "Boss.h"
#include <iostream>

using namespace std;

Boss::Boss(const char* first, const char* last, Date* b, int dc, double s) : Employee(first, last, b, dc)
{
	setWeeklySalary(s);
}

void Boss::setWeeklySalary(double s)
{
	weeklySalary = s > 0 ? s : 0;
}

double Boss::earnings(int month) 
{ 
	return weeklySalary + Employee::earnings(month);
}

void Boss::print() const
{
	cout << "\nAdministrator:\t";
	Employee::print();
}