#include "PieceWorker.h"
#include <iostream>

using namespace std;

PieceWorker::PieceWorker(const char* first, const char* last, Date* b, int dc, double w, int q) : Employee(first, last, b, dc)
{
	setWage(w);
	setQuantity(q);
}

void PieceWorker::setWage(double w)
{
	wagePerPiece = w > 0 ? w : 0;
}

void PieceWorker::setQuantity(int q)
{
	quantity = q > 0 ? q : 0;
}

double PieceWorker::earnings(int month) 
{
	return quantity * wagePerPiece + Employee::earnings(month);
}

void PieceWorker::print() const
{
	cout << "\nPeice Worker:\t";
	Employee::print();
}