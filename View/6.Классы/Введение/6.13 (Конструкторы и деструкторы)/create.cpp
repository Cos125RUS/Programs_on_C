#include <iostream>
#include <locale>
#include "create.h"

using namespace std;

CreateAndDestroy::CreateAndDestroy(int value)
{
	setlocale(LC_ALL, "Russian");

	data = value;
	cout << "Объект " << data << " конструктор";
}

CreateAndDestroy::~CreateAndDestroy()
{
	setlocale(LC_ALL, "Russian");

	cout << "Объект " << data << " деструктор\n";
}