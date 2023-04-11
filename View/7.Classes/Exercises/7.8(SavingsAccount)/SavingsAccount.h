#pragma once
class SavingsAccount
{
public:
	SavingsAccount(double);
	~SavingsAccount();

	void calculateMonthlyInterest();
	void printBalance();

	static void modifyInterestRate(double);
private:
	//double balance;
	double savingBalance;

	static double annualInterestRate;
};

