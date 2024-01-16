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
#include "DataBase.h"

using namespace std;

DataBase::DataBase(const char* oldMasterFileName, const char* transactionFileName, const char* newMasterFileName)
{
	ifstream inOldMaster(oldMasterFileName, ios::in);
	ifstream inTransaction(transactionFileName, ios::in);
	ofstream outNewMaster(newMasterFileName, ios::out);
}

void DataBase::readOldMaster()
{
    if (!inOldMaster)
    {
        cerr << "Невозможно открыть файл\n";
        exit(1);
    }

    int accountNum;
    char name[30];
    double currentBalance;

    inOldMaster >> accountNum >> name >> currentBalance;
    while (!inOldMaster.eof())
    {
        cout << setiosflags(ios::left) << setw(10) << accountNum
            << setw(12) << name << setw(7) << setprecision(2)
            << resetiosflags(ios::left) << currentBalance << endl;
        inOldMaster >> accountNum >> name >> currentBalance;
    }
    inOldMaster.clear();
    inOldMaster.seekg(0);
}

void DataBase::readTrans()
{
    if (!inTransaction)
    {
        cerr << "Невозможно открыть файл\n";
        exit(1);
    }

    int accountNum;
    double dollarAmount;

    inTransaction >> accountNum >> dollarAmount;
    while (!inTransaction.eof())
    {
        cout << setiosflags(ios::left) << setw(10) << accountNum
            << setw(7) << setprecision(2)
            << resetiosflags(ios::left) << dollarAmount << endl;
        inTransaction >> accountNum >> dollarAmount;
    }
    inTransaction.clear();
    inTransaction.seekg(0);
}

void DataBase::writeNewMaster(const ClientData& clientData)
{
    outNewMaster.open("newmaster.dat", ios::app);
    if (!outNewMaster)
    {
        cerr << "Не получилось открыт файл\n";
        exit(1);
    }

    outNewMaster << clientData.accountNum << ' ' << clientData.name << ' ' << clientData.currentBalance << '\n';
    outNewMaster.close();
}