#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include <cassert>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <cstring>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    char buffer[100];
    int size = 0;
    char c;
    while ((c = cin.get()) != '\n' && size < 100) {
        buffer[size++] = c;
    }

    cout.setf(ios::adjustfield);
    cout.fill('*');
    cout.width(size * 2);
    cout << setw(size / 2) << "";
    cout.write(buffer, size);
    cout << setw(size / 2) << "";








    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}