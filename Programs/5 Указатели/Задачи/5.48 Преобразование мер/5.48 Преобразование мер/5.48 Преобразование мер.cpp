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

const char* engLength[] = { "дюйм", "фут", "€рд", "мил€" };
const char* engWeight[] = { "фунт", "стоун", "унци", " " };
const char* engLiquids[] = { "пинт", "баррел", "галлон", " " };
const char* engBulk[] = { "кварт", "пек", "бушел", " " };

const char* rusLength[] = { "миллиметр", "сантиметр", "метр", "киллометр" };
const char* rusWeight[] = { "грамм", "килограмм", "тонн", "центнер" };
const char* rusLiquids[] = { "литр", "милилитр", " ", " " };

const char* *allMeasures[] = { engLength , engWeight , engLiquids ,engBulk ,rusLength ,rusWeight ,rusLiquids };

int separation(char text[100], char words[][20])
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
};

bool comparison(const char* w1, const char* w2)
{
    for (int i = 0; i < strlen(w2); i++)
        if (w1[i] != w2[i]) return false;
    return true;
};

void measuresDefinition(char words[10][20], int* size, int* measure1, int* measure2, int* scale1, int* scale2)
{
	for (int i = 0; i < *size; i++)
		for (int j = 0; j < 4; j++)
		{
			if (comparison(words[i], engLength[j]))
				if (*measure1 == -1)
				{
					*measure1 = 0;
					*scale1 = j;
				}
				else
				{
					*measure2 = 0;
					*scale2 = j;
					break;
				}
			if (comparison(words[i], engWeight[j]))
				if (*measure1 == -1)
				{
					*measure1 = 1;
					*scale1 = j;
				}
				else
				{
					*measure2 = 1;
					*scale2 = j;
					break;
				}
			if (comparison(words[i], engLiquids[j]))
				if (*measure1 == -1)
				{
					*measure1 = 2;
					*scale1 = j;
				}
				else
				{
					*measure2 = 2;
					*scale2 = j;
					break;
				}
			if (comparison(words[i], engBulk[j]))
				if (*measure1 == -1)
				{
					*measure1 = 3;
					*scale1 = j;
				}
				else
				{
					*measure2 = 3;
					*scale2 = j;
					break;
				}
			if (comparison(words[i], rusLength[j]))
				if (*measure1 == -1)
				{
					*measure1 = 4;
					*scale1 = j;
				}
				else
				{
					*measure2 = 4;
					*scale2 = j;
					break;
				}
			if (comparison(words[i], rusWeight[j]))
				if (*measure1 == -1)
				{
					*measure1 = 5;
					*scale1 = j;
				}
				else
				{
					*measure2 = 5;
					*scale2 = j;
					break;
				}
			if (comparison(words[i], rusLiquids[j]))
				if (*measure1 == -1)
				{
					*measure1 = 6;
					*scale1 = j;
				}
				else
				{
					*measure2 = 6;
					*scale2 = j;
					break;
				}
		}
};

double conversionLength(int* s1, int* s2, int ratio)
{
	double x = 25.4, 
		   y = 1;

	switch (*s1)
	{
	case 1:
		x *= 12;
		break;

	case 2:
		x *= 36;
		break;

	case 3:
		x *= 63360;
		break;
	}

	switch (*s2)
	{
	case 1:
		y *= 10;
		break;

	case 2:
		y *= 1000;
		break;

	case 3:
		y *= 1000000;
		break;
	}

	if (ratio > 0)
		return y / x;
	else 
		return x / y;
};

double chack(int* measure1, int* measure2, int* scale1, int* scale2)
{
	if (*measure1 == 0 && *measure2 == 4) return conversionLength(scale1, scale2, 1);
	if (*measure1 == 1 && *measure2 == 5) return false;
	if (*measure1 == 2 && *measure2 == 6) return false;
	if (*measure1 == 3 && *measure2 == 5) return false;
	if (*measure1 == 4 && *measure2 == 0) return conversionLength(scale2, scale1, -1);
	if (*measure1 == 5 && *measure2 == 1) return false;
	if (*measure1 == 5 && *measure2 == 3) return false;
	if (*measure1 == 6 && *measure2 == 2) return false;

	cout << "Error!";
};

int main()
{
    setlocale(LC_ALL, "Russian");

    char text[100] = "";
    char words[10][20];
    
    cin.getline(text, 100, '\n');

    int size = separation(text, words);
	int measure1 = -1, measure2 = -1,
        scale1, scale2;
    measuresDefinition(words, &size, &measure1, &measure2, &scale1, &scale2);
	
	double res = chack(&measure1, &measure2, &scale1, &scale2);
		cout << res << endl;
	
	





    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}