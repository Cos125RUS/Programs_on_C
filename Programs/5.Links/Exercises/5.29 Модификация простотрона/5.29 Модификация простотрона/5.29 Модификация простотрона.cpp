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

int run = 0;
bool flag = true,
     showDump = false;

void hello();
void prosto(int[], int*, int*, int*, int*, int*);
void dump(int[], int*, int*, int*, int*, int*);
void enterComand(int[], int*, int*);

int main()
{
	setlocale(LC_ALL, "Russian");

	int memory[100] = { 0 };
	int accumulator = 0,
		counter = 0,
		instructionRegister = 0,
		operationCode = 0,
		operand = 0;


	hello();
	while (memory[counter] != -99999 )
	{
		enterComand(memory, &counter, &instructionRegister);
		prosto(memory, &accumulator, &counter, &instructionRegister, &operationCode, &operand);
	}
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
}

void prosto(int memory[], int* accumulator, int* counter, int* instructionRegister, int* operationCode, int* operand)
{
	void findComand(int[], const int*, const int*, int*, int*);

	cout << "\n\n";

	while (memory[*counter] != -99999 && flag)
	{
		*instructionRegister = memory[*counter];
		*operationCode = *instructionRegister / 100;
		*operand = *instructionRegister % 100;
		findComand(memory, operationCode, operand, counter, accumulator);
		if (showDump)
			dump(memory, accumulator, counter, instructionRegister, operationCode, operand);
		++(*counter);
	}
	
	flag = true;
	cout << "\n\n";
}

void findComand(int memory[], const int* operationCode, const int* operand, int* counter, int* accumulator)
{
	switch (*operationCode)
	{
	case 10:
		cout << "\nВвод числа: ";
		cin >> memory[*operand];
		break;

	case 11:
		cout << "\nВывод значения: " << memory[*operand] << endl;
		break;

	case 12:
		char enter[100];
		cout << "\nВвод строки: ";
		cin >> enter;
		memory[*operand] = strlen(enter);
		for (int i = 0; i < memory[*operand]; i++)
			memory[*operand + 1 + i] = enter[i];
		break;

	case 13:
		cout << "\nВывод строки: ";
		for (int i = 0; i < memory[*operand]; i++)
			cout << static_cast<char>(memory[*operand + 1 + i]);
		break;

	case 20:
		*accumulator = memory[*operand];
		break;

	case 21:
		memory[*operand] = *accumulator;
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
			cout << "\n\n*** Попытка деления на 0 ***\n*** Выполнение программы завершено ненормально ***\n";
			flag = false;
		}
		else
			*accumulator = memory[*operand] / *accumulator;
		break;

	case 33:
		*accumulator *= memory[*operand];
		break;

	case 34:
		if (*accumulator == 1);
		else
			if (memory[*operand] == 0) *accumulator = 1;
			else
				if (memory[*operand] > 0)
					if (memory[*operand] > 1)
					{
						int i = memory[*operand];
						int j = *accumulator;
						while (i-- > 1)
							*accumulator *= j;
					}
					else
					{
						// дробные степени (только с вещественными числами)
					}
				else
				{
					int i = -memory[*operand];
					int j = *accumulator;
					while (i-- > 1)
						*accumulator *= j;
					*accumulator = 1 / *accumulator;
				}
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
		cout << "\n\n*** Программа выполнена ***";
		flag = false;
		break;

	case 44:
		if (*operand == 1)
		{
			cout << "\n\n*** Включен режим отладки ***";
			showDump = true;
		}
		else
			if (*operand == 0)
			{
				cout << "\n\n*** Режим отладки отключён ***";
				showDump = false;
			}
			else
				cout << "*** Неизвестная команда! ***\nПроверьте <operand>"
				<< setw(8) << *operand << endl;
		break;

	default:
		cout << "*** Неизвестная команда! ***\nПроверьте <operationCode>" 
			<< setw(10) << *operationCode << endl;
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
		if (*accumulator < 10)  cout << "000";
		else
			if (*accumulator < 100)  cout << "00";
			else
				if (*accumulator < 1000)  cout << "0";
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
	else cout << setw(4) << ' ';
	if (*instructionRegister == 0) cout << "0000\n";
	else cout << *instructionRegister << endl;
	cout << "operationCode" << setw(14) << ' ';
	if (*operationCode < 10) cout << '0' << *operationCode << endl;
	else cout << *operationCode << endl;
	cout << "operand" << setw(20) << ' ';
	if (*operand < 10) cout << '0' << *operand << endl;
	else cout << *operand << endl;

	cout << "\nПАМЯТЬ\n  ";

	cout << setw(2) << ' ';
	for (int i = 0; i < 10; i++)
		cout << setw(4) << i << setw(3) << ' ';

	for (int i = 0; i < 100; i++)
	{
		if (i == 0) cout << "\n00";

		if (i % 10 == 0 && i > 0)
			cout << setw(2) << i;

		if (memory[i] >= 0)
		{
			cout << "  +";

			if (memory[i] == 0) cout << "0000";
			else
				if (memory[i] < 10) cout << "000" << memory[i];
				else
					if (memory[i] < 100) cout << "00" << memory[i];
					else
						if (memory[i] < 1000) cout << "0" << memory[i];
						else cout << memory[i];
		}
		else cout << ' ' << memory[i];

		if ((i + 1) % 10 == 0) cout << endl;
	}
}

void enterComand(int memory[], int* counter, int* instructionRegister)
{
	run = *counter;

	do {
		if (*counter < 10) cout << "0";
		cout << *counter << '\t' << "?" << '\t';
		cin >> *instructionRegister;
		memory[*counter] = *instructionRegister;
		++(*counter);
	} while (*instructionRegister != -99999 && *instructionRegister != +4300);

	*counter = run;

	cout << "\n\n";

	const char* string[] = { "Загрузка программы закончена",
		"Начинается выполнение программы" };

	for (int i = 0; i < 2; i++)
	{
		cout << "*** ";
		for (int j = 0; j < strlen(string[i]); j++)
			cout << string[i][j];
		cout << " ***\n";
	}
}