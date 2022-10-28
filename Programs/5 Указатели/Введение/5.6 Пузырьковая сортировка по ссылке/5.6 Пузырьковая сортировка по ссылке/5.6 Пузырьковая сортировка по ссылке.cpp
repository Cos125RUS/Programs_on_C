#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void bubbleSort(int*, const int);

int main()
{
    setlocale(LC_ALL, "Russian");

    const int arraySize = 10;
    int a[arraySize] = { 2,6,4,8,10,12,89,68,45,37 };
    int i;

    cout << "Элементы данных в исходном порядке\n";

    for (i = 0; i < arraySize; i++)
        cout << setw(4) << a[i];

    bubbleSort(a, arraySize);
    cout << "\nЭлементы данных в возрастающем порядке\n";

    for (i = 0; i < arraySize; i++)
		cout << setw(4) << a[i];

          


    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

void bubbleSort(int* array, const int size)
{
    void swap(int* const, int* const);

    for (int pass = 0; pass < size -1; pass++)
        for (int j = pass; j < size - 1; j++)
            if (array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
}

void swap(int *const element1Ptr, int *const element2Ptr)
{
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}