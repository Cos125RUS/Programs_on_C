#include "clock.h"
#include <iostream>

using namespace std;

Clock::Clock() : time(0) { cout << "���� �������\n"; }

Clock::~Clock() { cout << "���� �������\n"; }

void Clock::tick() { time++; }

int Clock::getTime() const { return time; }