#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


const int line = 10, n = 100;

int block[line][n] = { 0 };

void creature(int[], int);

void bucket_sort(int[n]);

int main()
{
    setlocale(LC_ALL, "Russian");

    srand(time(0));

    
    int array[n] = { 0 };


    creature(array, n);
    bucket_sort(array);

    for (int i = 0; i < n; i++)
    {
        if (i % 10 == 0 && i != 0)
            cout << endl;
        cout << setw(5) << array[i];
    }








    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

void creature(int array[n], int size)
{
    for (int i = 0; i < size; i++)
        array[i] = 1 + rand() % 1000;
}

void bucket_sort(int array[n])
{
    int index;

    for (int i = n; i < n; i++)
    {
        index = array[i] % 10;
        block[index][i] = array[i];
    }

    for (int k = 0; k < n; k++)
        for (int j = 0; j < line; j++)
            for (int i = 0; i < n; i++)
                if (block[j][i] > 0)
                    array[k] = block[j][k];

    for (int i = n; i < n; i++)
    {        
        index = array[i] / 10 % 10;
        block[index][i] = array[i];
    }

    for (int k = 0; k < n; k++)
        for (int j = 0; j < line; j++)
            for (int i = 0; i < n; i++)
                if (block[j][i] > 0)
                    array[k] = block[j][k];

    for (int i = n; i < n; i++)
    {
        index = array[i] / 100 % 10;
        block[index][i] = array[i];
    }

    for (int k = 0; k < n; k++)
        for (int j = 0; j < line; j++)
            for (int i = 0; i < n; i++)
                if (block[j][i] > 0)
                    array[k] = block[j][k];
}
