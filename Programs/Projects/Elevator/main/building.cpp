#include "building.h"
#include <iostream>

using namespace std;

Building::Building() : floor1(Floor::FLOOR1, elevator), floor2(Floor::FLOOR1, elevator),
					   elevator(floor1, floor2), scheduler(floor1, floor2)
{
	cout << "������ �������\n";
}

Building::~Building() { cout << "������ �������\n"; }

void Building::runSimulation(int totalTime)
{
	int currentTime = 0;

	while (currentTime < totalTime)
	{
		clock.tick();
		currentTime = clock.getTime();
		cout << "TIME: " << currentTime << endl;
		scheduler.processTime(currentTime);
		cin.get();
	}
}