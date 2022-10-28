#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void bubble(int[], const int, bool(*)(int, int));
bool ascending(int, int);
bool descending(int, int);

int main()
{
	setlocale(LC_ALL, "Russian");

	const int arraySize = 10;
	int a[arraySize] = { 2,6,4,8,10,12,89,68,45,37 };
	int i, order;

	cout << "Enter 1 for ascending sort,\n"
		<< "Enter 2 for dissending sort: ";
	cin >> order;

	cout << "\n\nЭлементы данных в исходном порядке\n";

	for (i = 0; i < arraySize; i++)
		cout << setw(4) << a[i];

	if (order == 1)
	{
		bubble(a, arraySize, ascending);
		cout << "\n\nAscending sort: \n";
	}
	else
	{
		bubble(a, arraySize, descending);
		cout << "\n\nDescending sort: \n";
	}

	for (i = 0; i < arraySize; i++)
		cout << setw(4) << a[i];




	cout << "\n\n\n\n\n\n\n\n\n\n";

	return 0;
}

void bubble(int array[], const int size, bool(*compare)(int, int))
{
	void swap(int* const, int* const);

	for (int pass = 0; pass < size - 1; pass++)
		for (int j = 0; j < size - 1; j++)
			if ((*compare)(array[j], array[j + 1]))
				swap(&array[j], &array[j + 1]);
}

void swap(int* const element1Ptr, int* const element2Ptr)
{
	int hold = *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = hold;
}

bool ascending(int a, int b)
{
	return b < a;
}

bool descending(int a, int b)
{
	return b > a;
}