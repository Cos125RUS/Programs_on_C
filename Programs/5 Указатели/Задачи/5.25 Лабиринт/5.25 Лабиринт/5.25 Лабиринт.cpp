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

int main()
{
	setlocale(LC_ALL, "Russian");

	char maze[12][12] = { {'#','#','#','#','#','#','#','#','#','#','#','#'},
						  {'#','.','.','.','#','.','.','.','.','.','.','#'},
						  {'.','.','#','.','#','.','#','#','#','#','.','#'},
						  {'#','#','#','.','#','.','.','.','.','#','.','#'},
						  {'#','.','.','.','.','#','#','#','.','#','.','.'},
						  {'#','#','#','#','.','#','.','#','.','#','.','#'},
						  {'#','.','.','#','.','#','.','#','.','#','.','#'},
						  {'#','#','.','#','.','#','.','#','.','#','.','#'},
						  {'#','.','.','.','.','.','.','.','.','#','.','#'},
						  {'#','#','#','#','#','#','.','#','#','#','.','#'},
						  {'#','.','.','.','.','.','.','#','.','.','.','#'},
						  {'#','#','#','#','#','#','#','#','#','#','#','#'} };

	int x = 2, y = 0;
	char direction = 'r';

	mazeTravers(maze, x, y, direction);




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