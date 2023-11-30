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

using namespace std;

void function3() throw (runtime_error)
{
    throw runtime_error("runtime_error in function3");
}

void function2() throw (runtime_error)
{
    function3();
}

void function1() throw (runtime_error)
{
    function2();
}
int main()
{
    setlocale(LC_ALL, "Russian");

	try
	{
		function1();
	}
	catch (exception e)
	{
		cout << e.what();
	}







    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}