#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
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
#include "clntdata.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    ofstream outCredit("credit.dat", ios::binary);

    if (!outCredit)
    {
        cerr << "Невозможно открыть файл\n";
        exit(1);
    }

    clientData blankClient = { 0, "", "", 0.0 };

    for (int i = 0; i < 100; i++)
        outCredit.write(reinterpret_cast<const char*>(&blankClient), sizeof(clientData));

    cout << "Введите номер счёта" << "(от 1 до 100, 0 - для окончания ввода)\n>> ";

    clientData client;
    cin >> client.accountNumber;

    while (client.accountNumber > 0 && client.accountNumber <= 100)
    {
        cout << "Введите фамилию, имя, баланс\n>> ";
        cin >> client.lastName >> client.firstName >> client.balance;

        outCredit.seekp((client.accountNumber - 1) * sizeof(clientData));

        cout << "\nВведите номер счёта\n>> ";
        cin >> client.accountNumber;
    }




    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}