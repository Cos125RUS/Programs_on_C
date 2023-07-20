#include "PieceWorker.h"
#include <iostream>

using namespace std;

PieceWorker::PieceWorker(const char* first, const char* last, double w, int q) : Employee(first, last)
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

double PieceWorker::earnings() const
{
	return quantity * wagePerPiece;
}

void PieceWorker::print() const
{
	cout << "\nPeice Worker:\t\t\t";
	Employee::print();
}