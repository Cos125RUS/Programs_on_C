#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


const int line = 10, n = 100;

int block[line][n] = { 0 };

void creature(int[n], int);

void bucket_sort(int[n]);

void assembling(int[n]);

void print(int[n]);

void zero();

int main()
{
    setlocale(LC_ALL, "Russian");

    srand(time(0));

    
    int array[n] = { 0 };


    creature(array, n);
    bucket_sort(array);
    // print(array);
    








    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

void creature(int array[n], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = 1 + rand() % 999;        
    }

    print(array);
}

void bucket_sort(int array[n])
{
    int index;

    for (int i = 0; i < n; i++)
    {
        index = array[i] % 10;
        block[index][i] = array[i];
    }

    assembling(array);
    print(array);
    zero();
                
    for (int i = 0; i < n; i++)
    {        
        index = (array[i] / 10) % 10;
        block[index][i] = array[i];
    }
    
    assembling(array);
    print(array);
    zero();

    for (int i = 0; i < n; i++)
    {
        index = (array[i] / 100) % 10;
        block[index][i] = array[i];
    }
    
    assembling(array);
    print(array);
}

void assembling(int array[n])
{
    int k = 0;
    for (int i = 0; i < line; i++)
        for (int j = 0; j < n; j++)
            if (block[i][j] > 0)
            {
                array[k] = block[i][j];
                k++;
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

void zero()
{
    for (int i = 0; i < line; i++)
        for (int j = 0; j < n; j++)
            block[i][j] = 0;
}