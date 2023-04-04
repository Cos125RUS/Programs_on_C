#pragma once

class Employee
{
public:
	Employee(const char*, const char*);
	~Employee();

	const char* getFirstName() const;
	const char* getLastName() const;

	static int getCount();
private:
	char firstName[25];
	char lastName[25];

	static int count;
};

