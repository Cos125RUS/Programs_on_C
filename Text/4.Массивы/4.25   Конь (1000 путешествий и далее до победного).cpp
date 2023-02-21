#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int board_size = 8,
horizontal[board_size] = { 2,1,-1,-2,-2,-1,1,2 },
vertical[board_size] = { -1,-2,-2,-1,1,2,2,1 };

int main()
{
    setlocale(LC_ALL, "Russian");


    const int board_size = 8,
        horizontal[board_size] = { 2,1,-1,-2,-2,-1,1,2 },
        vertical[board_size] = { -1,-2,-2,-1,1,2,2,1 };

    int board[board_size][board_size] = { 0 },
        variants[board_size] = { 0 },
        //results[1001] = { 0 },
        current_row = 0,
        current_column = 0,
        counter = 1,
        //max = 0,
        n = 0,
        finish = 0,
        step, row, column, motions;

    board[current_row][current_column] = counter;

    srand(time(0));
    
    while (finish != 64)
    {
        while (counter <= 64)
        {
            motions = 0;

            for (int move_number = 0; move_number < board_size; move_number++)
            {
                row = current_row + vertical[move_number];
                column = current_column + horizontal[move_number];

                if (row > -1 && row < board_size)
                    if (column > -1 && column < board_size)
                        if (board[row][column] == 0)
                        {
                            variants[motions] = move_number;
                            motions++;
                        }
            }

            if (motions == 0)
            {
                finish = counter;
                //results[n] = counter;
                //if (results[n] > max)
                    //max = results[n];
                counter = 65;
                n++;
            }
            else
            {
                step = rand() % motions;
                current_row += vertical[variants[step]];
                current_column += horizontal[variants[step]];
                counter++;
                board[current_row][current_column] = counter;
            }
        }

        current_row = rand()% board_size;
        current_column = rand() % board_size;
        counter = 1;

        for (int i = 0; i < board_size; i++)
            for (int j = 0; j < board_size; j++)
                board[i][j] = 0;

        board[current_row][current_column] = counter;

        cout << n << ' ';
    }
    
    cout << "\n\nNumber of cycles = " << n + 1;


    //cout << "max = " << max << endl << endl;
    
    //for (int i = 1; i <= 1000; i++)
    //{
       // cout << setw(3) << results[i];
      //  if (i % 20 == 0)
       //     cout << endl;
    //}

    //cout << endl << setw(23) << "The way of the horse:" << endl << endl;

    //for (int i = 0; i < board_size; i++)
    //{
      //  for (int j = 0; j < board_size; j++)
        //    cout << setw(3) << board[i][j];
        //cout << endl;
    //}
    //cout << endl << endl;









    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}