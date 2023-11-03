#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include <cassert>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <cstring>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    /*
    cout.put('A').put('\n');

    int x, y;
    cout << "Введите два целых числа: ";
    cin >> x >> y;
    cout << x << " + " << y << " = " << (x + y) << endl;

    int grade, highestGrade = -1;
    cout << "Введите оценку: ";
    while (cin >> grade)
    {
        if (grade > highestGrade)
            highestGrade = grade;
        cout << "Введите оценку: ";
    }
    cout << "\n\nСамая высокая оценка: " << highestGrade << endl;

    char c;
    cout << cin.eof() << "\nВведите предложение:\n";
    while ((c = cin.get()) != EOF)
        cout.put(c);
    cout << endl << c;
    cout << endl << cin.eof();
    */

    const int SIZE = 80;
    char buffer1[SIZE], buffer2[SIZE], buffer3[SIZE];
    cout << cin.eof() << "\nВведите предложение:\n";
    cin.getline(buffer3, SIZE);
    cout << "\nСтрока через cin.getline:\n" << buffer3 << endl << endl;
    cout << cin.eof() << "\nВведите предложение:\n";
    cin >> buffer1;
    cout << "\nСтрока через cin:\n" << buffer1 << endl << endl;
    cin.get(buffer2, SIZE);
    cout << "\nСтрока через cin.get:\n" << buffer2 << endl << endl;


    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}