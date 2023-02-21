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

void print_array(char[][12]);
void mazeTravers(char[][12], int, int, char);
void mazeGenerator(char[][12], int, int);

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(0));

	char maze[12][12];
	int x = 1 + rand() % 10;
	int y = 0;

	mazeGenerator(maze, x, y);
	print_array(maze);



	cout << "\n\n\n\n\n\n\n\n\n\n";

	return 0;
}

void print_array(char maze[][12])
{
	cout << endl << endl;

	for (int i = 0; i < 12; i++)
	{
		cout << setw(5) << ' ';
		for (int j = 0; j < 12; j++)
			cout << maze[i][j];
		cout << endl;
	}
	cout << endl << endl;
}

void mazeTravers(char maze[][12], int x, int y, char direction)
{
	if (maze[x][y] != '#')
	{
		maze[x][y] = 'X';
		print_array(maze);

		if (x == 4 && y == 11)
		{
			cout << endl << endl << "Finish!";
			int k;
			cin >> k;
		}
		else
		{
			switch (direction)
			{
			case 'r':
				mazeTravers(maze, x + 1, y, 'd');
				mazeTravers(maze, x, y + 1, 'r');
				mazeTravers(maze, x - 1, y, 'u');
				mazeTravers(maze, x, y - 1, 'l');
				break;

			case 'u':
				mazeTravers(maze, x, y + 1, 'r');
				mazeTravers(maze, x - 1, y, 'u');
				mazeTravers(maze, x, y - 1, 'l');
				mazeTravers(maze, x + 1, y, 'd');
				break;

			case 'd':
				mazeTravers(maze, x, y - 1, 'l');
				mazeTravers(maze, x + 1, y, 'd');
				mazeTravers(maze, x, y + 1, 'r');
				mazeTravers(maze, x - 1, y, 'u');
				break;

			case 'l':
				mazeTravers(maze, x - 1, y, 'u');
				mazeTravers(maze, x, y - 1, 'l');
				mazeTravers(maze, x + 1, y, 'd');
				mazeTravers(maze, x, y + 1, 'r');
				break;
			}
		}
	}
}

void mazeGenerator(char maze[][12], int x, int y)
{
	for (int i = 0; i < 12; i++)
	{
		maze[0][i] = '#';
		maze[11][i] = '#';
		maze[i][0] = '#';
		maze[i][11] = '#';
	}

	for (int i = 1; i < 11; i++)
		for (int j = 1; j < 11; j++)
			maze[i][j] = ' ';

	maze[x][y] = '.';
	y++;
	maze[x][y] = '.';
	maze[1 + rand() % 10][11] = '.';

	void way(char[][12], int, int);
	void fillMaze(char[][12], int, int);
	void directionMaze(char[][12], int, int, char);

	//	way(maze, x, y);
	//	fillMaze(maze, x, y);
	//  directionMaze(maze, x, y, 'r');
}

void way(char maze[][12], int x, int y)
{
	void side(char[][12], int, int);

	bool success = false;
	int counter = 0;

	do {
		int r = rand() % 4;

		switch (r)
		{
		case 0:
			if (maze[x - 1][y] == ' ')
			{
				maze[x - 1][y] = '.';
				success = true;
				side(maze, x, y);
				way(maze, x - 1, y);
			}
			break;

		case 1:
			if (maze[x][y + 1] == ' ')
			{
				maze[x][y + 1] = '.';
				success = true;
				side(maze, x, y);
				way(maze, x, y + 1);
			}
			break;

		case 2:
			if (maze[x + 1][y] == ' ')
			{
				maze[x + 1][y] = '.';
				success = true;
				way(maze, x + 1, y);
				side(maze, x, y);
			}
			break;

		case 3:
			if (maze[x][y - 1] == ' ')
			{
				maze[x][y - 1] = '.';
				success = true;
				way(maze, x, y - 1);
				side(maze, x, y);
			}
			break;
		}

		counter++;
		if (counter > 100) success = true;

	} while (!success);
}

