#ifndef LIGHT_H
#define LIGHT_H

class Light
{
public:
	Light(char*);
	~Light();
	void turnOn();
	void turnOff();
private:
	bool on;
	char* name;
};

#endif