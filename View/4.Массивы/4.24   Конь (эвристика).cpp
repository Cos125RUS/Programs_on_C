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

int accessibility[board_size][board_size] = { 0 };

void horse(int[board_size][board_size], int, int, int);

int forecast(int[board_size][board_size], int, int, int);

int main()
{
    setlocale(LC_ALL, "Russian");


    int board[board_size][board_size] = { 0 },
        current_row = 3,
        current_column = 4,
        counter = 1;

    board[current_row][current_column] = counter;

    for (int i = 0; i < board_size; i++)
        for (int j = 0; j < board_size; j++)
            for (int number = 0; number < board_size; number++)
            {
                int row = i + vertical[number],
                    column = j + horizontal[number];

                if (row > -1 && row < board_size)
                    if (column > -1 && column < board_size)
                        if (board[i][j] == 0)
                            ++accessibility[row][column];
            }

    //cout << setw(15) << "Accessibility:" << endl;

   // for (int i = 0; i < board_size; i++)
    //{
        //for (int j = 0; j < board_size; j++)
            //cout << setw(2) << accessibility[i][j];
        //cout << endl;
    //}
    //cout << endl << endl;

    //horse(board, current_row, current_column, counter);

    for (counter; counter <= 64; counter++)
    {
        int min = 9,
            priority;

        for (int move_number = 0; move_number < board_size; move_number++)
        {
            int row = current_row + vertical[move_number],
            column = current_column + horizontal[move_number];

            if (row > -1 && row < board_size)
                if (column > -1 && column < board_size)
                    if (board[row][column] == 0)
                        if (min == accessibility[row][column])
                        {
                            if (forecast(board, row, column, priority) > forecast(board, row, column, move_number))
                                priority = move_number;
                        }
                        else
                            if (min > accessibility[row][column])
                            {
                            min = accessibility[row][column];
                            priority = move_number;
                            }
        }
        if (min < 9)
        {
            current_row += vertical[priority];
            current_column += horizontal[priority];
            board[current_row][current_column] = counter + 1;
        }
        //else
        //{
          //  int empty_fields = 64 - counter;
            //cout << endl << "Counter = " << counter << endl 
              //  << "Empty fields = " << empty_fields << endl << endl;
            //counter = 65;
        //}

        for (int number = 0; number < board_size; number++)
        {
            int row = current_row + vertical[number],
                column = current_column + horizontal[number];

            if (row > -1 && row < board_size)
                if (column > -1 && column < board_size)
                    --accessibility[row][column];
        }
    }

    cout << setw(23) << "The way of the horse:" << endl << endl;

    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
            cout << setw(3) << board[i][j];
        cout << endl;
    }
    cout << endl << endl;









    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

void horse(int board[board_size][board_size], int current_row, int current_column, int counter)
{
    int row, column;

    cout << "Counter = " << counter << endl;

    if (counter == 64)
    {
        for (int i = 0; i < board_size; i++)
        {
            for (int j = 0; j < board_size; j++)
                cout << setw(3) << board[i][j];
            cout << endl;
        }
        cout << endl << endl;
    }
    else
    {
        for (int move_number = 0; move_number < board_size; move_number++)
        {      
            row = current_row + vertical[move_number];
            column = current_column + horizontal[move_number];

            if (row > -1 && row < board_size)
            {
                if (column > -1 && column < board_size)
                {
                    if (board[row][column] == 0)
                    {
                        board[row][column] = counter + 1;
                        cout << "   move number - " << move_number << "\nhorse " << row << ":" << column << endl;
                        for (int i = 0; i < board_size; i++)
                        {
                            for (int j = 0; j < board_size; j++)
                                cout << setw(3) << board[i][j];
                            cout << endl;
                        }
                        cout << endl << endl;
                        horse(board, row, column, counter + 1);
                    }
                }
            }
        }
    }
}

int forecast(int board[board_size][board_size], int current_row, int current_column, int option)
{
    int min = 9,
        priority,
        copy_board[board_size][board_size] = { 0 };

    for (int i = 0; i < board_size; i++)
        for (int j = 0; j < board_size; j++)
            copy_board[i][j] = board[i][j];

    copy_board[current_row][current_column] = 1;
    current_row += vertical[option];
    current_column += horizontal[option];

    for (int move_number = 0; move_number < board_size; move_number++)
    {
        int row = current_row + vertical[move_number],
            column = current_column + horizontal[move_number];

        if (row > -1 && row < board_size)
            if (column > -1 && column < board_size)
                if (board[row][column] == 0)
                    if (min == accessibility[row][column])
                    {
                        if (forecast(copy_board, row, column, priority) > forecast(copy_board, row, column, move_number))
                            priority = move_number;
                    }
                    else
                        if (min > accessibility[row][column])
                        {
                            min = accessibility[row][column];
                            priority = move_number;
                        }
    }
        if (min < 9)
            return min;
        else
            return 9;
    
}
