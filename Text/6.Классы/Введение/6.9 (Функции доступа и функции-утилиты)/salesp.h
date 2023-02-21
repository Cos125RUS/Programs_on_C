#ifndef SALASP_H
#define SALASP_H

class SalesPerson
{
public:
	SalesPerson();
	void getSalesFromUser();
	void SetSales(int, double);

	void printAnnualSales();

private:
	double totalAnnualSales();
	double sales[12];
};

#endif