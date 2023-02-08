#include <iostream>
#include <iomanip>
#include "salesp.h"

using namespace std;

SalesPerson::SalesPerson()
{
	for (int i = 0; i < 12; i++)
		sales[i] = 0.0;
}

void SalesPerson::getSalesFromUser()
{
	double salesFigure;

	for (int i = 1; i <= 12; i++)
	{
		cout << "¬ведите объЄм продаж за мес€ц " << i << ": ";
		cin >> salesFigure;
		SetSales(i, salesFigure);
	}
}


void SalesPerson::SetSales(int month, double amount)
{
	if (month >= 1 && month <= 12 && month > 0)
		sales[month - 1] = amount;
	else
		cout << "ќшибочный мес€ц или сведени€ о продажах\n";
}


void SalesPerson::printAnnualSales()
{
	cout << setprecision(2) << setiosflags(ios::fixed | ios::showpoint)
		<< "\n—умма продаж за год: $" << totalAnnualSales() << endl;
}


double SalesPerson::totalAnnualSales()
{
	double total = 0.0;

	for (int i = 0; i < 12; i++)
		total += sales[i];

	return total;
}