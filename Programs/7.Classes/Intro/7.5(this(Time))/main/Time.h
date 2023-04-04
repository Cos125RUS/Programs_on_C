#pragma once
class Time
{
public:
	Time(int = 0, int = 0, int = 0);

	Time &setTime(int, int, int);
	Time &setHour(int);
	Time &setMinute(int);
	Time &setSecond(int);

	int getHour() const;
	int getMinute() const;
	int getSecond() const;

	void printMilitary() const;
	void printStandard() const;

private:
	int hour;
	int minute;
	int second;
};

