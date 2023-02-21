#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int board_size = 8,
		  options = 92;

int archive[options][board_size][board_size] = { 0 };

int placement(int);

void print(int[board_size][board_size]);

void clear(int[board_size][board_size]);

void memory(int[board_size][board_size], int[board_size][board_size]);

bool comparison(int[board_size][board_size]);

void add_to_archive(int[board_size][board_size], int);

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(0));

	int option = 0;

	while (option < options)
	{
		option += placement(option);
	}

	//cout << endl << "archiv(83): " << endl;
	//print(archive[82]);

	











	cout << "\n\n\n\n\n\n\n\n\n\n";

	return 0;
}

int placement(int option)
{
	int board[board_size][board_size] = { 0 },
		copy_board[board_size][board_size] = { 0 },
		count = 0;


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
				memory(board, copy_board);

				if (comparison(copy_board) == true)
				{
					cout << "N" << option + 1 << endl;
					print(copy_board);					
					cout << endl;		
					add_to_archive(copy_board, option);
				}
				else
				{
					count = 0;
					queen = 0;
					clear(board);
					clear(copy_board);
				}
			}
			else
			{
				count = 0;
				queen = 0;
				clear(board);
			}
		}
	}
	return 1;
}

void print(int chess_board[board_size][board_size])
{
	for (int i = 0; i < board_size; i++)
	{
		for (int j = 0; j < board_size; j++)
			cout << setw(2) << chess_board[i][j];
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

void memory(int chess_board[board_size][board_size], int print_board[board_size][board_size])
{
	for (int n = 1; n < 9; n++)
		for (int i = 0; i < board_size; i++)
			for (int j = 0; j < board_size; j++)
				if (chess_board[i][j] == n)
					print_board[i][j] = n;
}

bool comparison(int chess_board[board_size][board_size])
{
	bool flag = true;
	int count,
		index;

	for (index = 0; index < options; index++)
	{
		count = 0;

		for (int n = 1; n < 9; n++)
			for (int i = 0; i < board_size; i++)
				for (int j = 0; j < board_size; j++)
					if (chess_board[i][j] > 0 && archive[index][i][j] > 0)
						count++;

		if (count == 8)
		{			
			flag = false;
			index = options+10;
		}			
	}
	return flag;
}

void add_to_archive(int copy_board[board_size][board_size], int option)
{
	for (int n = 1; n < 9; n++)
		for (int i = 0; i < board_size; i++)
			for (int j = 0; j < board_size; j++)
				if (copy_board[i][j] == n)
					archive[option][i][j] = n;
}