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
#include "HugeInt.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	HugeInt n1(7654321), n2(7891234), n3("9999999999999999999999999999"), n4(" 1"), n5;
	cout << "n1 = " << n1 << endl
		<< "n2 = " << n2 << endl
		<< "n3 = " << n3 << endl
		<< "n4 = " << n4 << endl
		<< "n5 = " << n5 << endl;

	n5 = n1 + n2;
	cout << "\nn1 + n2\n" << n1 << " + " << n2 << " = " << n5 << endl;
	cout << "\nn3 + n4\n" << n3 << " + " << n4 << " = " << (n3 + n4) << endl;
	n5 = n1 + 9;
	cout << "\nn1 + 9\n" << n1 << " + " << 9 << " = " << n5 << endl;
	n5 = n2 + "10000";
	cout << "\nn2 + 10000\n" << n2 << " + " << 10000 << " = " << n5 << endl;
}