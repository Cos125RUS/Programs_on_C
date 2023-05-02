#include "string.h"
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

String::String(const char* s) :length(strlen(s))
{
	cout << "Conversion constructor: " << s << endl;
	setString(s);
}

String::String(const String& copy) : length(copy.length)
{
	cout << "Copy constructor: " << copy.sPtr << endl;
	setString(copy.sPtr);
}

String::~String()
{
	cout << "Distructor: " << sPtr << endl;
	delete[] sPtr;
}

const String& String::operator=(const String& right)
{
	cout << "operator= called\n";
	if (&right != this) {
		delete[] sPtr;
		length = right.length;
		setString(right.sPtr);
	}
	else
		cout << "Attemped assigment of a String to itself\n";

	return *this;
}

const String& String::operator+=(const String& right)
{
	char* tempPtr = sPtr;
	length += right.length;
	sPtr = new char[length + 1];
	assert(sPtr != 0);
	strcpy_s(sPtr, length + 1, tempPtr);
	strcat_s(sPtr, length + 1, right.sPtr);
	delete[] tempPtr;
	return *this;
}

bool String::operator!()const { return length == 0; }

bool String::operator==(const String& right) const
{
	return strcmp(sPtr, right.sPtr) == 0;
}

bool String::operator<(const String& right) const
{
	return strcmp(sPtr, right.sPtr) < 0;
}

char& String::operator[](int subscript)
{
	assert(subscript >= 0 && subscript < length);
	return sPtr[subscript];
}

const char& String::operator[](int subscript) const
{
	(subscript >= 0 && subscript < length);
	return sPtr[subscript];
}

String String::operator()(int index, int subLength)
{
	assert(index >= 0 && index < length && subLength >= 0);
	
	int len;

	if ((subLength == 0) || (index + subLength > length))
		len = length - index;
	else
		len = subLength;

	char* tempPtr = new char[len + 1];
	assert(tempPtr != 0);

	strncpy_s(tempPtr, len + 1, &sPtr[index], len);
	tempPtr[len] = '\0';
	String tempString(tempPtr);
	delete[] tempPtr;

	return tempString;
}

int String::getLength()const { return length; }
void String::setString(const char* string2)
{
	sPtr = new char[length + 1];
	assert(sPtr != 0);
	strcpy_s(sPtr, length + 1, string2);
}

ostream& operator<<(ostream& output, const String& s)
{
	output << s.sPtr;
	return output;
}

istream& operator>>(istream& input, String& s)
{
	char temp[100]; 
	input >> setw(100) >> temp;
	s = temp;
	return input;
}