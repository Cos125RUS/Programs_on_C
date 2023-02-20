#ifndef PERSON_H
#define PERSON_H

class Person
{
public:
	Person();
	~Person();
	int getID() const;
	void  stepOntoFloor();
	void enterElevator();
	void exitElevator();
private:
	int ID;
};

#endif