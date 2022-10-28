#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void copy1(char*, const char*);
void copy2(char*, const char*);

int main()
{
	setlocale(LC_ALL, "Russian");

	int b[] = { 10,20,30,40 }, i, offset;
	int* bPtr = b;

	cout << "Массив b, распечатанный с обозначением индекса массива\n";

	for (i = 0; i < 4; i++)
		cout << "b[" << i << "] = " << b[i] << endl;

	cout << "\nУказатель/смещение, где указатель - имя массива\n";

	for (offset = 0; offset < 4; offset++)
		cout << "*(b + " << offset << ") = " << *(b + offset) << endl;

	cout << "\nНотации индекса указателя\n";

	for (i = 0; i < 4; i++)
		cout << "bPtr[" << i << "] = " << bPtr[i] << endl;

	cout << "\nНотации указатель/смещения\n";

	for (offset = 0; offset < 4; offset++)
		cout << "*(bPtr + " << offset << ") = " << *(bPtr + offset) << endl << endl << endl;

	//----------------------------------------------------------------------------------

	char string1[10], string2[] = "Hello",
		string3[10], string4[] = "Good bye";

	copy1(string1, string2);
	cout << "string1 = " << string1 << endl;

	copy2(string3, string4);
	cout << "string3 = " << string3 << endl;




	cout << "\n\n\n\n\n\n\n\n\n\n";

	return 0;
}

void copy1(char* s1, const char* s2)
{
	for (int i = 0; (s1[i] = s2[i]) != '\0'; i++);
}

void copy2(char* s1, const char* s2)
{
	for (; (*s1 = *s2) != '\0'; s1++, s2++);
}
