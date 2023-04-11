#pragma once
class Date
{
public:
    Date(int, int, int);
    Date(int, int);
    Date();
    void print() const;
    ~Date();
private:
    int month;
    int day;
    int year;
    int checkDay(int);
};

