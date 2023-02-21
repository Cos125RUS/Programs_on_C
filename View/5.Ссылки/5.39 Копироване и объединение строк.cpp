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

void copy1(char* s1, const char* s2) { for (int i = 0; (s1[i] = s2[i]) != '\0'; i++); };
void copy2(char* s1, const char* s2) { while ((*s1++ = *s2++) != '\0'); };
void unification1(char* s1, const char* s2)
{
    int i = 0;
    for (i; s1[i] != '\0'; i++);
    for (int j = 0; (s1[i + j] = s2[j]) != '\0'; j++);
};
void unification2(char* s1, const char* s2)
{
    for (; *s1 != '\0'; s1++);
    for (; (*s1 = *s2) != '\0'; s1++, s2++);
};

int main()
{
    setlocale(LC_ALL, "Russian");

    char string1[] = "reverso ";
    const char string2[] = "translate_google ";
    const char string3[] = "translate.yandex.ru ";

    cout << string1 << endl;
    copy1(string1, string2);
    cout << string1 << endl;
    copy2(string1, string3);
    cout << string1 << endl;
    unification1(string1, string2);
    cout << string1 << endl;
    unification2(string1, string3);
    cout << string1 << endl;




    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}