#pragma once
#include "Item.h"
#include <iostream>

using namespace std;

class Polinomials
{
	friend ostream& operator<<(ostream&, const Polinomials&);
	friend istream& operator>>(istream&, Polinomials&);

public:
	Polinomials(Item[], int);
	Polinomials operator+(const Polinomials&) const;
	Polinomials operator-(const Polinomials&) const;
	Polinomials operator*(const Polinomials&) const;
	const Polinomials& operator=(const Polinomials);
private:
	int size;
	Item* equation;
	Item convertItem(char*, int*, int*);
};

