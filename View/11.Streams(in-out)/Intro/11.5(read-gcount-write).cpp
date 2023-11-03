#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    const int SIZE = 80;
    char buffer[SIZE];
    cout << cin.eof() << "\nВведите предложение:\n";
    cin.read(buffer, 20);
    cout << "\nВведённое предложение:\n";
    cout.write(buffer, cin.gcount());






    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}