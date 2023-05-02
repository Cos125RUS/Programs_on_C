#include "Time.h"
#include "Implement.h"
#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include <string.h>
#include <errno.h>
#include <ctype.h>

using namespace std;

Time::Time(int h, int m, int s) : ptr(new Implement(h, m, s)) {}
Time& Time::setTime(int h, int m, int s) 
{ 
	ptr->setTime(h, m, s); 
	return *this;
}

Time& Time::setHour(int h) 
{ 
	ptr->setHour(h); 
	return *this;
}

Time& Time::setMinute(int m) 
{ 
	ptr->setMinute(m); 
	return *this;
}

Time& Time::setSecond(int s)
{ 
	ptr->setSecond(s); 
	return *this;
}

int Time::getHour() const { return ptr->getHour(); }
int Time::getMinute() const { return ptr->getMinute(); }
int Time::getSecond() const { return ptr->getSecond(); }

void Time::printMilitary() const
{
	cout << (ptr->getHour() < 10 ? "0" : "") << ptr->getHour() << ":" 
		<< (ptr->getMinute() < 10 ? "0" : "") << ptr->getMinute()
		<< ":" << (ptr->getSecond() < 10 ? "0" : "") << ptr->getSecond() << endl;
}

void Time::printStandard() const
{
	cout << ((ptr->getHour() == 0 || ptr->getHour() == 12) ? 12 : ptr->getHour() % 12) << ":" 
		<< (ptr->getMinute() < 10 ? "0" : "") << ptr->getMinute() << ":" 
		<< (ptr->getSecond() < 10 ? "0" : "") << ptr->getSecond() << (ptr->getHour() < 12 ? " AM" : " PM") << endl;

}

Time::~Time() { delete ptr; }

