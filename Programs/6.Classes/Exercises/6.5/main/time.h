#ifndef TIME_H
#define TIME_H

class Time
{
public:
	Time(int = 0, int = 0, int = 0);
	void time(int,int,int);
	void printTime();
private:
	int hour;
	int minute;
	int second;
};

#endif