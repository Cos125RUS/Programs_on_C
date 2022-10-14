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

    int numbers;
    cout << "number of employees = ";
    cin >> numbers;

    int employees[50] = { 0 },
        salary[50] = { 0 },
        ranks[9] = { 0 };

    cout << "\n\nEnter gross sales of employees:\n";
    for (int i = 0; i < numbers; i++)
    {
        cout << "Employees №" << i + 1 << ": ";
        cin >> employees[i];
    }

    cout << endl << endl;

    for (int i = 0; i < numbers; i++)
    {
        salary[i] = employees[i] * 0.09 + 200;
        cout << "\nEmployees №" << i + 1 << " salary = " << salary[i];
        salary[i] /= 100;
        if (salary[i] > 10)
            salary[i] = 10;
        ++ranks[salary[i] - 2];
    }
    
    cout << endl << endl;

    for (int i = 0; i < 8; i++)
    {
        cout << endl << i + 1 << ". $" << (i + 2) * 100 << "-$" << (i + 3) * 100 - 1 << " - " << ranks[i] << " peaples";
    }
    cout << endl << "9. $1000 and more - " << ranks[8] << " peaples";




    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}