#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Enter number: ";
    cin >> n;

    cout << n << " in hex: " << hex << n << endl
        << dec << n << " in oct: " << oct << n << endl
        << setbase(10) << n << " in dec: " << n << endl;







    cout << "\n\n\n\n\n\n\n\n\n\n";
}