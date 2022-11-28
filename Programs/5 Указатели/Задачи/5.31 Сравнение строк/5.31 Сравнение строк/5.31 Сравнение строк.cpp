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

int comparison(const char* s1, const char* s2);

int main()
{
    setlocale(LC_ALL, "Russian");

    char string1[80], string2[80];

    cout << "string1: ";
    cin >> string1;
    cout << "string2: ";
    cin >> string2;

    if (strcmp(string1, string2) == 1)
		cout << "string1 > string2";
    else 
        if (strcmp(string1, string2) == -1)
            cout << "string1 < string2";
        else
            cout << "string1 = string2";

    cout << "\n\Characters checked - " << comparison(string1, string2);







    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

int comparison(const char* s1, const char* s2)
{
    int i = 0;
    while (*s1++ != '\0' && *s2++ != '\0') i++;
    return i;
}