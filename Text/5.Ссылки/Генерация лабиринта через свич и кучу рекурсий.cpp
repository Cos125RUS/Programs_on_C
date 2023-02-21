case 'u':
			if (maze[x - 1][y] == ' ')
				if (rand() % 2 == 0)
				{
					maze[x - 1][y] = '.';
					success = true;
					directionMaze(maze, x - 1, y, 'u');
					int r = rand() % 3;
					switch (r)
					{
					case 0:
						directionMaze(maze, x, y, 'r');
						if (rand() % 2 == 0)
						{
							directionMaze(maze, x, y, 'd');
							directionMaze(maze, x, y, 'l');
						}
						else
						{
							directionMaze(maze, x, y, 'l');
							directionMaze(maze, x, y, 'd');
						}
						break;

					case 1:
						directionMaze(maze, x, y, 'l');
						if (rand() % 2 == 0)
						{
							directionMaze(maze, x, y, 'r');
							directionMaze(maze, x, y, 'd');
						}
						else
						{
							directionMaze(maze, x, y, 'd');
							directionMaze(maze, x, y, 'r');
						}
						break; 
					
					case 2:
							directionMaze(maze, x, y, 'd');
							if (rand() % 2 == 0)
							{
								directionMaze(maze, x, y, 'r');
								directionMaze(maze, x, y, 'l');
							}
							else
							{
								directionMaze(maze, x, y, 'l');
								directionMaze(maze, x, y, 'r');
							}
							break;
					}
				}
				else
				{
					maze[x - 1][y] = '#';
					int r = rand() % 3;
					switch (r)
					{
					case 0:
						directionMaze(maze, x, y, 'r');
						if (rand() % 2 == 0)
						{
							directionMaze(maze, x, y, 'd');
							directionMaze(maze, x, y, 'l');
						}
						else
						{
							directionMaze(maze, x, y, 'l');
							directionMaze(maze, x, y, 'd');
						}
						break;

					case 1:
						directionMaze(maze, x, y, 'l');
						if (rand() % 2 == 0)
						{
							directionMaze(maze, x, y, 'r');
							directionMaze(maze, x, y, 'd');
						}
						else
						{
							directionMaze(maze, x, y, 'd');
							directionMaze(maze, x, y, 'r');
						}
						break;

					case 2:
						directionMaze(maze, x, y, 'd');
						if (rand() % 2 == 0)
						{
							directionMaze(maze, x, y, 'r');
							directionMaze(maze, x, y, 'l');
						}
						else
						{
							directionMaze(maze, x, y, 'l');
							directionMaze(maze, x, y, 'r');
						}
						break;
					}
				}
			else
			{
				int r = rand() % 3;
				switch (r)
				{
				case 0:
					directionMaze(maze, x, y, 'r');
					if (rand() % 2 == 0)
					{
						directionMaze(maze, x, y, 'd');
						directionMaze(maze, x, y, 'l');
					}
					else
					{
						directionMaze(maze, x, y, 'l');
						directionMaze(maze, x, y, 'd');
					}
					break;

				case 1:
					directionMaze(maze, x, y, 'l');
					if (rand() % 2 == 0)
					{
						directionMaze(maze, x, y, 'r');
						directionMaze(maze, x, y, 'd');
					}
					else
					{
						directionMaze(maze, x, y, 'd');
						directionMaze(maze, x, y, 'r');
					}
					break;

				case 2:
					directionMaze(maze, x, y, 'd');
					if (rand() % 2 == 0)
					{
						directionMaze(maze, x, y, 'r');
						directionMaze(maze, x, y, 'l');
					}
					else
					{
						directionMaze(maze, x, y, 'l');
						directionMaze(maze, x, y, 'r');
					}
					break;
				}
			}
			break;