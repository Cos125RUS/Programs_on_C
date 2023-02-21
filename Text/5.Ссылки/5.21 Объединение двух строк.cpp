#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void mystery1(char*, const char*);

int main()
{
    setlocale(LC_ALL, "Russian");

    char string1[80], string2[80];

    cout << "Enter two strings: ";
    cin >> string1 >> string2;
    mystery1(string1, string2);
    cout << string1 << endl;








    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

void mystery1(char* s1, const char* s2)
{
    while (*s1 != '\0')
        ++s1;

    for (; *s1 = *s2; s1++, s2++);
}