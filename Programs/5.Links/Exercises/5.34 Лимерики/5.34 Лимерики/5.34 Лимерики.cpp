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
void createName(char [], const char* [], const char* [], bool);

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(0));

	const char* name_male[5] = { "Ген", "Вов", "Вас", "Пет", "Ван" };
	const char* name_female[5] = { "Юл", "Тан", "Кат", "Маш", "Даш" };
	const char* name_endings[7] = { "у ", "е ", "ы ", "и ", "ю ", "а ", "я " };

	const char* pronouns_nominative[4] = { "он ", "она ", "они ", "оно " };
	const char* pronouns_object[6] = { "его ", "ему ", "ей ", "её ", "их ", "им " };

	const char* object_male[5] = { "бокал", "рюкзак", "стул", "телефон", "ключ" };
	const char* object_female[5] = { "подушк", "книг", "ручк", "тарелк", "салфетк" };
	const char* object_neuter_singular[4] = { "одеял", "блюдц", "дел", "слов" };
	const char* object_only_plural[5] = { "часы ", "деньги ", "сутки ", "очки ", "выборы " };
	const char* object_endings[5] = { "ы ", "и ", "ья ", "и ", "а " };

	const char* verb[5] = { "дал ", "взял ", "попросил ", "выбрал ", "использовал " };

	const char* adverb[5] = { "много ", "мало ", "ещё ", "чуть ", "совсем " };

	const char* adjective[5] = { "нов", "больш", "последн", "хорош", "маленьк" };
	const char* adjective_endings_male[3] = { "ый ", "ой ", "ий " };
	const char* adjective_endings_female[2] = { "ая ", "яя " };
	const char* adjective_endings_plural[2] = { "ые ", "ие "};

	const char* preposition[6] = { "на ", "в ", "из ", "под ", "к ", "у " };
	
	char d[20][100];

	bool male = rand() % 2;
	char name[20];

	if (male) createName(name, name_male, name_endings, male);
	else createName(name, name_female, name_endings, male);

	cout << name;





	cout << "\n\n\n\n\n\n\n\n\n\n";

	return 0;
}

void generate(char crossword[][100], const char* name[], const char* noun[], const char* verb[], const char* adjective[], int* row)
{
	
}

void createName(char name[], const char* root[], const char* ending[], bool male)
{
	int i = rand() % 5;

	strcpy_s(name, 5, root[i]);
	
	if (male)
		if (i < 2)
			strcat_s(name, 5, ending[5]);
		else
			strcat_s(name, 5, ending[6]);
	else
		if (i < 3)
			strcat_s(name, 5, ending[6]);
		else
			strcat_s(name, 5, ending[5]);
}