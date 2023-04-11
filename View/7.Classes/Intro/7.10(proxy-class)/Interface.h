#pragma once
class Implementation;

class Interface
{
public:
	Interface(int);
	void setValue(int);
	int getValue() const;
	~Interface();
private:
	Implementation* ptr;
};

