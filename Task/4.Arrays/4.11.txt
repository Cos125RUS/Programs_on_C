#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    const int array_size = 100;
    int a[array_size],
        i, hold = 0;

    srand(time(0));

    for (i = 0; i < array_size; i++)
    {
        a[i] = rand() % 100;
        cout << setw(7) << a[i];
        if ((i+1) % 10 == 0)
            cout << endl;
    }
    cout << endl << endl;

    for (int pass = 0; pass < array_size - 1; pass++)
    {
        while (hold != -1)
        {
            hold = -1;

            for (i = 0; i < array_size - 1 - pass; i++)
                if (a[i] > a[i + 1])
                {
                    hold = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = hold;
                }
        }
        
    }
        

    for (i = 0; i < array_size; i++)
    {
        cout << setw(7) << a[i];
        if ((i+1) % 10 == 0)
            cout << endl;
    }



    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}