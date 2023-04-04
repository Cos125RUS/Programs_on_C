#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;



void creature(int[], int);

void print(int[], int);

int main()
{
    setlocale(LC_ALL, "Russian");

    srand(time(0));

    const int size = 10;

    int array[size] = { 0 };


    creature(array, size);
    print(array, size);



    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

void creature(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        array[i] = 1 + rand() % 999;
    }
}

void print(int arr[], int size)
{
    if (size > 0)
    {
        cout << arr[size - 1] << ' ';
        print(arr, size - 1);
    }
}