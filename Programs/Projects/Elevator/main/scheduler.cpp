#include "scheduler.h"
#include <iostream>
#include "floor.h"
#include "person.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Scheduler::Scheduler(Floor& firstFloor, Floor& secondFloor) : currentClockTime(0), floor1Ref(firstFloor), floor2Ref(secondFloor)
{
	srand(time(0));
	cout << "Планировщик создан\n";

	scheduleTime(floor1Ref);
	scheduleTime(floor2Ref);
}

Scheduler::~Scheduler() { cout << "Планировщик удалён\n"; }

void Scheduler::scheduleTime(const Floor& floor)
{
	int floorNumber = floor.getNumber();
	int arrivalTime = currentClockTime + (5 + rand() % 16);

	floorNumber == Floor::FLOOR1 ? floor1ArrivalTime = arrivalTime : floor2ArrivalTime = arrivalTime;

	cout << "(Планировщик назначает следующего человека на этаж " << floorNumber << " в " << arrivalTime << ")\n";
}

void Scheduler::delayTime(const Floor& floor)
{
	int floorNumber = floor.getNumber();

	int arrivalTime = (floorNumber == Floor::FLOOR1) ? ++floor1ArrivalTime : ++floor2ArrivalTime;

	cout << "(Планировщик задерживает следующего человека на этаже " << floorNumber << " на " << arrivalTime << ")\n";
}

void Scheduler::processTime(int time)
{
	currentClockTime = time;

	handleArrivals(floor1Ref, currentClockTime);
	handleArrivals(floor2Ref, currentClockTime);
}

void Scheduler::createNewPerson(Floor& floor)
{
	int destinationFloor = floor.getNumber() == Floor::FLOOR1 ? Floor::Floor2 : Floor::FLOOR1;

	Person* newPersonPtr = new Person(destinationFloor);

	cout << "Планировщик оздаёт человека " << newPersonPtr->getID() << endl;
	newPersonPtr->stepOntoFloor(floor);
	scheduleTime(floor);
}

void Scheduler::handleArrivals(Floor& floor, int time)
{
	int floorNumber = floor.getNumber();

	int arrivalTime = (floorNumber == Floor::FLOOR1) ? floor1ArrivalTime : floor2ArrivalTime;

	if (arrivalTime == time)
	{
		if (floor.isOccupied())
			delayTime(floor);
		else
			createNewPerson(floor);
	}
}