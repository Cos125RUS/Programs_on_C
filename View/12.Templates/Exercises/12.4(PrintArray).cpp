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

template<class T>
void printArray(const T* array, const int count)
{
    for (int i = 0; i < count; i++)
        cout << array[i] << " ";
    cout << endl;
}

template<class T>
void printArray(const T* array, const int size, const int lowSubscript, const int highSubscript)
{
    if (highSubscript > lowSubscript && size >= highSubscript) {
		for (int i = lowSubscript; i < highSubscript; i++)
			cout << array[i] << " ";
		cout << endl << highSubscript - lowSubscript << " elements\n";
	}
}

int main()
{
    setlocale(LC_ALL, "Russian");

    const int aCount = 5, bCount = 7, cCount = 6;
    int a[aCount] = { 1,2,3,4,5 };
    double b[bCount] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7 };
    char c[cCount] = "HELLO";
    cout << "Массив а: ";
    printArray(a, aCount);
    cout << "Массив b: ";
    printArray(b, bCount);
    cout << "Массив c: ";
    printArray(c, cCount);

    cout << "\n\nМассив а: ";
    printArray(a, aCount, 2, 4);
    cout << "Массив b: ";
    printArray(b, bCount, 1, 5);
    cout << "Массив c: ";
    printArray(c, cCount, 0, 3);






    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}