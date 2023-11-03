#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    double root2 = sqrt(2.0);

    cout << setiosflags(ios::fixed) << "precision:\n";
    for (int i = 0; i <= 9; i++) {
        cout.precision(i);
        cout << root2 << endl;
    }
    cout << "\n\nsetprecision:\n";
    for (int i = 0; i <= 9; i++) {
        cout << setprecision(i) << root2 << endl;
    }






    cout << "\n\n\n\n\n\n\n\n\n\n";
}