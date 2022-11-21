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

int mystery2(const char*);

int main()
{
    setlocale(LC_ALL, "Russian");

    char string[80];

    cout << "Enter the string: ";
    cin >> string;
    cout << mystery2(string) << endl;






    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

int mystery2(const char* s)
{
    int x;

    for (x = 0; *s != '\0'; s++)
        ++x;

    return x;
}