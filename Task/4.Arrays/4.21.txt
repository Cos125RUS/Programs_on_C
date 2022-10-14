#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void someFunction(int[], int);

int main()
{
    setlocale(LC_ALL, "Russian");

    const int arraySize = 10;
    int a[arraySize] = { 32, 27 , 64, 18, 95, 14, 90, 70, 60, 37 }, i;

    cout << "Nombers: " << endl;
    someFunction(a, arraySize);
    cin >> i;



    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}
void someFunction(int b[], int size)
{
    if (size > 0)
    {
        someFunction(&b[1], size - 1);
        cout << b[0] << " ";
    }
}