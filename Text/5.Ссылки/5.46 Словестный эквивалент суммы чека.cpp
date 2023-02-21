#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include <string.h>
#include <errno.h>
#include <ctype.h>

using namespace std;

void protect(char* cheque, double* sum, int thousand, int integer, int fractional)
{
    int star = 5;
    int a = *sum;
    while (a > 9)
    {
        a /= 10;
        star--;
    }

    if (thousand > 0)
        star--;

    int i = 0;
    for (i, star; star > 0; i++, star--)
        cheque[i] = '*';

    if (thousand > 0)
    {
        if (thousand > 9)
        {
            cheque[i++] = thousand / 10 + 48;
            cheque[i++] = thousand % 10 + 48;
        }
        else cheque[i++] = thousand + 48;

        cheque[i++] = ',';
    }

    if (integer > 99)
    {
        cheque[i++] = integer / 100 + 48;
        integer %= 100;
    }
    else
        if (thousand > 0)
            cheque[i++] = 48;

    if (integer > 9)
    {
        cheque[i++] = integer / 10 + 48;
        integer %= 10;
    }
    else
        if (thousand > 0)
            cheque[i++] = 48;

    cheque[i++] = integer + 48;
    cheque[i++] = '.';

    if (fractional > 9)
    {
        cheque[i++] = fractional / 10 + 48;
        fractional %= 10;
    }
    else cheque[i++] = 48;

    if (fractional > 0)
        cheque[i] = fractional + 48;
    else cheque[i] = 48;
};

void unification(char* s1, const char* s2)
{
    int i = 0;
    for (i; s1[i] != '\0'; i++);
    for (int j = 0; (s1[i + j] = s2[j]) != '\0'; j++);
};

void printText(char* text, int thousand, int integer, int fractional)
{
    const char* hundred[] = { "сто ", "двести ", "триста ", "четыреста ", "пятьсот ", "шестьсот ", "семьсот ", "восемьсот ", "девяться " };
    const char* dozen[] = { "десять ", "двадцать ", "тридцать ", "сорок ", "пятьдесят ", "шестьдесят ", "семьдесят ", "восемьдесят ", "девяносто " };
    const char* unitHundred[] = { "одна ", "две ", "три ", "четыре ", "пять ", "шесть ", "семь ", "восемь ", "девять " };
    const char* unitDozen[] = { "одиннадцать ", "двенадцать ", "тринадцать ", "четырнадцать ", "пятнадцать ", "шестнадцать ", "семнадцать ", "восемнадцать ", "девятнадцать " };
    const char* unitOnce[] = { "один ", "два ", "три ", "четыре ", "пять ", "шесть ", "семь ", "восемь ", "девять " };
    const char* doz[] = { "тысяч ", "тысяча ", "тысячи " };
    const char* rub[] = { "рубль ", "рублей " , "рубля "};
    const char* cop[] = { "копейка", "копеек", "копейки" };

    if (thousand > 0)
    {
        if (thousand > 9)
            if (thousand < 20 && thousand > 10)
            {
                unification(text, unitDozen[thousand / 10 - 1]);
                thousand %= 10;
            }
            else
            {
                unification(text, dozen[thousand / 10 - 1]);
                thousand %= 10;
                if (thousand > 0)
                    unification(text, unitDozen[thousand - 1]);
            }

        if (thousand == 0 || thousand > 4)
            unification(text, doz[0]);
        if (thousand == 1)
            unification(text, doz[1]);
        if (thousand > 1 && thousand < 5)
            unification(text, doz[2]);
    }

    if (integer > 99)
    {
        unification(text, hundred[integer / 100 - 1]);
        integer %= 100;
    }

    if (integer < 20 && integer > 10)
    {
        unification(text, unitDozen[integer / 10 - 1]);
        integer %= 10;
    }
    else
    {
        unification(text, dozen[integer / 10 - 1]);
        integer %= 10;
        if (integer > 0)
            unification(text, unitOnce[integer - 1]);
	}

    if (integer == 0 || integer > 4)
        unification(text, rub[1]);
    if (integer == 1)
        unification(text, rub[0]);
    if (integer > 1 && integer < 5)
        unification(text, rub[2]);

    int len = strlen(text);
    if (fractional < 10)
    {
        text[len] = '0';
        text[len + 1] = fractional + 48;
        text[len + 2] = ' ';
        text[len + 3] = '\0';
    }
    else
    {
		text[len] = fractional / 10 + 48;
		text[len + 1] = fractional % 10 + 48;
		text[len + 2] = ' ';
        text[len + 3] = '\0';
    }

    if (fractional / 10 != 1)
    {
        fractional %= 10;

        if (fractional == 0 || fractional > 4)
            unification(text, cop[1]);
        if (fractional == 1)
            unification(text, cop[0]);
        if (fractional > 1 && fractional < 5)
            unification(text, cop[2]);
    }
    else
        unification(text, cop[1]);
};

void transformation(double* sum, char* cheque, char* text)
{
    int integer = *sum;
    double f = ceil(*sum * 100 - integer * 100);
    int fractional = f;
    int thousand = 0;
    if (integer > 999)
    {
        thousand = integer / 1000;
        integer %= 1000;
    }

    protect(cheque, sum, thousand, integer, fractional);
    printText(text, thousand , integer, fractional);
};

void main()
{
    setlocale(LC_ALL, "Russian");

    double sum;
    char cheque[12] = "";
    char text[200] = "";

    cout << "Enter the sum: ";
    cin >> sum;
    cout << endl << endl;
    transformation(&sum, cheque, text);
    cout << cheque << endl << endl << text;




    cout << "\n\n\n\n\n\n\n\n\n\n";
}