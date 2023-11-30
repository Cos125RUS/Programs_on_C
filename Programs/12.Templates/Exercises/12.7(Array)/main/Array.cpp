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
	assert(ptr != 0);

	for (int i = 0; i < size; i++)
		ptr[i] = NULL;
}

template<class T>
Array<T>::Array(const Array& init) : size(init.size)
{
	ptr = new int[size];
	assert(ptr != 0);

	for (int i = 0; i < size; i++)
		ptr[i] = init.ptr[i];
}

template<class T>
Array<T>::~Array()
{
	delete[] ptr;
}

template<class T>
int Array<T>::getSize() const { return size; }

template<class T>
const Array<T>& Array<T>::operator=(const Array& right)
{
	if (&right != this) {
		if (size != right.size) {
			delete[] ptr;
			size = right.size;
			ptr = new T[size];
			assert(ptr != 0);
		}
		for (int i = 0; i < size; i++)
			ptr[i] = right.ptr[i];
	}

	return *this;
}

template<class T>
bool Array<T>::operator==(const Array& right) const
{
	if (size != right.size)
		return false;

	for (int i = 0; i < size; i++)
		if (ptr[i] != right.ptr[i])
			return false;

	return true;
}

template<class T>
T& Array<T>::operator[](int subscript)
{
	assert(0 <= subscript && subscript < size);

	return ptr[subscript];
}

template<class T>
const T& Array<T>::operator[](int subscript) const
{
	assert(0 <= subscript && subscript < size);

	return ptr[subscript];
}

template<class T>
istream& operator>>(istream& input, Array<T>& a)
{
	for (int i = 0; i < a.size; i++)
		input >> a.ptr[i];

	return input;
}

template<class T>
ostream& operator<<(ostream& output, const Array<T>& a)
{
	for (int i = 0; i < a.size; i++) {
		output << ' ' << a.ptr[i];
	}

	return output;
}