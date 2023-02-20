#ifndef DOOR_H
#define DOOR_H

class Door
{
public:
	Door();
	~Door();

	void openDoor();
	void closeDoor();

private:
	bool open;
};

#endif