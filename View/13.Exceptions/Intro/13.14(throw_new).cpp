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

using namespace std;

void customNewHandler()
{
	cerr << "Вызвана CustomNewHandler";
	abort();
}

int main()
{
	setlocale(LC_ALL, "Russian");

	double* ptr[50];
	set_new_handler(customNewHandler);

	/*
	for (int i = 0; i < 50; i++)
	{
		ptr[i] = new double[50000000];
		cout << "Выделение памяти не удалось для ptr[" << i << "]\n";
	}*/

	try
	{

		for (int i = 0; i < 50; i++)
		{
			ptr[i] = new double[50000000];

			/*
			if (ptr[i] == 0)
			{
				cout << "Выделение памяти не удалось для ptr[" << i << "]\n";
				break;
			}
			else
			{
				cout << "Выделено 5000000 ячеек типа double для ptr[" << i << "]\n";
			}*/

			cout << "Выделение памяти не удалось для ptr[" << i << "]\n";
		}
	}
	catch (bad_alloc exception)
	{
		cout << "Возникло исключение: " << exception.what() << endl;
	}






	cout << "\n\n\n\n\n\n\n\n\n\n";

	return 0;
}