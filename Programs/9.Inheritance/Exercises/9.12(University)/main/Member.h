#pragma once
#include <iostream>

using namespace std;

class Member
{
	friend ostream& operator<<(ostream&, const Member&);
public:
	Member(const char*, const char*, int = 17);
	void setName(const char*, const char*);
	void setAge(int);
	int getAge() const { return age; }
	char* getFirstName() const { return firstName; }
	char* getLastName() const { return lastName; }
	//~Member();
protected:
	int age;
	char* firstName;
	char* lastName;
};

