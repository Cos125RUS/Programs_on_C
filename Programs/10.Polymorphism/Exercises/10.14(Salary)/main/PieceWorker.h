#pragma once
#include "Employee.h"

class PieceWorker : public Employee
{
public:
	PieceWorker(const char*, const char*, Date*, int, double = 0.0, int = 0);
	void setWage(double);
	void setQuantity(int);
	virtual double earnings(int);
	virtual void print() const;
private:
	double wagePerPiece;
	int quantity;
};

