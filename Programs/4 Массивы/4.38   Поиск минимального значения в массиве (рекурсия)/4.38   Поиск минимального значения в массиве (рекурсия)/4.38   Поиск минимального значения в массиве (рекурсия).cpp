#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


void fill_array(int[], int);

void print_array(int[], int);

int min_of_array(int[], int);

int main()
{
    setlocale(LC_ALL, "Russian");


    const int size = 100;

    int arr[size];
    fill_array(arr, size);
    print_array(arr, size);

    cout << endl << setw(20) << "Min of array = " << min_of_array(arr, size);








    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

void fill_array(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        array[i] = 1 + rand() % 99;
    }
}

void print_array(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i % 10 == 0 && i != 0)
            cout << endl;
        cout << setw(5) << array[i];
    }
    cout << endl << endl;
}

int min_of_array(int arr[], int size)
{
    if (size == 1)
        return arr[size - 1];
    else
    {
        if (arr[size - 1] < arr[0]) arr[0] = arr[size - 1];
        return min_of_array(arr, size - 1);
    }    
}