#ifndef FLOORBUTTON_H
#define FLOORBUTTON_H

class Elevator;

class FloorButton
{
public:
	FloorButton(int, Elevator&);
	~FloorButton();

	void pressButton();
	void resetButton();
private:
	int floorNumber;
	bool pressed;

	Elevator& elevatorRef;
};

#endif