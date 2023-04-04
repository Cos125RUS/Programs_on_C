#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

using namespace std;

void function1(int);
void function2(int);
void function3(int);

int main()
{
	setlocale(LC_ALL, "Russian");


	void (*f[3])(int) = { function1,function2,function3 };
	int choice;

	cout << "Enter the number 0 to 2, or 3 for the end: ";
	cin >> choice;

	while (choice >= 0 && choice < 3)
	{
		(*f[choice])(choice);
		cout << "Enter the number 0 to 2, or 3 for the end: ";
		cin >> choice;
	}

	cout << "\nEnd of the programe";




	cout << "\n\n\n\n\n\n\n\n\n\n";

	return 0;
}

void function1(int a)
{
	cout << "You arr enter the " << a << " becouse use Function 1" << endl << endl;
}

void function2(int a)
{
	cout << "You arr enter the " << a << " becouse use Function 2" << endl << endl;
}

void function3(int a)
{
	cout << "You arr enter the " << a << " becouse use Function 3" << endl << endl;
}