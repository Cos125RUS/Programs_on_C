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

int getAccount(const char* const prompt)
{
    int account;

    do {
        cout << prompt << " (1 - 100): ";
        cin >> account;
    } while (account < 1 || account > 100);

    return account;
}

enum Choices { TEXTFILE = 1, UPDATE, NEW, DELETE, END };

int enterChoice()
{
    cout << "\nВведите ваш выбор:\n"
        << "1 - Сохранить\n"
        << "2 - Изменить\n"
        << "3 - Добавить\n"
        << "4 - Удалить\n"
        << "5 - Выход\n>> ";
    
    int menuChoice;
    cin >> menuChoice;
    return menuChoice;
}

void textFile(fstream& readFromFile)
{
    ofstream outPrintFile("print.txt", ios::out);

    if (!outPrintFile)
    {
        cerr << "Невозможно открыть файл\n";
        exit(1);
    }

    outPrintFile << setiosflags(ios::left) << setw(10) << "Счёт"
        << setw(16) << "Фамилия" << setw(11) << "Имя"
        << resetiosflags(ios::left) << setw(10) << "Баланс\n";
    readFromFile.seekg(0);

    clientData client;
    readFromFile.read(reinterpret_cast<char*>(&client), sizeof(clientData));

    while (!readFromFile.eof())
    {
        if (client.accountNumber != 0)
            outputLine(outPrintFile, client);

        readFromFile.read(reinterpret_cast<char*>(&client), sizeof(clientData));
    }
}

void updateRecord(fstream& updateFile)
{
    int account = getAccount("Введите счёт для обновления");
    updateFile.seekg((account - 1) * sizeof(clientData));
    
    clientData client;
    updateFile.read(reinterpret_cast<char*>(&client), sizeof(clientData));

    if (client.accountNumber != 0)
    {
        outputLine(cout, client);
        cout << "Введите расход (+) или доплату (-): ";

        double transaction;
        cin >> transaction;
        client.balance += transaction;
        outputLine(cout, client);
        updateFile.seekp((account - 1) * sizeof(clientData));
        updateFile.write(reinterpret_cast<const char*>(&client), sizeof(clientData));
    }
    else
        cerr << "Счёт №" << account << " нет информации.\n";
}

void newRecord(fstream &insertInFile)
{
    int account = getAccount("Введите новый номер счёта: ");

    insertInFile.seekg((account - 1) * sizeof(clientData));

    clientData client;
    insertInFile.read(reinterpret_cast<char*>(&client), sizeof(clientData));

    if (client.accountNumber != 0)
    {
        cout << "Введите фамилию, имя, баланс\n>> ";
        cin >> client.lastName >> client.firstName >> client.balance;
        client.accountNumber = account;
        insertInFile.seekp((account - 1) * sizeof(clientData));
        insertInFile.write(reinterpret_cast<const char*>(&client), sizeof(clientData));
    }
    else
        cerr << "Счёт №" << account << " уже существует\n";
}

void deleteRecord(fstream& deleteFromFile)
{
    int account = getAccount("Введите счёта для удаления: ");

    deleteFromFile.seekg((account - 1) * sizeof(clientData));

    clientData client;
    deleteFromFile.read(reinterpret_cast<char*>(&client), sizeof(clientData));

    if (client.accountNumber != 0)
    {
        clientData blankClient = { 0, "", "", 0.0 };

        deleteFromFile.seekp((account - 1) * sizeof(clientData));
        deleteFromFile.write(reinterpret_cast<const char*>(&blankClient), sizeof(clientData));

        cout << "Счёт №" << account << " удалён\n";
    }
    else
        cerr << "Счёт №" << account << " пуст\n";
}


int main()
{
    setlocale(LC_ALL, "Russian");

    fstream inOutCredit("credit.dat", ios::in | ios::out);

    if (!inOutCredit)
    {
        cerr << "Невозможно открыть файл\n";
        exit(1);
    }

    int choice;

    while ((choice = enterChoice()) != END)
    {
        switch (choice)
        {
        case TEXTFILE:
            textFile(inOutCredit);
            break;
        case UPDATE:
            updateRecord(inOutCredit);
            break;
        case NEW:
            newRecord(inOutCredit);
            break;
        case DELETE:
            deleteRecord(inOutCredit);
            break;
        default:
            cerr << "Некорректный ввод\n";
            break;
        }
        inOutCredit.clear();
    }
    




    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}