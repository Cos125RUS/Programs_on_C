#pragma once
class Base1
{
public:
	Base1(int x) { value = x; }
	int getData() const { return value; }
protected:
	int value;
};

