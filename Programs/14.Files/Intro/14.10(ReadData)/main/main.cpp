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

void outputLine(ostream& output, const clientData& c)
{
    output << setiosflags(ios::left) << setw(10) << c.accountNumber
        << setw(16) << c.lastName << setw(11) << c.firstName << setprecision(2)
        << resetiosflags(ios::left) << setw(9) << setiosflags(ios::fixed | ios::showpoint) 
        << c.balance << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    ifstream inCredit("credit.dat", ios::in);

    if (!inCredit)
    {
        cerr << "Невозможно открыть файл\n";
        exit(1);
    }

    cout << setiosflags(ios::left) << setw(10) << "Счёт"
        << setw(16) << "Фамилия" << setw(11) << "Имя"
        << resetiosflags(ios::left) << setw(10) << "Баланс\n";

    clientData client;

    inCredit.read(reinterpret_cast<char*>(&client), sizeof(clientData));

    while (inCredit && !inCredit.eof())
    {
        if (client.accountNumber != 0)
            outputLine(cout, client);
        inCredit.read(reinterpret_cast<char*>(&client), sizeof(clientData));
    }




    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}