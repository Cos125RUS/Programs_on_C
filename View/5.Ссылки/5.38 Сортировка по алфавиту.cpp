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

bool comparison(char* city1, char* city2)
{
    int first = *city1, second = *city2;
    
    if (first != second) return first > second;
	else return comparison(city1 + 1, city2 + 1);
};

void sort(char citys[10][15], const int * size)
{
    char changing[15] = "";

    for (int i = 0; i < *size - 1; i++)
        for (int j = 0; j < *size - 1 - i; j++)
        {
            if (comparison(citys[j], citys[j+1]))
            {
                strcpy_s(changing, citys[j]);
                strcpy_s(citys[j], citys[j + 1]);
                strcpy_s(citys[j + 1], changing);
            }
        }
};

void print(char citys[10][15], const int* size)
{
    for (int i = 0; i < *size; i++)
        cout << citys[i] << endl;
};

int main()
{
    setlocale(LC_ALL, "Russian");

    const int size = 10;
    char citys[size][15] = { "Vladivostok", "Moskov", "London", "NewYork", "Istanbul", "Berin", "Madrid", "Paris", "Rome", "Vienna" };

    sort(citys, &size);
    print(citys, &size);



    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}