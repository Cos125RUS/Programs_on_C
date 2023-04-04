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

void generate(char[][100], const char* [], const char* [], const char* [], const char* [], int*);

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(0));

	const char* article[5] = { "the ", "a ", "one ", "some ", "any " };
	const char* noun[5] = { "boy ", "girl ", "dog ", "town ", "car " };
	const char* verb[5] = { "drove ", "jumped ", "ran " ,"walked " ,"skipped " };
	const char* preposition[5] = { "to ", "frome ", "over ", "under ", "on " };

	char crossword[20][100];

	for (int i = 0; i < 20; i++)
		generate(crossword, article, noun, verb, preposition, &i);





	cout << "\n\n\n\n\n\n\n\n\n\n";

	return 0;
}
void generate(char crossword[][100], const char* article[], const char* noun[], const char* verb[], const char* preposition[], int* row)
{
	int n1_chois, v_chois, p_chois, a2_chois, n2_chois;
	int a1_chois = rand() % 5;

	strcpy_s(crossword[*row], article[a1_chois]);
	crossword[*row][0] = toupper(crossword[*row][0]);

	switch (a1_chois)
	{
	case 0:
		n1_chois = 3 + rand() % 2;
		break;

	case 1:
		n1_chois = rand() % 3;
		break;

	default:
		n1_chois = rand() % 5;
		break;
	}
	strcat_s(crossword[*row], noun[n1_chois]);

	switch (n1_chois)
	{
	case 4:
		v_chois = 0;
		break;

	case 3:
		v_chois = 4;
		break;

	case 2:
		v_chois = 1 + rand() % 4;
		break;

	default:
		v_chois = rand() % 5;
		break;
	}
	strcat_s(crossword[*row], verb[v_chois]);

	switch (v_chois)
	{
	case 0:
		p_chois = rand() % 2;
		break;

	case 2:
	case 3:
		p_chois = rand() % 3;
		if (p_chois == 2) p_chois = 4;
		break;

	case 4:
		p_chois = 0;
		break;

	default:
		p_chois = rand() % 5;
		break;
	}
	strcat_s(crossword[*row], preposition[p_chois]);

	switch (n1_chois)
	{
	case 3:
		a2_chois = 1;
		n2_chois = 2;
		break;

	case 4:
		a2_chois = 0;
		n2_chois = 3;
		break;

	default:
		a2_chois = rand() % 5;
		switch (a2_chois)
		{
		case 0:
			n2_chois = 3 + rand() % 2;
			break;

		case 1:
			n2_chois = rand() % 3;
			break;

		default:
			n2_chois = rand() % 5;
			break;
		}
		break;
	}

	strcat_s(crossword[*row], article[a2_chois]);
	strcat_s(crossword[*row], noun[n2_chois]);

	crossword[*row][strlen(crossword[*row]) - 1] = '.';
	cout << crossword[*row] << endl;
}