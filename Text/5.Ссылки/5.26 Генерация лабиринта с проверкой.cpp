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
void mazeTravers(char[][12], int, int);
void mazeGenerator(char[][12]);

bool flag = false;

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(0));

	char maze[12][12];


	mazeGenerator(maze);
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

void mazeTravers(char maze[][12], int x, int y)
{
	if (maze[x][y] != '#' && maze[x][y] != 'X')
	{
		maze[x][y] = 'X';

		if (y == 11)
			flag = true;
		else
		{
			mazeTravers(maze, x, y + 1);
			mazeTravers(maze, x + 1, y);
			mazeTravers(maze, x - 1, y);
			mazeTravers(maze, x, y - 1);
		}
	}
}

void mazeGenerator(char maze[][12])
{
	void fillMaze(char[][12]);

	while (!flag)
	{
		fillMaze(maze);

		int x = 1 + rand() % 10;
		int y = 1 + rand() % 10;

		maze[x][0] = '.';
		maze[x][1] = '.';
		maze[y][11] = '.';
		maze[y][10] = '.';

		mazeTravers(maze, x, 1);
	}
}

void fillMaze(char maze[][12])
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
			if (rand() % 2 == 0) maze[i][j] = '.';
			else maze[i][j] = '#';
}