#ifndef CLOCK_H
#define CLOCK_H

class Clock
{
public:
	Clock();
	~Clock();
	void tick();
	int getTime();
private:
	int time;
};

#endif