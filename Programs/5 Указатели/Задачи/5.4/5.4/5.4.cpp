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

	double number1 = 7.3,
		number2;

	char* ptr;
	char s1[100], s2[100] = "dfg,dfdf,gdfg,dfgdf,gsadfg,dsfg";

	double* fPtr;
	fPtr = &number1;
	cout << *fPtr << endl;

	number2 = *fPtr;
	cout << number2 << endl << endl;


	cout << &number1 << endl;
	cout << fPtr << endl;

	cout << endl << endl;

	cout << s2 << endl;

	strcpy_s(s1,  s2);
	cout << s1 << endl << endl;

	cout << strcmp(s1, s2) << endl << endl;

	strncpy_s(s1, s2, 10);
	cout << s1 << endl << endl;

	cout << strlen(s1) << endl << endl;

	strtok_s(s2, ",", &ptr);
	cout << s2 << endl << endl << ptr;



	cout << "\n\n\n\n\n\n\n\n\n\n";

	return 0;
}