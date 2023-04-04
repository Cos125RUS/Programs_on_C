#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void creature(int[], int);

int binary_seach(int[], int, int, int, int);

void print(int[], int);

void sort(int[], int, int);

int main()
{
    setlocale(LC_ALL, "Russian");

    const int array_size = 100;

    int arr[array_size], key, result;

    creature(arr, array_size);
    print(arr, array_size);
    sort(arr, array_size, 0);
    cout << endl << endl;
    print(arr, array_size);    

    cout << "Enter seachh key: ";
    cin >> key;

    result = binary_seach(arr, array_size, key, 0, array_size - 1);

    if (result != -1)
        cout << "\nSeach key found in the " << result << " element of array.";
    else
        cout << "\nSeach key not found in array.";





    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

int binary_seach(int arr[], int size, int key, int low, int high)
{
    int middle;

    if (low <= high)
        middle = (low + high) / 2;
    else
        return -1;

    if (key == arr[middle])
        return middle;
    else
        if (key < arr[middle])
            return binary_seach(arr, size, key, low, middle-1);
        else
            return binary_seach(arr, size, key, middle+1, high);


}

void creature(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        array[i] = 1 + rand() % 99;
    }
}

void print(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i % 10 == 0 && i != 0)
            cout << endl;
        cout << setw(5) << array[i];
    }
    cout << endl << endl;
}

void sort(int array[], int n, int a)
{
    if (a != n - 1)
    {
        int min = array[a],
            index = a;

        for (int i = a + 1; i < n; i++)
            if (min > array[i])
            {
                min = array[i];
                index = i;
            }

        int change = array[a];
        array[a] = array[index];
        array[index] = change;

        return sort(array, n, a + 1);
    }
}