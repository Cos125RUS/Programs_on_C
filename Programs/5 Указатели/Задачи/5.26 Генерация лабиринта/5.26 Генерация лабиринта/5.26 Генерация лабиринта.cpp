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

void print_array(char[][20]);
void mazeTravers(char[][20], int, int);
void mazeGenerator(char[][20]);

bool flag = false;

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(0));

	char maze[20][20];


	mazeGenerator(maze);
	print_array(maze);



	cout << "\n\n\n\n\n\n\n\n\n\n";

	return 0;
}

void print_array(char maze[][20])
{
	cout << endl << endl;

	for (int i = 0; i < 20; i++)
	{
		cout << setw(5) << ' ';
		for (int j = 0; j < 20; j++)
			cout << maze[i][j];
		cout << endl;
	}
	cout << endl << endl;
}

void mazeTravers(char maze[][20], int x, int y)
{
	if (maze[x][y] != '#' && maze[x][y] != 'x')
	{
		maze[x][y] = 'x';

		if (y == 19)
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

void mazeGenerator(char maze[][20])
{
	void fillMaze(char[][20]);

	while (!flag)
	{
		fillMaze(maze);

		int x = 1 + rand() % 10;
		int y = 1 + rand() % 10;

		maze[x][0] = '.';
		maze[x][1] = '.';
		maze[y][19] = '.';
		maze[y][18] = '.';

		mazeTravers(maze, x, 1);
	}
}

void fillMaze(char maze[][20])
{
	for (int i = 0; i < 20; i++)
	{
		maze[0][i] = '#';
		maze[19][i] = '#';
		maze[i][0] = '#';
		maze[i][19] = '#';
	}
	
	for (int i = 1; i < 19; i++)
		for (int j = 1; j < 19; j++)
			if (rand() % 10 > 4) maze[i][j] = '.';
			else maze[i][j] = '#';
}