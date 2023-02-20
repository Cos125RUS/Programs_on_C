#ifndef FLOOR_H
#define FLOOR_H

class Elevator;
class Person;

class Floor
{
public:
	Floor(int, Elevator&);
	~Floor();

	bool isOccupied() const;

	int getNumber() const;

	void personArrives(Person* const);

	Person* elevatorArrived();

	void elevatoeLeaving();

private:
	int floorNumber;
	Elevator& elevatorRef;
};

#endif