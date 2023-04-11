#ifndef BUILDING_H
#define BUILDING_H

#include "elevator.h"
#include "floor.h"
#include "clock.h"
#include "scheduler.h"


class Building
{
public:
	Building();
	~Building();

	void runSimulation(int);
private:
	Floor floor1;
	Floor floor2;
	Elevator elevator;
	Clock clock;
	Scheduler scheduler;
};

#endif