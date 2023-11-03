#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    cout.setf(ios::showpoint);
    cout << 9.90000 << endl;
    cout << setw(10) << 10 << setw(10) << 10;
    cout.setf(ios::left, ios::adjustfield);
    cout << "\nbase\n";
    cout.unsetf(ios::left);
    cout << "\nbase\n";
    cout << setw(10) << setiosflags(ios::left) << 10 << endl << setw(10) << resetiosflags(ios::left) << 10 << endl;
    cout << setiosflags(ios::internal | ios::showpoint) << setw(10) << 123 << endl;








    cout << "\n\n\n\n\n\n\n\n\n\n";
}