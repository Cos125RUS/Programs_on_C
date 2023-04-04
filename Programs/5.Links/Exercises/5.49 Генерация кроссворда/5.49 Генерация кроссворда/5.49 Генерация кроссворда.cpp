#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include <string.h>
#include <errno.h>
#include <ctype.h>

using namespace std;

enum Derection { HORIZONTAL, VERTICAL };

int success[500];
int index = 0;

const char* answers[] = { "buckingham", "museum", "westminster", "trafalgard", "nelson", "bigban", "national", "rawens" };

void frame(char crossword[20][20])
{
    for (int i = 0; i < 20; i++)
    {
        crossword[i][0] = '*';
        crossword[i][19] = '*';
        crossword[0][i] = '*';
        crossword[19][i] = '*';
    }    
};

void print(char crossword[20][20])
{
    for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
			cout << crossword[i][j];

		cout << endl;
	}
};

void clear(char updateCrossword[20][20], char crossword[20][20])
{
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            updateCrossword[i][j] = crossword[i][j];
};

bool check(const char* word, const char* field, const int* length)
{
	bool contact = false;
    for (int i = 0; i < *length; i++)
    {
        if (!contact)
            contact = (word[i] == field[i]);

        if ((field[i] == 0) || ((word[i] == field[i]) && (word[i - 1] != field[i - 1]) && (word[i + 1] != field[i + 1])));
        else
            return false;
    }

    if (contact)
        return true;
    else 
        return false;
};

bool parallelLines(char crossword[20][20], const int* length, const int* row, const int* column, Derection line)
{
    bool flag = true;

	if (line == HORIZONTAL)
	{
        if (*column > 1)
			flag = (crossword[*row][*column - 1] == 0);
		if (flag && (*column + *length < 19))
			flag = (crossword[*row][*column + *length] == 0);

        if (flag)
			for (int i = *column; i < *column + *length; i++)
				{
					if (flag && (*row > 1))
						flag = ((crossword[*row - 1][i] == 0) || (crossword[*row - 1][i + 1] == 0));
					if (flag && (*row < 19))
						flag = ((crossword[*row + 1][i] == 0) || (crossword[*row + 1][i + 1] == 0));
				}
	}
	else
	{
		if (*row > 1)
            flag = (crossword[*row - 1][*column] == 0);
		if (flag && (*row + *length < 19))
			flag = (crossword[*row + *length][*column] == 0);

        if (flag)
            for (int i = *row; i < *row + *length; i++)
				{
					if (flag && (*column > 1))
						flag = ((crossword[i][*column - 1] == 0) || (crossword[i + 1][*column - 1] == 0));
					if (flag && (*column < 19))
						flag = ((crossword[i][*column + 1] == 0) || (crossword[i + 1][*column + 1] == 0));
				}
    }

    return flag;
};

void horizontalCopy(char* field, const char* word, const int* length)
{
    for (int i = 0; i < *length; i++)
        field[i] = word[i];

    if (field[-1] != '*') field[-1] = '\0';
    if (field[*length] != '*') field[*length] = '\0';
};

void verticalCopy(char field[20][20], const char* word, const int* length, const int* row, const int* column)
{
    for (int i = 0; i < *length; i++)
        field[*row+i][*column] = word[i];

    if (*row > 1)
        field[*row - 1][*column] = '\0';

    if (*row + *length < 19)
        field[*row + *length][*column] = '\0';
};

void vertical(char crossword[20][20], char* field, const int* column)
{
    for (int i = 1; i < 19; i++)
        field[i] = crossword[i][*column];
};

void createCrossword(char crossword[20][20], int word, Derection line)
{
    if (word == 8)
    {
        print(crossword);
        cout << "\nSTOP!\n\n";
        cin >> success[index++];
    }
    else
    {
        int length = strlen(answers[word]);
        char updateCrossword[20][20] = { "" };

        if (line == HORIZONTAL)
        {
            for (int i = 1; i < 19; i++)
                for (int j = 1; j < 19 - length; j++)
                    if (check(answers[word], &crossword[i][j], &length))
                        if (parallelLines(crossword, &length, &i, &j, line))
						{
							clear(updateCrossword, crossword);
							horizontalCopy(&updateCrossword[i][j], answers[word], &length);
							createCrossword(updateCrossword, word + 1, VERTICAL);
						}
        }
        else //(line == VERTICAL)
            for (int j = 1; j < 19 ; j++)
            {
                char fildLine[20];
                vertical(crossword, fildLine, &j);
                for (int i = 1; i < 19 - length; i++)
                    if (check(answers[word], fildLine+i, &length))
                        if (parallelLines(crossword, &length, &i, &j, line))
						{
							clear(updateCrossword, crossword);
							verticalCopy(updateCrossword, answers[word], &length, &i, &j);
							createCrossword(updateCrossword, word + 1, HORIZONTAL);
						}
            }
    }

};

int main()
{
    setlocale(LC_ALL, "Russian");

    char crossword[20][20] = { "" };
    Derection line = HORIZONTAL;

    frame(crossword);

    int length = strlen(answers[0]);
    char updateCrossword[20][20] = { "" };

    for (int j = 1; j < 19 ; j++)
    {
        char fildLine[20];
        vertical(crossword, fildLine, &j);

        for (int i = 1; i < 19 - length; i++)
        {
			clear(updateCrossword, crossword);
            verticalCopy(updateCrossword, answers[0], &length, &i, &j);
            createCrossword(updateCrossword, 1, line);
        }
    }

    






    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}