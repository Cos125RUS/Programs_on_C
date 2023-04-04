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

	const int size = 10;
	double numbers[size] = { 0.0,1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9 };
	double* nPtr;

	nPtr = numbers;

	for (int i = 0; i < size; i++)
		cout << setw(5) << setiosflags(ios::showpoint | ios::fixed) << setprecision(1) << numbers[i];

	cout << endl << endl;

	for (int i = 0; i < size; i++)
		cout << setw(5) << setiosflags(ios::showpoint | ios::fixed) << setprecision(1) << nPtr[i];

	cout << endl << endl;

	for (int i = 0; i < size; i++)
		cout << setw(5) << setiosflags(ios::showpoint | ios::fixed) << setprecision(1) << *(nPtr + i);

	cout << endl << endl << endl << endl;

	for (int i = 0; i < size; i++)
		cout << setw(5) << setiosflags(ios::showpoint | ios::fixed) << setprecision(1) << *(numbers + i);

	cout << endl << endl;

	nPtr = &numbers[0];
	cout << endl << endl << nPtr << endl;
	*nPtr = numbers[0];
	cout << endl << nPtr << endl;

	cout << endl << endl;

	cout << numbers[3] << endl;
	cout << *(numbers + 3) << endl;
	cout << nPtr[3] << endl;
	cout << *(nPtr + 3) << endl;

	cout << endl << endl;

	nPtr = numbers;

	cout << endl << &*(nPtr+8) << endl;

	cout << endl << endl;

	*nPtr = numbers[5];
	nPtr -= 4;
	cout << endl << *nPtr << endl; // запрещённая форма




	cout << "\n\n\n\n\n\n\n\n\n\n";

	return 0;
}