void side(char maze[][12], int x, int y)
{
	if (maze[x + 1][y] == ' ')
		if (rand() % 6 == 0)
		{
			maze[x + 1][y] = '.';
			way(maze, x + 1, y);
		}
		else maze[x + 1][y] = '#';

	if (maze[x][y + 1] == ' ')
		if (rand() % 6 == 0)
		{
			maze[x][y + 1] = '.';
			way(maze, x, y + 1);
		}
		else maze[x][y + 1] = '#';

	if (maze[x][y - 1] == ' ')
		if (rand() % 6 == 0)
		{
			maze[x][y - 1] = '.';
			way(maze, x, y - 1);
		}
		else maze[x][y - 1] = '#';

	if (maze[x - 1][y] == ' ')
		if (rand() % 6 == 0)
		{
			maze[x - 1][y] = '.';
			way(maze, x - 1, y);
		}
		else maze[x - 1][y] = '#';
}

void fillMaze(char maze[][12], int x, int y)
{
	if (maze[x + 1][y] == ' ')
		if (rand() % 2 == 0)
		{
			maze[x + 1][y] = '.';
			fillMaze(maze, x + 1, y);
		}
		else maze[x + 1][y] = '#';

	if (maze[x][y + 1] == ' ')
		if (rand() % 2 == 0)
		{
			maze[x][y + 1] = '.';
			fillMaze(maze, x, y + 1);
		}
		else maze[x][y + 1] = '#';

	if (maze[x][y - 1] == ' ')
		if (rand() % 2 == 0)
		{
			maze[x][y - 1] = '.';
			fillMaze(maze, x, y - 1);
		}
		else maze[x][y - 1] = '#';

	if (maze[x - 1][y] == ' ')
		if (rand() % 2 == 0)
		{
			maze[x - 1][y] = '.';
			fillMaze(maze, x - 1, y);
		}
		else maze[x - 1][y] = '#';
}

