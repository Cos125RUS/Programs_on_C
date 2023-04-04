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

void turtle_step(char[], int*);
void hare_step(char[], int*);
void move(char[], int*, int*);

int main()
{
    setlocale(LC_ALL, "Russian");

    srand(time(0));

    int turtle = 1, hare = 1;
    
    const int distance = 72;
    
    char track[distance];

    for (int i = 0; i < distance; i++)
        track[i] = ' ';

    track[1] = 'S';
    track[70] = 'F';

    while (turtle < 70 && hare < 70)
    {
        turtle_step(track, &turtle);
        hare_step(track, &hare);
        move(track, &turtle, &hare);
        cout << endl << endl;
    }

    if (turtle != hare)
    {
        if (turtle == 71)
            cout << "\n\n\t\t\t\tTurtle win!";
        else
            cout << "\n\n\t\t\t\tHare win=(";
    }
    else
        cout << "\n\n\t\t\t\tDraw...";






    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

void turtle_step(char track[], int *turtle)
{
    if (*turtle != 1) track[*turtle] = ' ';

    int step = 1 + rand() % 10;
    
    if (step < 6) *turtle += 3;
    if (step > 5 && step < 8) *turtle -= 6;
    if (step > 7) *turtle++;

    if (*turtle < 2) *turtle = 0;
    if (*turtle > 69) *turtle = 71;
}

void hare_step(char track[], int* hare)
{
    if (*hare != 1) track[*hare] = ' ';

    int step = 1 + rand() % 10;

    if (step > 2 && step < 5) *hare += 9;
    if (step > 4 && step < 6) *hare -= 12;
    if (step > 5 && step < 9) *hare++;
    if (step > 8) *hare -=2;

    if (*hare < 2) *hare = 0;
    if (*hare > 69) *hare = 71;
}

void move(char track[], int* turtle, int* hare)
{
    if (*turtle != *hare)
    {
        if (*turtle != 1 && *turtle != 70)
            track[*turtle] = 'T';

        if (*hare != 1 && *hare != 70)
            track[*hare] = 'H';
    }
    else
        if (*hare != 1 && *hare != 70)
            track[*hare] = 'X';

    for (int i = 0; i < 72; i++)
        cout << track[i];

    if (track[71] != ' ') cout << "!!!";
}