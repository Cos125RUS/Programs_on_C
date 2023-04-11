#include "SavingsAccount.h"
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

using namespace std;

double SavingsAccount::annualInterestRate = 0;

void SavingsAccount::modifyInterestRate(double rate)
{
	if (rate > 0 && rate < 1)
		annualInterestRate = rate;
}


SavingsAccount::SavingsAccount(double balance)
{
	if (balance > 0)
		savingBalance = balance;
	else
		savingBalance = 0;
}

SavingsAccount::~SavingsAccount() {  }

void SavingsAccount::calculateMonthlyInterest()
{
	savingBalance += (savingBalance * annualInterestRate) / 12;
}

void SavingsAccount::printBalance()
{
	cout << "Balance = " << savingBalance << endl;
}

