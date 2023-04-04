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

int comparison1(const char* s1, const char* s2)
{
    int i = 0, j = 0;

    for (i; s1[i] != '\0'; i++);
    for (j; s2[j] != '\0'; j++);
    
    if (i == j) return 0;
    else
        if (i > j) return 1;
        else return -1;
};

int comparison2(const char* s1, const char* s2)
{
    while (*s1++ != '\0' || *s2++ != '\0');
    if (*s1 == '\0' && *s2 == '\0') return 0;
    else if (*s1 == '\0') return -1;
    else return 1;
};

int main()
{
    setlocale(LC_ALL, "Russian");

    const char string1[] = "translate_google ";
    const char string2[] = "translate.yandex.ru ";

    cout << comparison1(string1, string2) << endl;
    cout << comparison2(string1, string2);




    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}