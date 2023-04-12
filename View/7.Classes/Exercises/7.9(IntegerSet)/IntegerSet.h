#pragma once
class IntegerSet
{
public:
	IntegerSet(int[], int);
	~IntegerSet();
	IntegerSet &unionOfIntegerSet(IntegerSet);
	IntegerSet &intersectionOfIntegerSet(IntegerSet);
	void insertElement(int);
	void deletElement(int);
	bool isEqualTo(IntegerSet);

	void print();
private:
	int array[100] = { 0 };
	void setArray(int);
	bool getIndex(int);
};

