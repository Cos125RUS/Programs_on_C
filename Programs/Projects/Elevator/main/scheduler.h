#ifndef SCHEDULER_H
#define SCHEDULER_H

class Floor;

class Scheduler
{
public:
	Scheduler(Floor&, Floor&);
	~Scheduler();
	void processTime(int);
private:
	void sheduleTime(Floor&);

	void delayTime(Floor&);

	Floor& floor1Ref;
	Floor& floor2Ref;
	int floor1ArrivalTime;
	int floor2ArrivalTime;
};

#endif