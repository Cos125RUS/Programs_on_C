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
#include <csetjmp>
#include <exception>
#include <stdexcept>
#include <new>
#include <stdlib.h>
#include <memory>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    ofstream outClientFile("client.dat", ios::out);

    if (!outClientFile) {
        cerr << "Не получилось открыт файл\n";
        exit(1);
    }

    cout << "Введите счёт, имя и баланс\nВведите EOF для окончания ввода\n?";

    int account;
    char name[30];
    double balance;

    while (cin >> account >> name >> balance) {
        outClientFile << account << ' ' << name << ' ' << balance << '\n';
        cout << "?";
    }






    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}