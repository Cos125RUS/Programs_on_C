#include "array.h"
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

using namespace std;

template<class T>
Array<T>::Array(int arraySize)
{
	size = (arraySize > 0 ? arraySize : 10);
	ptr = new T[size];
}