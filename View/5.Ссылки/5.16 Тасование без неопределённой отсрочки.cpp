#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

using namespace std;

void shuffle(int[][13], const int*, const int*);
void deal(const int[][13], const char* [], const char* []);
void fill_deck(int[][13], const int*, const int*);
void print_deck(int[][13], const int*, const int*);

int main()
{
	setlocale(LC_ALL, "Russian");

	const int row = 4,
		column = 13;

	const char* suit[row] = { "Черви", "Буби", "Трефы", "Пики" };
	const char* face[column] = { "Туз", "Двойка", "Тройка", "Четвёрка", "Пятёрка", "Шестёрка", "Семёрка",
							"Восьмёрка", "Девятка", "Десятка", "Валет", "Дама", "Король" };

	int deck[row][column] = { 0 };

	srand(time(0));


	fill_deck(deck, &row, &column);
	//print_deck(deck, &row, &column);

	for (int i = 0; i < 500; i++)
		shuffle(deck, &row, &column);

	print_deck(deck, &row, &column);
	deal(deck, face, suit);



	cout << "\n\n\n\n\n\n\n\n\n\n";

	return 0;
}

void shuffle(int wDeck[][13], const int* row, const int* column)
{
	int change_row, change_column, change_card, card = 1;

	for (int i = 0; i < *row; i++)
		for (int j = 0; j < *column; j++)
		{
			change_row = rand() % 4;
			change_column = rand() % 13;
			change_card = wDeck[change_row][change_column];
			wDeck[change_row][change_column] = wDeck[i][j];
			wDeck[i][j] = change_card;
		}


}

void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[])
{
	for (int card = 1; card <= 52; card++)
		for (int row = 0; row <= 3; row++)
			for (int column = 0; column <= 12; column++)
				if (wDeck[row][column] == card)
				{
					cout << setw(10) << setiosflags(ios::right) << wFace[column]
						<< " масти " << setiosflags(ios::left) << wSuit[row]
						<< setw(5) << (card % 2 == 0 ? '\n' : '\t');

					break;
				}
}

void fill_deck(int deck[][13], const int* row, const int* column)
{
	int n = 0;

	for (int i = 0; i < *row; i++)
		for (int j = 0; j < *column; j++)
			deck[i][j] = ++n;
}

void print_deck(int deck[][13], const int* row, const int* column)
{
	for (int i = 0; i < *row; i++)
	{
		for (int j = 0; j < *column; j++)
			cout << setw(3) << deck[i][j];
		cout << endl;
	}
	cout << endl << endl;
}