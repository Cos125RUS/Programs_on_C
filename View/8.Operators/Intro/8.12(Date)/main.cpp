#include "Date.h"
#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include <cassert>
#include <string.h>
#include <errno.h>
#include <ctype.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	Date d1, d2(12, 27, 1992), d3(0, 99, 8045);
	cout << "d1 = " << d1 << "\nd2 = " << d2 << "\nd3 = " << d3 << "\n\n";
	cout << "d2 + 7 = " << (d2 += 7) << "\n\n";
	d3.setDate(2, 28, 1992);
	cout << "d3 = " << d3;
	cout << "\n++d3 = " << ++d3;
	cout << "\n++d3 = " << ++d3 << "\n\n";
	Date d4(3, 18, 1969);
	cout << "\nd4 = " << d4 << endl;
	cout << "++d4 = " << ++d4 << endl;
	cout << "d4 = " << d4 << endl;
	cout << "\nd4 = " << d4 << endl;
	cout << "d4++ = " << d4++ << endl;
	cout << "d4 = " << d4 << endl;
}