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

void convertPhone(char[], int*, long*);

int main()
{
    setlocale(LC_ALL, "Russian");

    char text[200];
    int region = 0;
    long person = 0;

	cout << "Enter phone number:   ";
    cin.getline(text, 200, '\n');
    convertPhone(text, &region, &person);

	cout << "\n\nregion - " << region << endl ;
	cout << "person - " << person << endl ;










    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

void convertPhone(char text[], int* region, long* person)
{
    char* token;
    char* txt; 

    int convertToNumb(char*);

    strtok_s(text, ")", &txt);

	token = &text[1];
	*region = convertToNumb(token);

	strtok_s(txt, "-", &token);
	*person = convertToNumb(txt);
	*person *= 10000;
	*person += convertToNumb(token);
}

int convertToNumb(char* text)
{
    int length = strlen(text),
		result = 0;

	for (int i = 0, j = pow (10, length - 1); i < length; i++, j /= 10)
	{
		int x = *(text + i);

		switch (x)
		{
		case 48:
			x = 0;
			break;

		case 49:
			x = 1;
			break;

		case 50:
			x = 2;
			break;

		case 51:
			x = 3;
			break;

		case 52:
			x = 4;
			break;

		case 53:
			x = 5;
			break;

		case 54:
			x = 6;
			break;

		case 55:
			x = 7;
			break;

		case 56:
			x = 8;
			break;

		case 57:
			x = 9;
			break;

		default:
			cout << "Error!";
			break;
		}
		result += (x * j);
	}

	return result;
}
