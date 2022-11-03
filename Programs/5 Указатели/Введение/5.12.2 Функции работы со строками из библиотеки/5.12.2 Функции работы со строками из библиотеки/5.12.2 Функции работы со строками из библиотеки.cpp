#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include <string.h>
#include <string>
#include <errno.h>
#include <stdio.h>


using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	char x[] = "Happu Birthday to You";
	char y[25], z[15];

	strcpy_s(y, x);
	cout << "x: " << x << "\ny: " << y;


	strncpy_s(z, x, 14);
	z[14] = '\0';

	cout << "\nz: " << z << endl << endl;



	char s1[20] = "Happy ";
	char s2[] = "New Year";
	char s3[40] = "";
	char s4[40] = "";

	cout << "s1 = " << s1 << "\ns2 = " << s2;
	strcat_s(s1, s2);
	cout << "\nstrcat(s1,s2) = " << s1;
	strncat_s(s3, s1, 6);
	cout << "\nstrncat(s3,s1, 6) = " << s3;
	strcat_s(s4, s1);
	cout << "\nstrcat(s4,s1) = " << s4 << endl << endl;


	const char* z1 = "Happy New Year";
	const char* z2 = "Happy New Year";
	const char* z3 = "Happy Holidays";

	cout << "z1 = " << z1 << "\nz2 = " << z2 << "\nz3 = " << z3
		<< "\n\nstrcmp(z1, z2) = " << setw(2) << strcmp(z1, z2)
		<< "\n\nstrcmp(z1, z3) = " << setw(2) << strcmp(z1, z3)
		<< "\n\nstrcmp(z3, z1) = " << setw(2) << strcmp(z3, z1);

	cout << "\n\nstrncmp(z1, z3, 6) = " << setw(2) << strncmp(z1, z3, 6)
		<< "\n\nstrncmp(z1, z3, 7) = " << setw(2) << strncmp(z1, z3, 7)
		<< "\n\nstrncmp(z3, z1, 7) = " << setw(2) << strncmp(z3, z1, 7);


	char string[] = "This sentence contains five tokens";
	char* tokenPtr;
	char* next_token;

	cout << "\n\nThe string is divided into tokens:\n" << string << "\n\nTokens:\n";

	tokenPtr = strtok_s(string, " ", &next_token);

	while (tokenPtr != NULL)
	{
		cout << tokenPtr << '\t' << next_token << endl;
		tokenPtr = strtok_s(NULL, " ", &next_token);
	}

	const char* string1 = "dfgdfhghfghfghfghfghfghfghndfgjilioli";
	const char* string2 = "four";
	const char* string3 = "Boston";

	cout << "\n\n\nLength \"" << string1 << "\" = " << strlen(string1)
		<< "\n\n\nLength \"" << string2 << "\" = " << strlen(string2)
		<< "\n\n\nLength \"" << string3 << "\" = " << strlen(string3) << endl;



	cout << "\n\n\n\n\n\n\n\n\n\n";

	return 0;
}