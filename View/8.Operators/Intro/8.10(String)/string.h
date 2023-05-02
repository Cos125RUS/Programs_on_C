#pragma once

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

class String
{
	friend ostream& operator<<(ostream&, const String&);
	friend istream& operator>>(istream&, String&);

public:
	String(const char* = "");
	String(const String&);
	~String();
	const String& operator=(const String&);
	const String& operator+=(const String&);
	bool operator!() const;
	bool operator==(const String&) const;
	bool operator<(const String&) const;
	bool operator!=(const String& right) const {return *this == right;}
	bool operator>(const String& right) const { return right < *this; }
	bool operator<=(const String& right) const { return right < *this; }
	bool operator>=(const String& right) const { return *this < right; }
	char& operator[](int);
	const char& operator[](int)const;
	String operator()(int, int);
	int getLength()const;

private:
	int length;
	char* sPtr;
	void setString(const char*);
};

