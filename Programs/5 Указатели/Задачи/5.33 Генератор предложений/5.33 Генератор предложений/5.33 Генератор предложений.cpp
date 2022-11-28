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

void generate(char [][100], const char* [], const char* [], const char* [], const char* [], int*);

int main()
{
    setlocale(LC_ALL, "Russian");

    srand(time(0));

    const char* article[5] = { "the", "a", "one", "some", "any" };
    const char* noun[5] = { "boy", "girl", "dog", "town", "car" };
    const char* verb[5] = { "drow", "jumped", "ran" ,"walked" ,"skipped" };
    const char* preposition[5] = { "to", "frome", "over", "under", "on" };

    char crossword[20][100];

    for (int i = 0; i < 20; i++)
        generate(crossword, article, noun, verb, preposition, &i);





    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}
void generate(char crossword[][100], const char* article[], const char* noun[], const char* verb[], const char* preposition[], int *row)
{
    const char* sp = " ";
    const char* t = ".";
    strcpy_s(crossword[*row], article[rand() % 5]);
    crossword[*row][0] = toupper(crossword[*row][0]);
    strcat_s(crossword[*row], sp);
    strcat_s(crossword[*row], noun[rand() % 5]);
    strcat_s(crossword[*row], sp);
    strcat_s(crossword[*row], verb[rand() % 5]);
    strcat_s(crossword[*row], sp);
    strcat_s(crossword[*row], preposition[rand() % 5]);
    strcat_s(crossword[*row], sp);
    strcat_s(crossword[*row], article[rand() % 5]);
    strcat_s(crossword[*row], sp);
    strcat_s(crossword[*row], noun[rand() % 5]);
    strcat_s(crossword[*row], t);
    cout << crossword[*row] << endl;

}