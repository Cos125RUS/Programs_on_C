#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int board_size = 8;
int board[board_size][board_size] = { 0 },
heuristics[board_size][board_size] = { 0 };

void eureka();
void hueurika(int, int);

int main()
{
    setlocale(LC_ALL, "Russian");


    cout << setw(18) << "Heuristics:" << endl << endl;

    eureka();

    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
            cout << setw(3) << heuristics[i][j];
        cout << endl;
    }
     
    cout << endl << endl;


    for (int queen = 1; queen < 9; queen++)
    {
        int min = 99,
            x, y;

        for (int i = 0; i < board_size; i++)
            for (int j = 0; j < board_size; j++)
                if (board[i][j] == 0)
                    if (min > heuristics[i][j])
                    {
                        min = heuristics[i][j];
                        x = i;
                        y = j;
                    }

        if (min > 30)
        {
            cout << queen - 1 << " queens on the board\n\n";
            queen = 9;
        }
        else
        {
            board[x][y] = queen;

            cout << endl << endl << "x - " << x << "    y - " << y << endl << endl;

            hueurika(x, y);
        }
    }
    
            
    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
            cout << board[i][j] << ' ';
        cout << endl;
    }
    









    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

void eureka()
{
    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
        {
            ++heuristics[i][j];

            for (int n = 1; n < board_size; n++)
            {
                if ((i - n) > -1)
                {
                    ++heuristics[i][j];
                    if ((j - n) > -1)
                        ++heuristics[i][j];
                    if ((j + n) < board_size)
                        ++heuristics[i][j];
                }
                if ((i + n) < board_size)
                {
                    ++heuristics[i][j];
                    if ((j - n) > -1)
                        ++heuristics[i][j];
                    if ((j + n) < board_size)
                        ++heuristics[i][j];
                }
                if ((j - n) > -1)
                    ++heuristics[i][j];
                if ((j + n) < board_size)
                    ++heuristics[i][j];
            }
        }
    }

}

void hueurika(int i, int j)
{
    heuristics[i][j] = 99;

    for (int n = 1; n < board_size; n++)
    {
        if ((i - n) > -1)
        {
            heuristics[i - n][j] = 98;
            if ((j - n) > -1)
                heuristics[i - n][j - n] = 98;
            if ((j + n) < board_size)
                heuristics[i - n][j + n] = 98;
        }
        if ((i + n) < board_size)
        {
            heuristics[i + n][j] = 98;
            if ((j - n) > -1)
                heuristics[i + n][j - n] = 98;
            if ((j + n) < board_size)
                heuristics[i + n][j + n] = 98;
        }
        if ((j - n) > -1)
            heuristics[i][j - n] = 98;
        if ((j + n) < board_size)
            heuristics[i][j + n] = 98;
    }
    
    cout << endl << endl;
    
    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
            cout << setw(3) << heuristics[i][j];
        cout << endl;
    }

    cout << endl << endl;
}