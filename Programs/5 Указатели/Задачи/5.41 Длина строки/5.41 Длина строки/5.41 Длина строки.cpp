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

int stringLength1(const char* s) 
{ 
    int i = 0;
    for (i; s[i] != '\0'; i++);
    return i; 
};

int stringLength2(const char* s)
{
    int i = 0;
    while (*(s+i) != '\0') i++;
    return i;
};

int main()
{
    setlocale(LC_ALL, "Russian");

    const char string1[] = "translate_google ";
    const char string2[] = "translate.yandex.ru ";

    cout << stringLength1(string1) << endl;
    cout << stringLength2(string2) << endl;



    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}