#pragma once
class Employee
{
public:
	Employee(const char*, const char*);
	void print() const;
	~Employee();
private:
	char* firstName;
	char* lastName;
};

