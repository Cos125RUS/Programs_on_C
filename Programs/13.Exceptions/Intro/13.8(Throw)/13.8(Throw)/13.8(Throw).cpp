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

using namespace std;

void throwException()
{
	try
	{
		cout << "throwException function\n";
		throw exception();
	}
	catch (exception e)
	{
		cout << "Exception generate in throwException\n";
		throw;
	}
	cout << "This not writing";
}

int main()
{
    setlocale(LC_ALL, "Russian");

	try
	{
		throwException();
		cout << "This not writing";
	}
	catch (exception e)
	{
		cout << "Exception generate in main\n";
	}

	cout << "main after generated exception\n";






    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}