#include "clock.h"
#include <iostream>

using namespace std;

Clock::Clock() : time(0) { cout << "Часы созданы\n"; }

Clock::~Clock() { cout << "Часы удалены\n"; }

void Clock::tick() { time++; }

int Clock::getTime() const { return time; }