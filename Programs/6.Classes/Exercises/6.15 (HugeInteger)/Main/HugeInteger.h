#pragma once

const int length = 40;

class HugeInteger
{
public:
	HugeInteger(const char* = "0");
	~HugeInteger();
	void inputHugeInteger(const char*);
	void outputHugeInteger();
	void addHugeInteger(HugeInteger);
	void substractHugeInteger(HugeInteger);

	int* get();
private:
	int numbers[length] = { 0 };

	bool check(const char*);
	void set(const char*);
	void toZero();
};

