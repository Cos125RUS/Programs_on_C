#ifndef TIME_H
#define TIME_H

class Time
{
public:
    Time(int = 0, int = 0, int = 0);
    void setTime(int, int, int);
    void printMilitary();
    void printStandard();
private:
    int hour;
    int minute;
    int second;
};



#endif