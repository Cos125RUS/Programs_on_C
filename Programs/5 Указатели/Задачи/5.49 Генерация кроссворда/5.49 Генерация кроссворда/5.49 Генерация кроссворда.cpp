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

void print(char crossword[20][20])
{
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            cout << crossword[i][j];
};

void clear(char crossword[20][20], char updateCrossword[20][20])
{
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            updateCrossword[i][j] = crossword[i][j];
};

void createCrossword(char crossword[20][20], const char* answers[], int word, Derection line)
{
    int length = strlen(answers[word]);
    char updateCrossword[20][20] = { "" };
    clear(crossword, updateCrossword);

	bool allGood = true;
    bool nextWord = false;
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20 - length; j++)
        {
            if (!nextWord) {
                allGood = true;
                for (int k = 0; k < length; k++)
                    if (allGood)
                    {
                        if (line == HORIZONTAL)
                        {
                            if (crossword[i][j + k] == 0 || (crossword[i][j + k] == answers[word][k] && crossword[i][j + k + 1] == 0))
                                updateCrossword[i][j + k] = answers[word][k];
                            else
                            {
                                allGood = false;
                                clear(crossword, updateCrossword);
                            }
                        }
                        else
                            if (crossword[j + k][i] == 0 || (crossword[j + k][i] == answers[word][k] && crossword[j + k + 1][i] == 0))
                                updateCrossword[j + k][i] = answers[word][k];
                            else
                            {
                                allGood = false;
                                clear(crossword, updateCrossword);
                            }
                    }
                if (allGood)
                {
                    for (int k = 0; k < length; k++)
                        if (line == HORIZONTAL)
                            crossword[i][j + k] = updateCrossword[i][j + k];
                        else
                            crossword[j + k][i] = updateCrossword[j + k][i];
                    
                    clear(crossword, updateCrossword);
                    word++;
                    nextWord = true;
                    if (line == HORIZONTAL)
                        line = VERTICAL;
                    else 
                        line = HORIZONTAL;
                }
            }
        }

    if (word < 8)
        createCrossword(crossword, answers, word, line);
    else
        print(crossword);
};

int main()
{
    setlocale(LC_ALL, "Russian");

    const char* answers[] = { "buckingham", "museum", "westminster", "trafalgard", "nelson", "bigban", "national", "rawens" };
	char crossword[20][20] = { "" };
    Derection line = HORIZONTAL;

    
    createCrossword(crossword, answers, 0, line);








    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}