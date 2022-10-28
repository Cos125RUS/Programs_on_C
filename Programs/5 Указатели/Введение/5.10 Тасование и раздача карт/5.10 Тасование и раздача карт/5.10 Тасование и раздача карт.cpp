#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

using namespace std;

void shuffle(int[][13]);
void deal(const int[][13], const char* [], const char* []);

int main()
{
	setlocale(LC_ALL, "Russian");

	const char* suit[4] = { "Черви", "Буби", "Трефы", "Пики" };
	const char* face[13] = { "Туз", "Двойка", "Тройка", "Четвёрка", "Пятёрка", "Шестёрка", "Семёрка",
							"Восьмёрка", "Девятка", "Десятка", "Валет", "Дама", "Король" };

	int deck[4][13] = { 0 };

	srand(time(0));

	shuffle(deck);
	deal(deck, face, suit);



	cout << "\n\n\n\n\n\n\n\n\n\n";

	return 0;
}

void shuffle(int wDeck[][13])
{
	int row, column;

	for (int card = 1; card <= 52; card++)
	{
		do {
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);
		wDeck[row][column] = card;
	}
}

void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[])
{
	for (int card = 1; card <= 52; card++)
		for (int row = 0; row <= 3; row++)
			for (int column = 0; column <= 12; column++)
				if (wDeck[row][column] == card)
					cout << setw(10) << setiosflags(ios::right) << wFace[column] 
						<< " масти " << setiosflags(ios::left) << wSuit[row] 
						<< setw(5) << (card % 2 == 0 ? '\n' : '\t');
}