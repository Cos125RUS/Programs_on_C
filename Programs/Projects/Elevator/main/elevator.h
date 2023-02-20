#ifndef ELEVATOR_H
#define ELEVATOR_H

class Floor;
class Person;

class Elevator
{
public:
	Elevator(Floor &, Floor &);
	~Elevator();

	void summonElevator(int);

	void prepareToLeave();

	void processTime(int);

	void passengerEnters(Person* const);

	void passengerExits();

private:
	bool moving;

	int direction;
	int currentTime;

	int arrivalTime;

	Floor& floor1Ref;
	Floor& floor2Ref;

};

#endif