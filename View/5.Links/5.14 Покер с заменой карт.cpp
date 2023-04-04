#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

using namespace std;

void shuffle(int[][13], int[], int[], int[][13]);
void deal(const int[][13], const int[][13], const char* [], const char* []);
int combinations(int[], int[], const char* []);
void winner(int, int, int[], int[]);
void replacing(int[][13], int, int[], int[], const char* [], int[][13]);

int main()
{
	setlocale(LC_ALL, "Russian");

	const char* suit[4] = { "Черви", "Буби", "Трефы", "Пики" };
	const char* face[13] = { "Туз", "Двойка", "Тройка", "Четвёрка", "Пятёрка", "Шестёрка", "Семёрка",
							"Восьмёрка", "Девятка", "Десятка", "Валет", "Дама", "Король" };
	const char* comb[] = { "Старшая карта" ,"Пара", "Две пары", "Тройка", "Стрит", "Флэш", "Фулл-хаус", "Каре", "Стрит-флэш" };

	int player[4][13] = { 0 };
	int quality_player[13] = { 0 };
	int colour_player[4] = { 0 };

	int croupier[4][13] = { 0 };
	int quality_croupier[13] = { 0 };
	int colour_croupier[4] = { 0 };

	int deck[4][13] = { 0 };


	srand(time(0));

	shuffle(player, quality_player, colour_player, deck);
	shuffle(croupier, quality_croupier, colour_croupier, deck);

	deal(player, croupier, face, suit);

	int estimation_player = combinations(quality_player, colour_player, comb);
	int estimation_croupier = combinations(quality_croupier, colour_croupier, comb);
	cout << endl << endl;

	replacing(player, estimation_player, quality_player, colour_player, comb, deck);
	replacing(croupier, estimation_croupier, quality_croupier, colour_croupier, comb, deck);
	deal(player, croupier, face, suit);
	estimation_player = combinations(quality_player, colour_player, comb);
	estimation_croupier = combinations(quality_croupier, colour_croupier, comb);
	cout << endl << endl;


	winner(estimation_player, estimation_croupier, quality_player, colour_croupier);



	cout << "\n\n\n\n\n\n\n\n\n\n";

	return 0;
}

void shuffle(int distribution[][13], int quality[], int colour[], int deck[][13])
{
	int row, column;

	for (int card = 1; card <= 5; card++)
	{
		do {
			row = rand() % 4;
			column = rand() % 13;
		} while (distribution[row][column] != 0 || deck[row][column] != 0);
		distribution[row][column] = card;
		deck[row][column] = card;
		++quality[column];
		++colour[row];
	}
}

void deal(const int wDeck1[][13], const int wDeck2[][13], const char* wFace[], const char* wSuit[])
{
	for (int card = 1; card <= 5; card++)
	{
		for (int row = 0; row <= 3; row++)
			for (int column = 0; column <= 12; column++)
				if (wDeck1[row][column] == card)
					cout << setw(10) << setiosflags(ios::right) << wFace[column]
					<< " масти " << setiosflags(ios::left) << wSuit[row] << setw(10) << '\t';

		for (int row = 0; row <= 3; row++)
			for (int column = 0; column <= 12; column++)
				if (wDeck2[row][column] == card)
					cout << setw(10) << setiosflags(ios::right) << wFace[column]
					<< " масти " << setiosflags(ios::left) << wSuit[row] << endl;
	}
	cout << endl << endl;
}

int combinations(int quality[], int colour[], const char* comb[])
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

	cout << setw(15) << comb[distribution] << setw(10) << '\t';

	return distribution;
}

void winner(int p1, int p2, int quality1[], int quality2[])
{
	bool high_card(int[], int[], int);

	if (p1 > p2) cout << "\n\n\n\n\t\t\tPlayqr 1 win!";
	else
		if (p2 > p1) cout << "\n\n\n\n\t\t\tPlayqr 2 win!";
		else
			if (high_card(quality1, quality2, p1)) cout << "\n\n\n\n\t\t\tPlayqr 1 win!";
			else cout << "\n\n\n\n\t\t\tPlayqr 2 win!";
}

bool high_card(int q1[], int q2[], int d)
{
	int x;
	switch (d)
	{
	case 1:
		x = 2;
		break;

	case 2:
		x = 2;
		break;

	case 3:
		x = 3;
		break;

	case 7:
		x = 4;
		break;

	default:
		x = 1;
		break;
	}

	if (q1[0] == x && q2[0] == x);
	else
		if (q1[0] == x || q2[0] == x) return q1[0] > q2[0];

	for (int i = 12; i > 0; i--)
	{
		if (q1[i] == x && q2[i] == x);
		else
			if (q1[i] == x || q2[i] == x) return q1[0] > q2[0];
	}
}

void replacing(int player[][13], int distribution, int quality[], int colour[], const char* comb[], int deck[][13])
{
	int change[3] = { 0 };
	int rows[3] = { 0 };
	int columns[3] = { 0 };
	int counter = 0;

	if (distribution < 4 || distribution == 7)
		for (int column = 1; column <= 12; column++)
			if (counter < 3)
				if (quality[column] == 1)
					for (int row = 0; row <= 3; row++)
						if (player[row][column] != 0)
						{
							change[counter] = player[row][column];
							rows[counter] = row;
							columns[counter] = column;
							counter++;
							--quality[column];
							--colour[row];
						}

	if (counter > 0)
		for (int i = 0; i < counter; i++)
		{
			int row, column;
			do {
				row = rand() % 4;
				column = rand() % 13;
			} while (player[row][column] != 0 || deck[row][column] != 0);
			player[row][column] = change[i];
			++quality[column];
			++colour[row];
		}

	for (int i = 0; i < counter; i++)
		player[rows[i]][columns[i]] = 0;
}