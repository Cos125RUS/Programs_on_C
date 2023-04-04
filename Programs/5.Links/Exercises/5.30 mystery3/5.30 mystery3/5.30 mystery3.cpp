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

bool mystery3(const char*, const char*);

int main()
{
    setlocale(LC_ALL, "Russian");

    char string1[80], string2[80];

    cout << "Enter two strings: ";
    cin >> string1 >> string2;
    cout << "\n\nResult: " << mystery3(string1, string2);




    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

bool mystery3(const char*s1, const char*s2)
{
    for (; *s1 != '\0' && *s2 != '\0'; *s1++, *s2++)

        if (*s1 != *s2)
            return false;

    return true;
}