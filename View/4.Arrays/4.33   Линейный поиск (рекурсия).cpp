#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void creature(int[], int);

int linear_seach(int[], int, int);

int main()
{
    setlocale(LC_ALL, "Russian");

    const int array_size = 100;

    int arr[array_size], seach_key, element;

    creature(arr, array_size);

    cout << "Enter seachh key: ";
    cin >> seach_key;

    element = linear_seach(arr, array_size, seach_key);

    if (element != -1)
        cout << "\nSeach key found in the " << element << " element of array.";
    else
        cout << "\nSeach key not found in array.";





    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

int linear_seach(int arr[], int size, int key)
{
    if (size == 0) return -1;
    else
    {
        if (arr[size - 1] == key) return size - 1;
        else return linear_seach(arr, size - 1, key);
    }
}

void creature(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        array[i] = 1 + rand() % 99;
    }
}