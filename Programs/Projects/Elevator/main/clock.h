#ifndef CLOCK_H
#define CLOCK_H

class Clock
{
public:
	Clock();
	~Clock();
	void tick();
	int getTime() const;
private:
	int time;
};

#endif