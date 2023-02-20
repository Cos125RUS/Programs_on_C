#ifndef ELEVATORBUTTON_H
#define ELEVATORBUTTON_H

class Elevator;

class ElevatorButton
{
public:
	ElevatorButton(Elevator &);
	~ElevatorButton();

	void pressButton();
	void resetButton();
private:
	bool pressed;

	Elevator& elevatorRef;
};

#endif