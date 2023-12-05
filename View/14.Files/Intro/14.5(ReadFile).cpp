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

enum RequestType {ZERO_BALANCE = 1, CREDIT_BALANCE, DEBIT_BALANCE, END};

int getRequest() 
{
    int request;
    do {
        cout << "\n>> ";
        cin >> request;
    } while (request < ZERO_BALANCE && request > END);
    return request;
}

bool shouldDisplay(int type, double balance)
{
    if (type == CREDIT_BALANCE && balance < 0)
        return true;
    if (type == DEBIT_BALANCE && balance > 0)
        return true;
    if (type == ZERO_BALANCE && balance == 0)
        return true;
    return false;
}

void outputLine(int acct, const char* const name, double bal) 
{
    cout << setiosflags(ios::left) << setw(10) << acct
        << setw(12) << name << setw(7) << setprecision(2)
        << resetiosflags(ios::left) << bal << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    ifstream inClientFile("client.dat", ios::in);

    if (!inClientFile)
    {
        cerr << "Невозможно открыть файл\n";
        exit(1);
    }

    int request, account;
    char name[30];
    double balance;

    cout << "Введите запрос\n"
        << " 1 - Список счетов с нулевым балансом\n"
        << " 2 - Список счетов с кредитным балансом\n"
        << " 3 - Список счетов с дебетовым балансом\n"
        << " 4 - Конец работы\n"
        << setiosflags(ios::fixed | ios::showpoint);

    //cout << setiosflags(ios::left) << setw(10) << "Счёт" << setw(13) 
      //  << "Имя" << "Баланс\n" << setiosflags(ios::fixed | ios::showpoint);
    
    request = getRequest();
    while (request != END)
    {
        switch (request)
        {
        case ZERO_BALANCE:
            cout << "\nСчета с нулевым балонсом:\n";
			break;
        case CREDIT_BALANCE:
            cout << "\nСчета с кредитным балонсом:\n";
            break;
        case DEBIT_BALANCE:
            cout << "\nСчета с дебетовым балонсом:\n";
            break;
        }
        inClientFile >> account >> name >> balance;
        while (!inClientFile.eof())
        {
            if (shouldDisplay(request, balance))
                outputLine(account, name, balance);
			inClientFile >> account >> name >> balance;
        }
        inClientFile.clear();
        inClientFile.seekg(0);
        request = getRequest();
    }

    cout << "\nКонец работы\n";
    
    /*while (inClientFile >> account >> name >> balance)
    {
        outputLine(account, name, balance);
    }*/





    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}