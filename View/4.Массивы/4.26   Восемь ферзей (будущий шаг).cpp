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

void print(int[board_size][board_size]);
void eureka();
void hueurika(int[board_size][board_size], int, int);
int forecast(int[board_size][board_size], int[board_size][board_size], int, int, int);

int main()
{
    setlocale(LC_ALL, "Russian");


    cout << setw(18) << "Heuristics:" << endl << endl;

    eureka();
    print(heuristics); 
     

    for (int queen = 1; queen < 9; queen++)
    {
        int min = 99,
            x, y, future_step;

        for (int i = 0; i < board_size; i++)
            for (int j = 0; j < board_size; j++)
                if (board[i][j] == 0)
                    if (min > heuristics[i][j])
                    {
                        min = heuristics[i][j];
                        x = i;
                        y = j;
                        future_step = forecast(board, heuristics, x, y, queen);
                    }
                    else
                        if (min == heuristics[i][j])
                            if (future_step != 9)
                                if (future_step < forecast(board, heuristics, i, j, queen))
                                {
                                    min = heuristics[i][j];
                                        x = i;
                                        y = j;
                                        future_step = forecast(board, heuristics, x, y, queen);
                                }                            

        if (min > 30)
        {
            cout << setw(3) << queen - 1 << " queens on the board\n\n";
            queen = 9;
        }
        else
        {
            board[x][y] = queen;

            //cout << endl << endl << "x - " << x << "    y - " << y << endl << endl;

            hueurika(heuristics, x, y);
        }
    }
    
            
    print(board);

    









    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

void print(int chess_board[board_size][board_size])
{
    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
            cout << setw(3) << chess_board[i][j];
        cout << endl;
    }
    cout << endl << endl;
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

void hueurika(int heuristics[board_size][board_size], int i, int j)
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
    
    //cout << endl << endl;
    
    //for (int i = 0; i < board_size; i++)
    //{
      //  for (int j = 0; j < board_size; j++)
        //    cout << setw(3) << heuristics[i][j];
        //cout << endl;
    //}

    //cout << endl << endl;
}

int forecast(int board[board_size][board_size], int heuristics[board_size][board_size], int x, int y, int queen)
{
    int copy_board[board_size][board_size] = { 0 },
        copy_heuristics[board_size][board_size] = { 0 };

    for (int i = 0; i < board_size; i++)
        for (int j = 0; j < board_size; j++)
        {
            copy_board[i][j] = board[i][j];
            copy_heuristics[i][j] = heuristics[i][j];
        }

    copy_board[x][y] = queen;
    queen++;
    hueurika(copy_heuristics, x, y);    

    while (queen < 9)
    {
        int min = 99,
            a, b, future;

        for (int i = 0; i < board_size; i++)
            for (int j = 0; j < board_size; j++)
                if (copy_board[i][j] == 0)
                    if (min > copy_heuristics[i][j])
                    {
                        min = copy_heuristics[i][j];
                        a = i;
                        b = j;
                        future = forecast(copy_board, copy_heuristics, a, b, queen);
                    }
                    else
                        if (min == copy_heuristics[i][j])
                            if (future != 9)
                            if (future < forecast(copy_board, copy_heuristics, i, j, queen))
                            {
                                min = copy_heuristics[i][j];
                                a = i;
                                b = j;
                                future = forecast(copy_board, copy_heuristics, a, b, queen);                                
                            }
        if (min > 30)
        {
            return queen;
        }
        else
        {
            copy_board[a][b] = queen;
            queen++;
            hueurika(copy_heuristics, a, b);
        }        
    }
    

    return queen;
}