#include "salesp.h"
#include <locale>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	SalesPerson s;

	s.getSalesFromUser();
	s.printAnnualSales();



	cout << "\n\n\n\n\n\n\n\n\n\n";

	return 0;
}