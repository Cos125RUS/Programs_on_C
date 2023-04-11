#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include "SavingsAccount.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    SavingsAccount* ac1 = new SavingsAccount(2000.0);
    SavingsAccount* ac2 = new SavingsAccount(3000.0);
    SavingsAccount::modifyInterestRate(0.03);
    ac1->calculateMonthlyInterest();
    ac2->calculateMonthlyInterest();
    ac1->printBalance();
    ac2->printBalance();
    SavingsAccount::modifyInterestRate(0.04);
    ac1->calculateMonthlyInterest();
    ac2->calculateMonthlyInterest();
    ac1->printBalance();
    ac2->printBalance();






    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}