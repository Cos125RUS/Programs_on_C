#pragma once
#include <iostream>

using namespace std;

class Item
{
	friend ostream& operator<<(ostream&, const Item&);
	friend istream& operator>>(istream&, Item&);

public:
	Item(int = 1, int = 1);
	Item(char*);
	Item operator+(const Item&) const;
	Item operator-(const Item&) const;
	Item operator*(const Item&) const;
	const Item& operator=(const Item&);
	int getRatio() { return ratio; };
	int getDegree() { return degree; };
	void setRatio(int r) { ratio = r; }
private:
	int ratio;
	int degree;
	int convertInt(char* );
};

