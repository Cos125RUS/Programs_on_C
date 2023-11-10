#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int x;
    cout << cin.rdstate() << endl << cin.eof() << endl << cin.fail() << endl << cin.bad() << endl << cin.good() << endl << endl;
    cin >> x;
    cout << cin.rdstate() << endl << cin.eof() << endl << cin.fail() << endl << cin.bad() << endl << cin.good() << endl << endl;
    cin.clear();
    cout << cin.fail() << endl << cin.good() << endl << endl;







    cout << "\n\n\n\n\n\n\n\n\n\n";
}