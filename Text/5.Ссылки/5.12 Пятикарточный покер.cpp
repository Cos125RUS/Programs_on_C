#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

using namespace std;

void shuffle(int[][13], int[], int[]);
void deal(const int[][13], const char* [], const char* []);
void combinations(int[], int[], const char* []);

int main()
{
	setlocale(LC_ALL, "Russian");

	const char* suit[4] = { "Черви", "Буби", "Трефы", "Пики" };
	const char* face[13] = { "Туз", "Двойка", "Тройка", "Четвёрка", "Пятёрка", "Шестёрка", "Семёрка",
							"Восьмёрка", "Девятка", "Десятка", "Валет", "Дама", "Король" };
	const char* comb[] = { "Старшая карта" ,"Пара", "Две пары", "Тройка", "Стрит", "Флэш", "Фулл-хаус", "Каре", "Стрит-флэш" };

	int deck[4][13] = { 0 };
	int colour[4] = { 0 };
	int quality[13] = { 0 };

	srand(time(0));

	shuffle(deck, quality, colour);
	deal(deck, face, suit);

	cout << endl << endl ;

	combinations(quality, colour, comb);




	cout << "\n\n\n\n\n\n\n\n\n\n";

	return 0;
}

void shuffle(int wDeck[][13], int quality[], int colour[])
{
	int row, column;

	for (int card = 1; card <= 5; card++)
	{
		do {
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);
		wDeck[row][column] = card;
		++quality[column];
		++colour[row];
	}
}

void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[])
{
	for (int card = 1; card <= 5; card++)
		for (int row = 0; row <= 3; row++)
			for (int column = 0; column <= 12; column++)
				if (wDeck[row][column] == card)
					cout << setw(10) << setiosflags(ios::right) << wFace[column]
					<< " масти " << setiosflags(ios::left) << wSuit[row] << endl;
}

void combinations(int quality[], int colour[], const char* comb[])
{
	int distribution = 0;
	int couple = 0;
	int street = 0;

	for (int column = 0; column <= 12; column++)
	{
		if (quality[column] > 0) street++;
		else
			if (street < 5) street = 0;
		if (quality[column] == 2) couple++;
		if (quality[column] == 3) distribution = 3;
		if (quality[column] == 4) distribution = 7;
	}

	if (distribution == 3 && couple > 0) distribution = 6;

	if (distribution < 4 && street == 5) distribution = 4;

	for (int row = 0; row <= 3; row++)
		if (colour[row] == 5)
			if (street == 5) distribution = 8;
			else
				if (distribution < 5) distribution = 5;

	if (distribution == 0 && couple > 0)
		if (couple == 2) distribution = 2;
		else distribution = 1;

	cout << setw(15) << comb[distribution];
}
