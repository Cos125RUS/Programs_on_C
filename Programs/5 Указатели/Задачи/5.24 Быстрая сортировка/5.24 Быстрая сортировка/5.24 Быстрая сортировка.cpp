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

void fill_array(int[], const int*);
void print_array(int[], const int*);
void quick_sort(int[], int);

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(0));

	const int size = 10;

	int array[size] = { 0 };

	fill_array(array, &size);
	print_array(array, &size);
	quick_sort(array, size);
	print_array(array, &size);


	cout << "\n\n\n\n\n\n\n\n\n\n";

	return 0;
}

void fill_array(int array[], const int* n)
{
	for (int i = 0; i < *n; i++)
		array[i] = 1 + rand() % 99;
}

void print_array(int array[], const int* n)
{
	for (int i = 0; i < *n; i++)
	{
		if (i % 10 == 0 && i != 0)
			cout << endl;
		cout << setw(5) << array[i];
	}
	cout << endl << endl;
}

void quick_sort(int array[], int n)
{
	int partition(int[], int);

	if (n > 1)
	{
		int position = partition(array, n);

		quick_sort(array, position);
		quick_sort(&array[position + 1], n - (position + 1));
	}
}

int partition(int array[], int n)
{
	int first = 0,
		lust = n;

	while (first != lust)
	{
		for (int i = lust - 1; i >= first; i--)
			if (array[i] <= array[first])
			{
				int c = array[i];
				array[i] = array[first];
				array[first] = c;
				lust = i;
			}

		for (int i = first + 1; i <= lust; i++)
			if (array[i] >= array[lust])
			{
				int c = array[i];
				array[i] = array[lust];
				array[lust] = c;
				first = i;
			}
	}

	return first;
}