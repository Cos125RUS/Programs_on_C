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

int separation(char text[200], char words[][20]);
void coding(char words[][20], const int* size);

int main()
{
    setlocale(LC_ALL, "Russian");

    srand(time(0));

    char text[200], words[10][20];
    int size;

    cin.getline(text, 200, '\n');
    cout << endl << endl;

    size = separation(text, words);
    coding(words, &size);

    

    



    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

int separation(char text[200], char words[][20])
{
    char* token;
    char* txt;
    int i = 0;
    
    token = strtok_s(text, " ", &txt);

    while (token != NULL)
    {
		strcpy_s(words[i], token);
		i++;
		token = strtok_s(NULL, " ", &txt);
    }

    return i;
}

void coding(char words[][20], const int* size)
{
    int length;
    char firstLetter;
    char* others;
    const char* increase[5] = { "ay", "df", "gh", "jk", "vb" };
    char code[200] = "";

    for (int i = 0; i < *size; i++)
    {
        length = strlen(words[i]);

        if (length > 1)
        {
			firstLetter = words[i][0];
			others = &words[i][1];
			strncpy_s(words[i], others, length - 1);
            words[i][length - 1] = firstLetter;
            words[i][length] = '\0';
            strcat_s(words[i], increase[rand()%5]);
        }

        if (i != (*size - 1))
			strcat_s(words[i], " ");

        strcat_s(code, words[i]);
    }

    cout << code;
}