#pragma once
#include <iostream>
#include "Member.h"

using namespace std;

class Student : Member
{
	friend ostream& operator<<(ostream&, const Student&);
public:
	Student(const char*, const char*, const char*, int = 17);
	void setDirection(const char*);
	char* getDirection() const { return direction; }
	int* getEvaluations() const { return evaluations; }
	Student newEvaluation(int);
	void printEvaluation();
	//~Student();
protected:
	char* direction;
	int* evaluations;
	int index;
};

