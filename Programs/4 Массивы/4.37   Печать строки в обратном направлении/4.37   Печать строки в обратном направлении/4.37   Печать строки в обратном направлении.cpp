#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void string_revers(char[], int);

int string_length(char[], int);

int main()
{
    setlocale(LC_ALL, "Russian");


    const int length = 20;

    char string[length];

    cout << "Enter the text: ";
    cin >> string;
    cout << endl;

    int high = string_length(string, length);

    string_revers(string, high);






    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

void string_revers(char text[], int high)
{
    if (high >= 0)
    {
        cout << text[high];
        string_revers(text, high - 1);
    }

}

int string_length(char text[], int length)
{
    int count = 0;

    for (int i = 0; i < length; i++)
        if (text[i] != 0)
            count++;
        else 
            return count;
}