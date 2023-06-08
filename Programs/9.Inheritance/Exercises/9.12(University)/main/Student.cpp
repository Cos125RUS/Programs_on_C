#include "Student.h"
#include <cassert>
#include <cstring>

using namespace std;

Student::Student(const char* d, const char* fn, const char* ln, int a) : Member(fn, ln, a)
{
	setDirection(d);
	evaluations = new int[20];
	index = 0;
}

void Student::setDirection(const char* d)
{
	direction = new char[strlen(d) + 1];
	assert(direction != 0);
	strcpy_s(direction, strlen(d) + 1, d);
}

Student Student::newEvaluation(int e)
{
	if (e > 0 && e < 6)
		evaluations[index++] = e;
	else
		cout << "Что за оценка такая?";

	return *this;
}

void Student::printEvaluation()
{
	cout << "[ ";
	for (int i = 0; i < index; i++)
		cout << evaluations[i] << " ";
	cout << "]";
}

//Student::~Student()
//{
	//delete[] direction;
	//delete[] evaluations;
//}

ostream& operator<<(ostream& output, const Student& s)
{
	output << static_cast<Member>(s) << " '" << s.getDirection() << "'";

	return output;
}