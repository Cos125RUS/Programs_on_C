#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

void convertToUppercase(char*);

void printCharacters(const char*);

int main()
{
    setlocale(LC_ALL, "Russian");

    char string1[] = "characters and $32.98";

    cout << "Строка до преобразования:   " << string1;
    convertToUppercase(string1);
    cout << "\nСтрока после преобразования:  " << string1 << endl;

         
    char string2[] = "Печатль символьнос строки";

    cout << "Строка:\n";
    printCharacters(string2);
    cout << endl;


    int x, y;

    int* const ptr = &x;

    *ptr = 7;
    // ptr = &y;

    cout << "ptr = " << ptr << "\n*ptr = " << *ptr << "\nx = " << x;


    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

void convertToUppercase(char *sPtr)
{
    while (*sPtr != '\0')
    {
        if (islower(*sPtr)) *sPtr = toupper(*sPtr);
        ++sPtr;
    }
}

void printCharacters(const char *sPtr)
{
    for (; *sPtr != '\0'; sPtr++)
        cout << *sPtr;
}
