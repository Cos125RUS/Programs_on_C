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

template<typename T>
void bubbleSort(T* array, const int size)
{
    T temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

template<typename T>
void print(T* array, const int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << ' ';
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int intArray[] = { 2,5,3,4,9,1,7,6,8 };
    float floatArray[] = { 2.2,5.5,3.3,4.4,9.9,1.1,7.7,6.6,8.8 };
    bubbleSort(intArray, 9);
    bubbleSort(floatArray, 9);
    print(intArray, 9);
    print(floatArray, 9);







    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}