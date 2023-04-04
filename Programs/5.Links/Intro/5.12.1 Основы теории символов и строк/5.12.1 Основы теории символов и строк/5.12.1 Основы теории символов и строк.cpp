#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    char word[20];

    cin >> setw(10) >> word;

    cout << word;

    cin.getline(word, 5, '\t');

    cout << word;
    


    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}