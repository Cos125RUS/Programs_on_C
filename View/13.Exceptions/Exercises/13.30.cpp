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

class MyException
{
public:
	MyException() : message("Базовый класс\n") {}
	MyException(const char* m) { message = m; }
	const char* what() const { return message; }
private:
	const char* message;
};

class ChildMyException : public MyException
{
public:
	ChildMyException() : MyException("Производный класс\n") {}
};

int main()
{
	setlocale(LC_ALL, "Russian");


	try
	{
		throw ChildMyException();
		//throw MyException();
	}
	catch (MyException exception)
	{
		cout << "Возникло исключение: " << exception.what() << endl;
	}






	cout << "\n\n\n\n\n\n\n\n\n\n";

	return 0;
}