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

    int sales[4][5] = { 0 },
        sum, total = 0;

    srand(time(0));

    for (int day = 0; day < 30; day++)
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 5; j++)
                sales[i][j] += rand() % 100;

    cout << setw(14) << "trader/product";
    for (int i = 0; i < 5; i++)
        cout << setw(10) << "product " << i + 1;

    cout << setw(7) << "total" << endl << endl;

    for (int i = 0; i < 4; i++)
    {
        sum = 0;
        cout << setw(9) << "trader " << i + 1 << setw(1) << ' ';
        for (int j = 0; j < 5; j++)
        {
            cout << setw(11) << sales[i][j];
            sum += sales[i][j];
        }
        cout << setw(10) << sum << endl;
    }

    cout << endl << setw(8) << "total" << setw(3) << ' ';

    for (int j = 0; j < 5; j++)
    {
        sum = 0;
        for (int i = 0; i < 4; i++)
        {
            sum += sales[i][j];
        }
        cout << setw(11) << sum;
        total += sum;
    }

    cout << setw(11) << total;
        



    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}
