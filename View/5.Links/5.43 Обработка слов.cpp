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

void separation(char* s)
{

};
int linesNumbets(char text[650], char strings[10][65])
{
    int i = 0;
    char* token;
    char* txt;

    token = strtok_s(text, "\n", &txt);

    for (i; token != NULL; i++)
    {
        while (strlen(token) > 65)
        {
            int j = 64;
            while (token[j] != ' ') j--;
            token[j] = '*';
            char* t;
            char* p;
            t = strtok_s(token, "*", &p);
            strcpy_s(strings[i], t);
            i++;
            token = p;
        }

		strcpy_s(strings[i], token);
		token = strtok_s(NULL, "\n", &txt);
    }
    return i;
};
void printText(char* string)
{
    cout << setw(9) << setiosflags(ios::left) << ' ';

    if (strlen(string) < 60)
        cout << string;
    else
    {
        int space = 0;
        for (int i = 0; i < 65; i++)
            if (string[i] == ' ') space++;
        
        while ((strlen(string) + space) > 65) 
            space--;

        for (int i = 0; string[i] != '\0'; i++)
		{
            if ((string[i] == ' ') && (space > 0))
            {
                cout << ' ';
                space--;
            }

			cout << string[i];
		}
	}

    cout << endl;
};

int main()
{
    setlocale(LC_ALL, "Russian");

    char text[650];
    char strings[10][65];


    cin.getline(text, 650, EOF);
    cout << endl << endl << endl << endl;

    int lines = linesNumbets(text, strings);

    for (int i = 0; i < lines; i++)
        printText(strings[i]);


    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}