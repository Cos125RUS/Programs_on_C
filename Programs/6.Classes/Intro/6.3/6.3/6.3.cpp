#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include <string.h>
#include <errno.h>
#include <ctype.h>

using namespace std;

struct Time {
	int hours;
	int minutes;
	int second;
};


int main()
{
	setlocale(LC_ALL, "Russian");


	Time timeObject, timeArray[10], * timePtr;

	timeObject = { 12,12,12 };
	timePtr = &timeObject;
	cout << timeObject.hours << endl;
	cout << timePtr->hours;








	cout << "\n\n\n\n\n\n\n\n\n\n";

}