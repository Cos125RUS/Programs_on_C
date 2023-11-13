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
#include "Stack.h"

using namespace std;

template<class T>
void testStack(
    Stack<T>& theStack,
    T value,
    T increment,
    const char* stackName
)
{
    cout << "\nPush in " << stackName << endl;
    while (theStack.push(value))
    {
        cout << value << ' ';
        value += increment;
    }
    cout << "\nPop of " << stackName << endl;
    while (theStack.pop(value))
        cout << value << ' ';
}

int main()
{
    setlocale(LC_ALL, "Russian");

    Stack<double> doubleStack(5);
    Stack<int> intStack;

    /*
    double f = 1.1;
    while (doubleStack.push(f))
    {
        cout << f << ' ';
        f += 1.1;
    }

    cout << "Stack is full\n\n";

    while (doubleStack.pop(f))
        cout << f << ' ';

    cout << "Stack is clear\n\n";

    int i = 1;
    while (intStack.push(i))
        cout << i++ << ' ';

    cout << "Stack is full\n\n";

    while (intStack.pop(i))
        cout << i << ' ';

    cout << "Stack is clear\n\n";
    */

    testStack(doubleStack, 1.1, 1.1, "doubleStack");
    testStack(intStack, 1, 1, "intStack");



    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}