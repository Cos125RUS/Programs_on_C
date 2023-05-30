#pragma once
class Base2
{
public:
	Base2(char c) { letter = c; }
	char getData() const { return letter; }
protected:
	char letter;
};

