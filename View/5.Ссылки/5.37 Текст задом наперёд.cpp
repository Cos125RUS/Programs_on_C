#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include <string.h>
#include <errno.h>

using namespace std;

int separation(char text[200], char words[10][20]);

int main()
{
    setlocale(LC_ALL, "Russian");

    char text[200];
    char words[10][20];

    cin.getline(text, 200, '\n');

    int size = separation(text, words);

    for (int i = size - 1; i >= 0; i--)
    {
        cout << words[i] << ' ';
    }


    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

int separation(char text[200], char words[10][20])
{
    char* txt;
    char* token;
    int i = 0;

    token = strtok_s(text, " ", &txt);

    while (token != NULL)
    {
        strcpy_s(words[i], token);
        i++;
        token = strtok_s(NULL, " ", &txt);
    }

    return i;
}