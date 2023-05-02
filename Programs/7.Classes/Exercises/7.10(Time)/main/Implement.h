#pragma once
class Implement
{
public:
	Implement(int h, int m, int s) { setValue(h, m, s);	}

	Implement& setTime(int h, int m, int s) 
	{ 
		setValue(h, m, s); 
		return *this;
	}
	Implement& setHour(int h) 
	{	
		second = second % (60 * 60) + 60 * 60 * h; 
		return *this;
	}
	Implement& setMinute(int m) 
	{ 
		int hours = second / (60 * 60);
		second = second % (60 * 60) % 60 + hours * (60 * 60) + 60 * m; 
		return *this;
	}
	Implement& setSecond(int s) 
	{ 
		int hours = second / (60 * 60);
		int min = second % (hours * (60 * 60)) / 60;
		second = hours * 60 * 60 + min * 60 + s; 
		return *this;
	}

	int getHour() const { return second / (60 * 60); }
	int getMinute() const { return (second - getHour() * (60 * 60)) / 60; }
	int getSecond() const { return second - getHour() * (60 * 60) - getMinute() * 60; }
private:
	int second;
	void setValue(int h, int m, int s) { second = s + 60 * m + 60 * 60 * h; }
	int getValue() const { return second; }
};