void directionMaze(char maze[][12], int x, int y, char direction)
{
		switch (direction)
		{
		case 'r':
			if (maze[x][y + 1] == ' ')
				if (rand() % 2 == 0)
				{
					maze[x][y + 1] = '.';
					directionMaze(maze, x, y + 1, 'r');
					if (rand() % 2 == 0)
						if (maze[x + 1][y] == ' ')
							if (rand() % 2 == 0)
							{
								maze[x + 1][y] = '.';
								directionMaze(maze, x + 1, y, 'd');
							}
							else
								maze[x + 1][y] = '#';
						else
						{
							if (maze[x - 1][y] == ' ')
							{
								if (rand() % 2 == 0)
								{
									maze[x - 1][y] = '.';
									directionMaze(maze, x - 1, y, 'u');
								}
								else maze[x - 1][y] = '#';
							}
						}
					else
						if (maze[x - 1][y] == ' ')
							if (rand() % 2 == 0)
							{
								maze[x - 1][y] = '.';
								directionMaze(maze, x - 1, y, 'u');
							}
							else
								maze[x - 1][y] = '#';
						else
						{
							if (maze[x + 1][y] == ' ')
							{
								if (rand() % 2 == 0)
								{
									maze[x + 1][y] = '.';
									directionMaze(maze, x + 1, y, 'd');
								}
								else maze[x + 1][y] = '#';
							}
						}
				}
				else
				{
					maze[x][y + 1] = '#';
					if (rand() % 2 == 0)
						if (maze[x + 1][y] == ' ')
							if (rand() % 2 == 0)
							{
								maze[x + 1][y] = '.';
								directionMaze(maze, x + 1, y, 'd');
							}
							else
							{
								maze[x + 1][y] = '#';
								if (maze[x - 1][y] == ' ')
								{
									maze[x - 1][y] = '.';
									directionMaze(maze, x - 1, y, 'u');
								}
							}
						else
						{
							if (maze[x - 1][y] == ' ')
							{
								maze[x - 1][y] = '.';
								directionMaze(maze, x - 1, y, 'u');
							}
						}
					else
						if (maze[x - 1][y] == ' ')
							if (rand() % 2 == 0)
							{
								maze[x - 1][y] = '.';
								directionMaze(maze, x - 1, y, 'u');
							}
							else
							{
								maze[x - 1][y] = '#';
								if (maze[x + 1][y] == ' ')
								{
									maze[x + 1][y] = '.';
									directionMaze(maze, x + 1, y, 'd');
								}
							}
						else
						{
							if (maze[x + 1][y] == ' ')
							{
								maze[x + 1][y] = '.';
								directionMaze(maze, x + 1, y, 'd');
							}
						}
				}
			else
				if (rand() % 2 == 0)
					if (maze[x + 1][y] == ' ')
						if (rand() % 2 == 0)
						{
							maze[x + 1][y] = '.';
							directionMaze(maze, x + 1, y, 'd');
							if (maze[x - 1][y] == ' ')
								if (rand() % 2 == 0)
								{
									maze[x - 1][y] = '.';
									directionMaze(maze, x - 1, y, 'u');
								}
								else maze[x - 1][y] = '#';
						}
						else
						{
							maze[x + 1][y] = '#';
							if (maze[x - 1][y] == ' ')
							{
								maze[x - 1][y] = '.';
								directionMaze(maze, x - 1, y, 'u');
							}
						}
					else
						if (maze[x - 1][y] == ' ')
						{
							maze[x - 1][y] = '.';
							directionMaze(maze, x - 1, y, 'u');
						}
						else
							;
				else
					if (maze[x - 1][y] == ' ')
						if (rand() % 2 == 0)
						{
							maze[x - 1][y] = '.';
							directionMaze(maze, x - 1, y, 'u');
							if (maze[x + 1][y] == ' ')
								if (rand() % 2 == 0)
								{
									maze[x + 1][y] = '.';
									directionMaze(maze, x + 1, y, 'd');
								}
								else maze[x + 1][y] = '#';
						}
						else
						{
							maze[x - 1][y] = '#';
							if (maze[x + 1][y] == ' ')
							{
								maze[x + 1][y] = '.';
								directionMaze(maze, x + 1, y, 'd');
							}
						}
					else
						if (maze[x + 1][y] == ' ')
						{
							maze[x + 1][y] = '.';
							directionMaze(maze, x + 1, y, 'd');
						}
			break;

		case 'u':
			if (maze[x - 1][y] == ' ')
				if (rand() % 2 == 0)
				{
					maze[x - 1][y] = '.';
					directionMaze(maze, x - 1, y, 'u');
					if (rand() % 2 == 0)
						if (maze[x][y + 1] == ' ')
							if (rand() % 2 == 0)
							{
								maze[x][y + 1] = '.';
								directionMaze(maze, x, y + 1, 'r');
							}
							else
								maze[x][y + 1] = '#';
						else
						{
							if (maze[x][y - 1] == ' ')
							{
								if (rand() % 2 == 0)
								{
									maze[x][y - 1] = '.';
									directionMaze(maze, x, y - 1, 'l');
								}
								else maze[x][y - 1] = '#';
							}
						}
					else
						if (maze[x][y - 1] == ' ')
							if (rand() % 2 == 0)
							{
								maze[x][y - 1] = '.';
								directionMaze(maze, x, y - 1, 'l');
							}
							else
								maze[x][y - 1] = '#';
						else
						{
							if (maze[x][y + 1] == ' ')
							{
								if (rand() % 2 == 0)
								{
									maze[x][y + 1] = '.';
									directionMaze(maze, x, y + 1, 'r');
								}
								else maze[x][y + 1] = '#';
							}
						}
				}
				else
				{
					maze[x - 1][y] = '#';
					if (rand() % 2 == 0)
						if (maze[x][y + 1] == ' ')
							if (rand() % 2 == 0)
							{
								maze[x][y + 1] = '.';
								directionMaze(maze, x, y + 1, 'r');
							}
							else
							{
								maze[x][y + 1] = '#';
								if (maze[x][y - 1] == ' ')
								{
									maze[x][y - 1] = '.';
									directionMaze(maze, x, y - 1, 'l');
								}
							}
						else
						{
							if (maze[x][y - 1] == ' ')
							{
								maze[x][y - 1] = '.';
								directionMaze(maze, x, y - 1, 'l');
							}
						}
					else
						if (maze[x][y - 1] == ' ')
							if (rand() % 2 == 0)
							{
								maze[x][y - 1] = '.';
								directionMaze(maze, x, y - 1, 'l');
							}
							else
							{
								maze[x][y - 1] = '#';
								if (maze[x][y + 1] == ' ')
								{
									maze[x][y + 1] = '.';
									directionMaze(maze, x, y + 1, 'r');
								}
							}
						else
						{
							if (maze[x][y + 1] == ' ')
							{
								maze[x][y + 1] = '.';
								directionMaze(maze, x, y + 1, 'r');
							}
						}
				}
			else
				if (rand() % 2 == 0)
					if (maze[x][y + 1] == ' ')
						if (rand() % 2 == 0)
						{
							maze[x][y + 1] = '.';
							directionMaze(maze, x, y + 1, 'r');
							if (maze[x][y - 1] == ' ')
								if (rand() % 2 == 0)
								{
									maze[x][y - 1] = '.';
									directionMaze(maze, x, y - 1, 'l');
								}
								else maze[x][y - 1] = '#';
						}
						else
						{
							maze[x][y + 1] = '#';
							if (maze[x][y - 1] == ' ')
							{
								maze[x][y - 1] = '.';
								directionMaze(maze, x, y - 1, 'l');
							}
						}
					else
						if (maze[x][y - 1] == ' ')
						{
							maze[x][y - 1] = '.';
							directionMaze(maze, x, y - 1, 'l');
						}
						else
							;
				else
					if (maze[x][y - 1] == ' ')
						if (rand() % 2 == 0)
						{
							maze[x][y - 1] = '.';
							directionMaze(maze, x, y - 1, 'l');
							if (maze[x][y + 1] == ' ')
								if (rand() % 2 == 0)
								{
									maze[x][y + 1] = '.';
									directionMaze(maze, x, y + 1, 'r');
								}
								else maze[x][y + 1] = '#';
						}
						else
						{
							maze[x][y - 1] = '#';
							if (maze[x][y + 1] == ' ')
							{
								maze[x][y + 1] = '.';
								directionMaze(maze, x, y + 1, 'r');
							}
						}
					else
						if (maze[x][y + 1] == ' ')
						{
							maze[x][y + 1] = '.';
							directionMaze(maze, x, y + 1, 'r');
						}
			break;

		case 'd':
			if (maze[x + 1][y] == ' ')
				if (rand() % 2 == 0)
				{
					maze[x + 1][y] = '.';
					directionMaze(maze, x + 1, y, 'd');
					if (rand() % 2 == 0)
						if (maze[x][y + 1] == ' ')
							if (rand() % 2 == 0)
							{
								maze[x][y + 1] = '.';
								directionMaze(maze, x, y + 1, 'r');
							}
							else
								maze[x][y + 1] = '#';
						else
						{
							if (maze[x][y - 1] == ' ')
							{
								if (rand() % 2 == 0)
								{
									maze[x][y - 1] = '.';
									directionMaze(maze, x, y - 1, 'l');
								}
								else maze[x][y - 1] = '#';
							}
						}
					else
						if (maze[x][y - 1] == ' ')
							if (rand() % 2 == 0)
							{
								maze[x][y - 1] = '.';
								directionMaze(maze, x, y - 1, 'l');
							}
							else
								maze[x][y - 1] = '#';
						else
						{
							if (maze[x][y + 1] == ' ')
							{
								if (rand() % 2 == 0)
								{
									maze[x][y + 1] = '.';
									directionMaze(maze, x, y + 1, 'r');
								}
								else maze[x][y + 1] = '#';
							}
						}
				}
				else
				{
					maze[x + 1][y] = '#';
					if (rand() % 2 == 0)
						if (maze[x][y + 1] == ' ')
							if (rand() % 2 == 0)
							{
								maze[x][y + 1] = '.';
								directionMaze(maze, x, y + 1, 'r');
							}
							else
							{
								maze[x][y + 1] = '#';
								if (maze[x][y - 1] == ' ')
								{
									maze[x][y - 1] = '.';
									directionMaze(maze, x, y - 1, 'l');
								}
							}
						else
						{
							if (maze[x][y - 1] == ' ')
							{
								maze[x][y - 1] = '.';
								directionMaze(maze, x, y - 1, 'l');
							}
						}
					else
						if (maze[x][y - 1] == ' ')
							if (rand() % 2 == 0)
							{
								maze[x][y - 1] = '.';
								directionMaze(maze, x, y - 1, 'l');
							}
							else
							{
								maze[x][y - 1] = '#';
								if (maze[x][y + 1] == ' ')
								{
									maze[x][y + 1] = '.';
									directionMaze(maze, x, y + 1, 'r');
								}
							}
						else
						{
							if (maze[x][y + 1] == ' ')
							{
								maze[x][y + 1] = '.';
								directionMaze(maze, x, y + 1, 'r');
							}
						}
				}
			else
				if (rand() % 2 == 0)
					if (maze[x][y + 1] == ' ')
						if (rand() % 2 == 0)
						{
							maze[x][y + 1] = '.';
							directionMaze(maze, x, y + 1, 'r');
							if (maze[x][y - 1] == ' ')
								if (rand() % 2 == 0)
								{
									maze[x][y - 1] = '.';
									directionMaze(maze, x, y - 1, 'l');
								}
								else maze[x][y - 1] = '#';
						}
						else
						{
							maze[x][y + 1] = '#';
							if (maze[x][y - 1] == ' ')
							{
								maze[x][y - 1] = '.';
								directionMaze(maze, x, y - 1, 'l');
							}
						}
					else
						if (maze[x][y - 1] == ' ')
						{
							maze[x][y - 1] = '.';
							directionMaze(maze, x, y - 1, 'l');
						}
						else
							;
				else
					if (maze[x][y - 1] == ' ')
						if (rand() % 2 == 0)
						{
							maze[x][y - 1] = '.';
							directionMaze(maze, x, y - 1, 'l');
							if (maze[x][y + 1] == ' ')
								if (rand() % 2 == 0)
								{
									maze[x][y + 1] = '.';
									directionMaze(maze, x, y + 1, 'r');
								}
								else maze[x][y + 1] = '#';
						}
						else
						{
							maze[x][y - 1] = '#';
							if (maze[x][y + 1] == ' ')
							{
								maze[x][y + 1] = '.';
								directionMaze(maze, x, y + 1, 'r');
							}
						}
					else
						if (maze[x][y + 1] == ' ')
						{
							maze[x][y + 1] = '.';
							directionMaze(maze, x, y + 1, 'r');
						}
			break;

		case 'l':
			if (maze[x][y - 1] == ' ')
				if (rand() % 2 == 0)
				{
					maze[x][y - 1] = '.';
					directionMaze(maze, x, y - 1, 'l');
					if (rand() % 2 == 0)
						if (maze[x + 1][y] == ' ')
							if (rand() % 2 == 0)
							{
								maze[x + 1][y] = '.';
								directionMaze(maze, x + 1, y, 'd');
							}
							else
								maze[x + 1][y] = '#';
						else
						{
							if (maze[x - 1][y] == ' ')
							{
								if (rand() % 2 == 0)
								{
									maze[x - 1][y] = '.';
									directionMaze(maze, x - 1, y, 'u');
								}
								else maze[x - 1][y] = '#';
							}
						}
					else
						if (maze[x - 1][y] == ' ')
							if (rand() % 2 == 0)
							{
								maze[x - 1][y] = '.';
								directionMaze(maze, x - 1, y, 'u');
							}
							else
								maze[x - 1][y] = '#';
						else
						{
							if (maze[x + 1][y] == ' ')
							{
								if (rand() % 2 == 0)
								{
									maze[x + 1][y] = '.';
									directionMaze(maze, x + 1, y, 'd');
								}
								else maze[x + 1][y] = '#';
							}
						}
				}
				else
				{
					maze[x][y - 1] = '#';
					if (rand() % 2 == 0)
						if (maze[x + 1][y] == ' ')
							if (rand() % 2 == 0)
							{
								maze[x + 1][y] = '.';
								directionMaze(maze, x + 1, y, 'd');
							}
							else
							{
								maze[x + 1][y] = '#';
								if (maze[x - 1][y] == ' ')
								{
									maze[x - 1][y] = '.';
									directionMaze(maze, x - 1, y, 'u');
								}
							}
						else
						{
							if (maze[x - 1][y] == ' ')
							{
								maze[x - 1][y] = '.';
								directionMaze(maze, x - 1, y, 'u');
							}
						}
					else
						if (maze[x - 1][y] == ' ')
							if (rand() % 2 == 0)
							{
								maze[x - 1][y] = '.';
								directionMaze(maze, x - 1, y, 'u');
							}
							else
							{
								maze[x - 1][y] = '#';
								if (maze[x + 1][y] == ' ')
								{
									maze[x + 1][y] = '.';
									directionMaze(maze, x + 1, y, 'd');
								}
							}
						else
						{
							if (maze[x + 1][y] == ' ')
							{
								maze[x + 1][y] = '.';
								directionMaze(maze, x + 1, y, 'd');
							}
						}
				}
			else
				if (rand() % 2 == 0)
					if (maze[x + 1][y] == ' ')
						if (rand() % 2 == 0)
						{
							maze[x + 1][y] = '.';
							directionMaze(maze, x + 1, y, 'd');
							if (maze[x - 1][y] == ' ')
								if (rand() % 2 == 0)
								{
									maze[x - 1][y] = '.';
									directionMaze(maze, x - 1, y, 'u');
								}
								else maze[x - 1][y] = '#';
						}
						else
						{
							maze[x + 1][y] = '#';
							if (maze[x - 1][y] == ' ')
							{
								maze[x - 1][y] = '.';
								directionMaze(maze, x - 1, y, 'u');
							}
						}
					else
						if (maze[x - 1][y] == ' ')
						{
							maze[x - 1][y] = '.';
							directionMaze(maze, x - 1, y, 'u');
						}
						else
							;
				else
					if (maze[x - 1][y] == ' ')
						if (rand() % 2 == 0)
						{
							maze[x - 1][y] = '.';
							directionMaze(maze, x - 1, y, 'u');
							if (maze[x + 1][y] == ' ')
								if (rand() % 2 == 0)
								{
									maze[x + 1][y] = '.';
									directionMaze(maze, x - 1, y, 'd');
								}
								else maze[x + 1][y] = '#';
						}
						else
						{
							maze[x - 1][y] = '#';
							if (maze[x + 1][y] == ' ')
							{
								maze[x + 1][y] = '.';
								directionMaze(maze, x + 1, y, 'd');
							}
						}
					else
						if (maze[x + 1][y] == ' ')
						{
							maze[x + 1][y] = '.';
							directionMaze(maze, x + 1, y, 'd');
						}
			break;
		}
}