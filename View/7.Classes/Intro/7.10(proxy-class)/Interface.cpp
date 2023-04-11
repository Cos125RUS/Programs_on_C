#include "Interface.h"
#include "Implementation.h"

Interface::Interface(int v) : ptr (new Implementation(v)){}

void Interface::setValue(int v) { ptr->setValue(v); }

int Interface::getValue() const { return ptr->getValue(); }

Interface::~Interface() { delete ptr; }