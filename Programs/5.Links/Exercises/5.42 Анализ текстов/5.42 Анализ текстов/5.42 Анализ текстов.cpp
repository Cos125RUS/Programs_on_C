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

void countingLetters(char* text, int alphabet[])
{
    for (int i = 0; text[i] != '\0'; i++)
        text[i] = tolower(text[i]);
     
    while (*text != '\0')
        ++alphabet[*text++];

    for (int i = 97; i < 127; i++)
        if (alphabet[i] > 0)
		{
			char letter = i;
			cout << letter << " - " << alphabet[i] << endl;
		}
};
void discardUnnecessary(char* word)
{
    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] < 65)
            word[i] = '\0';
    }
};
int separationWordsLength(char* text, char words[][30])
{
    char* token;
    char* txt;
    int i = 0;

    token = strtok_s(text, " ", &txt);
        
    while (token != NULL)
    {
        strcpy_s(words[i], token);
        discardUnnecessary(words[i]);
        i++;
        token = strtok_s(NULL, " ", &txt);
    }

    return i;
};
void wordsLength(char words[][30], const int* size, int length[])
{
    for (int i = 0; i < *size; i++)
        ++length[strlen(words[i])];

    cout << "Length of the word\tQuantity\n";
    for (int i = 1; i < 30; i++)
        if (length[i] > 0)
            cout << setw(9) << i << setw(19) << length[i] << endl;
};
bool comparison(const char* w1, const char* w2, int length)
{
    for (int i = 0; i < length; i++)
        if (w1[i] != w2[i]) return false;
    return true;
};
void frequency(char words[][30], const int* size, int length[])
{
    cout << setw(12) << "Words:" << setw(13) << "Volume:" << endl << endl;

    for (int i = 0; i < *size; i++)
        if (length[strlen(words[i])] > 0)
        {
            int len = strlen(words[i]), 
                l = 1;
            
            for (int j = i + 1; j < *size && l < len; j++)
                if (strlen(words[j]) == len)
                    if (comparison(words[i], words[j], len))
                    {
                        l++;
                        for(int k = 0; k < len; k++)
							words[j][k] = ' ';
                        words[j][0] = '\0';
                    }
			
            cout << setw(12) << setiosflags(ios::right) << words[i] << setw(10) << setiosflags(ios::left) << l << endl;
        }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    int alphabet[127] = { 0 };
    char text[200];
    char words[50][30];
    int length[30] = { 0 };

    cin.getline(text, 200,'\n');
    cout << endl << endl;

    countingLetters(text, alphabet);
    cout << endl << endl;

    int size = separationWordsLength(text, words);
    wordsLength(words, &size, length);
    cout << endl << endl;

    frequency(words, &size, length);




    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}