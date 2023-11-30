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
#include <memory>

using namespace std;

class Test
{
public:
    Test() 
	{ 
		id = ++count;
		cout << "Constructor " << id << endl;
	}
	Test(const char* name) 
	{ 
		id = ++count;
		cout << "Constructor " << name << endl; 
	}
    ~Test() { cout << "Destructor " << id << endl; }
private:
	static int count;
	int id;
};

int Test::count = 0;

int main()
{
    setlocale(LC_ALL, "Russian");

	try
	{
		auto_ptr<Test> t1(new Test());
		auto_ptr<Test> t2(new Test());
		Test* t3 = new Test();
		Test t4("t4");
		throw exception();
		Test t5("t5");
	}
	catch (exception e)
	{
		cout << "----------------------------------------\nCatch";
		e.what();
	}






    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}