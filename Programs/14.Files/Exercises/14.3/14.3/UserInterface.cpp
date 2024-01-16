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
#include "UserInterface.h"

using namespace std;

UserInterface::UserInterface(int i) 
{

}

bool UserInterface::choice()
{
    char c;
    cout << "Enter new line (y/n): ";
    cin >> c;
    if (c == 'y')
        return true;
    return false;
}

ClientData UserInterface::enterData()
{
    const int SIZE = 30;
    int accountNum;
    char name[SIZE];
    double currentBalance;
    ClientData clientData;

    cout << "Enter account number: ";
    cin >> clientData.accountNum;
    cin.get();
    cout << "Enter the name: ";
    cin.getline(clientData.name, SIZE);
    cout << "Enter Current Balance: ";
    cin >> clientData.currentBalance;
    cout << endl;

    return clientData;
}