#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


const int n = 100;

void creature(int[n]);

void print(int[n]);

void sort(int[n], int);

int main()
{
    setlocale(LC_ALL, "Russian");

    srand(time(0));


    int array[n] = { 0 };


    creature(array);
    print(array);
    sort(array, 0);
    print(array);



    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

void creature(int array[n])
{
    for (int i = 0; i < n; i++)
    {
        array[i] = 1 + rand() % 999;
    }
}

void print(int array[n])
{
    for (int i = 0; i < n; i++)
    {
        if (i % 10 == 0 && i != 0)
            cout << endl;
        cout << setw(5) << array[i];
    }
    cout << endl << endl;
}

void sort(int array[n], int a)
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

        return sort(array, a + 1);
    }
}