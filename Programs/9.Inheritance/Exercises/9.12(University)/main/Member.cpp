#include "Member.h"
#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

Member::Member(const char* fn, const char* ln, int a)
{
	setAge(a);
	setName(fn, ln);
}

void Member::setName(const char* fn, const char* ln)
{
	firstName = new char[strlen(fn) + 1];
	assert(firstName != 0);
	strcpy_s(firstName, strlen(fn) + 1, fn);

	lastName = new char[strlen(ln) + 1];
	assert(lastName != 0);
	strcpy_s(lastName, strlen(ln) + 1, ln);
}

void Member::setAge(int a)
{
	age = (a > 16 ? a : 17);
}

//Member::~Member()
//{
	//delete[] firstName;
	//delete[] lastName;
//}

ostream& operator<<(ostream& output, const Member& m)
{
	output << m.getFirstName() << " " << m.getLastName() << " (" << m.getAge() << " лет)";

	return output;
}