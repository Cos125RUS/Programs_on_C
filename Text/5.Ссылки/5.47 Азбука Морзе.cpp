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

void printMorse(char text[500], const char* morse[])
{
    int size = strlen(text);

    for (int i = 0; i < size; i++)
    {
        text[i] = toupper(text[i]);
        cout << morse[text[i]] << ' ';
    }
};

int separation(char code[1000], char words[][10])
{
    char* token;
    char* txt;
    int i = 0;
    const char* sp = "space";

    token = strtok_s(code, " ", &txt);


    while (token != NULL)
    {
        strcpy_s(words[i], token);
        i++;

		if (txt[0] == ' ' && txt[1] == ' ')
		{
			strcpy_s(words[i], sp);
			i++;
            while (*txt == ' ') txt++;
        }

		token = strtok_s(NULL, " ", &txt);
    }

    return i;
}

bool comparison(const char* w1, const char* w2)
{
    for (int i = 0; i < strlen(w1); i++)
        if (w1[i] != w2[i]) return false;
    return true;
};

void prinText(char code[1000], const char* morse[])
{
    char words[100][10];
    int size = separation(code, words);
    char letter;

    cout << '*';

    for (int i = 0; i < size; i++)
    {
        if (comparison(words[i], "space"))
            cout << ' ';
        else
			for (int j = 0; j < 91; j++)
				if (strcmp(words[i], morse[j]) == 0)
					if (comparison(words[i], morse[j]))
					{
                        letter = j;
						cout << letter;
					}
    }

    cout << '*';
};

int main()
{
    setlocale(LC_ALL, "Russian");

    const char* morse[] = { "","","","","","","","","","","","","","","","","","","","","","","","",
                            "","","","","","","","","  ","","","","","","","","","","","","","","","",
                            "-----",".----","..---","...--","....-",".....","-....","--...","---..","----.",
                            "","","","","","","",
                            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..",
                            "--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };

    char text[500] = "";
    cin.getline(text, 500, '\n');
    printMorse(text, morse);
    cout << endl << endl;

    char code[1000] = "";
    cin.getline(code, 1000, '\n');
    prinText(code, morse);





    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}