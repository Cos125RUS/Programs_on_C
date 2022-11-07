#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include <string.h>
#include <errno.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	const int size = 5;
	unsigned int values[size];
	int i = 0, j = 2;

	for (; i < size; i++, j += 2)
		values[i] = j;

	unsigned int* vPtr;

	for (i = 0; i < size; i++)
		cout << setw(5) << values[i];

	cout << endl << endl;

	vPtr = &values[0];

	for (i = 0; i < size; i++)
		cout << setw(5) << *(vPtr + i);

	cout << endl << endl;

	for (i = 0; i < size; i++)
		cout << setw(5) << *(values + i);

	cout << endl << endl;

	for (i = 0; i < size; i++)
		cout << setw(5) << vPtr[i];

	cout << endl << endl << endl << endl;

	cout << values[4] << ' ' << vPtr[4] << ' ' << *(values + 4) << ' ' << *(vPtr + 4);

	cout << endl << endl << endl << endl;

	vPtr = &values[4];
	cout << vPtr << ' ' << *vPtr;

	cout << endl << endl;

	vPtr -= 4;
	cout << vPtr << ' ' << *vPtr;

	cout << endl << endl;
	cout << vPtr + 3 << ' ' << *(vPtr + 3);




	cout << "\n\n\n\n\n\n\n\n\n\n";

	return 0;
}