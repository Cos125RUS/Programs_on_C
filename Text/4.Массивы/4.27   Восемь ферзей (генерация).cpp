#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int board_size = 8;

void print(int[board_size][board_size]);

void clear(int[board_size][board_size]);

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(0));

	int board[board_size][board_size] = { 0 },
		count = 0,
		fail = 0;


	for (int queen = 1; queen < 9; queen++)
	{
		int i, j;

		do {
			i = rand() % 8;
			j = rand() % 8;
		} while (board[i][j] != 0);

		board[i][j] = queen;
		count++;

		for (int n = 1; n < board_size; n++)
		{
			if ((i - n) > -1)
			{
				if (board[i - n][j] == 0)
				{
					count++;
					board[i - n][j] = 9;
				}				
				if ((j - n) > -1)
				{
					if (board[i - n][j - n] == 0)
					{
						board[i - n][j - n] = 9;
						count++;
					}
				}					
				if ((j + n) < board_size)
				{
					if (board[i - n][j + n] == 0)
					{
						board[i - n][j + n] = 9;
						count++;
					}
				}					
			}
			if ((i + n) < board_size)
			{
				if (board[i + n][j] == 0)
				{
					board[i + n][j] = 9;
					count++;
				}
				if ((j - n) > -1)
				{
					if (board[i + n][j - n] == 0)
					{
						board[i + n][j - n] = 9;
						count++;
					}					
				}					
				if ((j + n) < board_size)
				{
					if (board[i + n][j + n] == 0)
					{
						board[i + n][j + n] = 9;
						count++;
					}					
				}					
			}
			if ((j - n) > -1)
			{
				if (board[i][j - n] == 0)
				{
					board[i][j - n] = 9;
					count++;
				}				
			}		
			if ((j + n) < board_size)
			{
				if (board[i][j + n] == 0)
				{
					board[i][j + n] = 9;
					count++;
				}				
			}					
		}

		if (count == 64)
		{
			if (queen == 8)
			{				
				cout << "Failed attempts - " << fail << endl << endl;
				print(board);
			}
			else
			{
				count = 0;
				queen = 0;
				fail++;				
				clear(board);
				//cout << fail << "   ";
				//cout << endl << endl;
			}
		}		
	}

	











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

void clear(int chess_board[board_size][board_size])
{
	for (int i = 0; i < board_size; i++)
		for (int j = 0; j < board_size; j++)
			chess_board[i][j] = 0;
}