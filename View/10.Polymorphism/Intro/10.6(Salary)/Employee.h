#pragma once
class Employee
{
public:
	Employee(const char*, const char*);
	~Employee();
	const char* getFirstName() const;
	const char* getLastName() const;

	virtual double earnings() const = 0;
	virtual void print() const;

private:
	char* firstName;
	char* lastName;
};

