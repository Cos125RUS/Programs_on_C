#include "Point.h"
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

Point::Point(int a, int b) { setPoint(a, b); }

void Point::setPoint(int a, int b)
{
	x = a;
	y = b;
}

void Point::parseString(char line[], int size) 
{ 
	int b = getNum(line, &size, ',');
	int a = getNum(line, &size, '(');

	setPoint(a, b);
}

int Point::getNum(char line[], int *size, char sep) {
	int k = 0, num = 0;
	while (line[--*size] != sep) {
		if (line[*size] != ' ') {
			int n = line[*size] - '0';
			if (n < 0 || n > 9) {
				cin.clear(ios::failbit);
			}
			num += n * pow(10, k++);
		}
	}
	return num;
}

ostream& operator<<(ostream& output, const Point& p)
{
	if (!cin.fail()) 
		output << '(' << p.x << ", " << p.y << ')';

	return output;
}

istream& operator>>(istream& input, Point& p)
{
	char temp[20];
	int size = 0;
	char c;
	while ((c = cin.get()) != ')' && size < 20) {
		temp[size++] = c;
	}
	p.parseString(temp, size);

	return input;
}