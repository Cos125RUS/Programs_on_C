#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include <string.h>
#include <errno.h>

using namespace std;

void hello();
void prosto(int[], int*, int*, int*, int*, int*);
void dump(int[], int*, int*, int*, int*, int*);
void enterComand(int[], int*, int*);

int main()
{
	setlocale(LC_ALL, "Russian");

	int memory[100] = { 0 };
	int accumulator = +0000,
		counter = 00,
		instructionRegister = +0000,
		operationCode = 00,
		operand = 00;


	hello();
	enterComand(memory, &counter, &instructionRegister);
//	dump(memory, &accumulator, &counter, &instructionRegister, &operationCode, &operand);
	prosto(memory, &accumulator, &counter, &instructionRegister, &operationCode, &operand);
	dump(memory, &accumulator, &counter, &instructionRegister, &operationCode, &operand);





	cout << "\n\n\n\n\n\n\n\n\n\n";

	return 0;
}

void hello()
{
	const char* string[] = { "Добро пожаловать в Простотрон!",
		"Пожалуйста, вводите по одной команде вашей программы.",
		"Я буду печатать номера ячеек и знак(?)",
		"После этого вы можете ввести слово в эту ячейку.",
		"Введите номер - 99999 в конце ввода программы." };

	for (int i = 0; i < 5; i++)
	{
		cout << "*** ";
		for (int j = 0; j < strlen(string[i]); j++)
			cout << string[i][j];
		cout << " ***\n";
	}
	cout << "\n\n";

	//	cout << "*** Добро пожаловать в Простотрон! ***\n\n"
	//		<< "*** Пожалуйста, вводите по одной команде вашей программы ***\n"
	//		<< "*** Я буду печатать номера ячеек и знак (?) ***\n"
	//		<< "*** После этого вы можете ввести слово в эту ячейку. ***\n"
	//		<< "*** Введите номер -99999 в конце ввода программы. ***\n\n";
}

void prosto(int memory[], int* accumulator, int* counter, int* instructionRegister, int* operationCode, int* operand)
{
	void findComand(int[], const int*, const int*, int*, int*);

	cout << "\n\n\n";

	while (memory[*counter] != -99999 && *counter < 100)
	{
		*instructionRegister = memory[*counter];
		*operationCode = *instructionRegister / 100;
		*operand = *instructionRegister % 100;
		findComand(memory, operationCode, operand, counter, accumulator);
		++(*counter);
	}
	cout << "\n\n\n";
}

void findComand(int memory[], const int* operationCode, const int* operand, int* counter, int* accumulator)
{
	switch (*operationCode)
	{
	case 10:
		cout << "\nВвод: ";
		cin >> memory[*operand];
		break;

	case 11:
		cout<< "\nВывод: " << memory[*operand];
	break; 
	
	case 20:
		*accumulator = memory[*operand];
		break;

	case 21:
		memory[*operand]  = *accumulator;
		break;

	case 30:
		*accumulator += memory[*operand];
		break;

	case 31:
		*accumulator -= memory[*operand];
		break;

	case 32:
		if (*accumulator == 0) 
		{
			cout << "\n\n*** Попытка деления на 0 ***\n*** Выполнение простотрона завершено ненормально ***\n";
			*counter = 100;
		}
		else 
			*accumulator = memory[*operand] / *accumulator;
		break;

	case 33:
		*accumulator *= memory[*operand];
		break;

	case 40:
		*counter = *operand;
		break;

	case 41:
		if (*accumulator < 0)
			*counter = *operand;
		break;

	case 42:
		if (*accumulator == 0)
			*counter = *operand;
		break;

	case 43:
		*accumulator = 0;
		cout << "*** Простотрон закончил работу ***";
		break;

	default:
		cout << "*** Неизвестная команда! ***\noperationCode" << setw(10) << operationCode;
		break;
	}
}

void dump(int memory[], int* accumulator, int* counter, int* instructionRegister, int* operationCode, int* operand)
{
	cout << "\n\nРЕГИСТР\n" << "accumulator";
	if (*accumulator == 0) cout << setw(19) << "+0000\n";
	else
	{
		if (*accumulator > 0) cout << setw(14) << '+';
		else cout << setw(13) << ' ';
		cout << *accumulator << endl;
	}
	if (*counter < 100)
	{
		cout << "counter" << setw(20) << ' ';
		if (*counter < 10) cout << '0' << *counter << endl;
		else cout << *counter << endl;
	}
	else cout << "counter" << setw(22) << *counter << endl;
	cout << "instructionRegister";
	if (*instructionRegister != -99999) cout << setw(6) << '+';
	else cout << setw(5) << ' ';
	if (*instructionRegister == 0) cout << "0000\n";
	else cout << *instructionRegister << endl;
	cout << "operationCode" << setw(13) << ' ';
	if (*operationCode == 0) cout << '0' << *operationCode << endl;
	else cout << ' ' << *operationCode << endl;
	cout << "operand" << setw(19) << ' ';
	if (*operand == 0) cout << '0' << *operand << endl;
	else cout << ' ' << *operand << endl;

	cout << "\nПАМЯТЬ\n  ";

	for (int i = 0; i < 10; i++)
		cout << setw(6) << i;

	for (int i = 0; i < 100; i++)
	{
		if (i == 0) cout << "\n00";

		if (i % 10 == 0 && i > 0)
			cout << setw(2) << i;

		 if (memory[i] >= 0) 
		 {
			 cout << " +";

			 if (memory[i] == 0) cout << "0000";
			 else
				 if (memory[i] < 10) cout << "000" << memory[i];
				 else
					 if (memory[i] < 100) cout << "00" << memory[i];
					 else
						 if (memory[i] < 1000) cout << "0" << memory[i];
						 else cout << memory[i];
		 }
		 else cout << memory[i];

		if ((i + 1) % 10 == 0) cout << endl;
	}
}

void enterComand(int memory[], int* counter, int* instructionRegister)
{
	do {
		if (*counter < 10) cout << "0";
		cout << *counter << '\t' << "?" << '\t';
		cin >> *instructionRegister;
		memory[*counter] = *instructionRegister;
		++(*counter);
	} while (*instructionRegister != -99999);

	*counter = 0;

	cout << "\n\n";

	const char* string[] = { "Загрузка программы закончена",
		"Начинается выполнение программы"};

	for (int i = 0; i < 2; i++)
	{
		cout << "*** ";
		for (int j = 0; j < strlen(string[i]); j++)
			cout << string[i][j];
		cout << " ***\n";
	}
	cout << "\n\n";
}