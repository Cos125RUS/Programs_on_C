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
#include "Array.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	Array doubleArray1(3, 3);
	//Array doubleArray2;

	cout << "doubleArray1 rows = " << doubleArray1.getSizeRows() 
		<< "\ndoubleArray1 columns = " << doubleArray1.getSizeColumns()
		<< "\ndoubleArray1:\n" << doubleArray1 << endl;
	//cout << "doubleArray2 rows = " << doubleArray2.getSizeRows()
		//<< "\ndoubleArray2 columns = " << doubleArray2.getSizeColumns()
		//<< "\ndoubleArray2:\n" << doubleArray2 << endl;

	cout << "\nEnter 9 numbers: ";
	cin >> doubleArray1;
	cout << "\ndoubleArray1:\n" << doubleArray1 << endl;

	cout << "\ndoubleArray1[1][2] = " << doubleArray1(1, 2) << endl;

}
