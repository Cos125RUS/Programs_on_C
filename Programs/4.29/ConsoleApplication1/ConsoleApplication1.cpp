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

    const int n = 1000;
    int array[n] = { 0 };

    for (int i = 0; i < n; i++)
        array[i] = 1;

    for (int i = 2; i < n; i++)
        if (array[i] > 0)
            for (int j = i + 1; j < n; j++)
                if (j % i == 0)
                    array[j] = 0;

    for (int i = 1; i < n; i++)
        if (array[i] == 1)
            cout << i << endl;










    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

