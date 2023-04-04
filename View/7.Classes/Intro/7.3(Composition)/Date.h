#pragma once
class Date
{
public:
    Date(int = 1, int = 1, int = 1990);
    void print() const;
    ~Date();
private:
    int month;
    int day;
    int year;
    int checkDay(int);
};

