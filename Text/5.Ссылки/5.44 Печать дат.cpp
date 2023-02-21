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

void convert(const int* day, const int* month, const int* year)
{
    bool error = false;

    if (*day < 1 && *day > 31)
        error = true;

    if (*month < 1 && *month > 12)
        error = true;

    if (*year > 99)
        error = true;

    if (*day == 31)
    {
        switch (*month)
        {
        case 4: 
            error = true;
            break;

        case 6:
            error = true;
            break;

        case 9:
            error = true;
            break;

        case 11:
            error = true;
            break;

        default:
            break;
        }
    }

    if (*month == 2 && *day > 28)
        if ((*year % 4) != 0 && *day != 29)
            error = true;
    
    cout << "\t\t\t";

    if (error)
        cout << "The date is incorrect";
    else
    {
        switch (*month)
        {
        case 1:
            cout << "January ";
            break;

        case 2:
            cout << "February ";
            break;

        case 3:
            cout << "March ";
            break;

        case 4:
            cout << "April ";
            break;

        case 5:
            cout << "May ";
            break;

        case 6:
            cout << "June ";
            break;

        case 7:
            cout << "July ";
            break;

        case 8:
            cout << "August ";
            break;

        case 9:
            cout << "September ";
            break;

        case 10:
            cout << "October ";
            break;

        case 11:
            cout << "November ";
            break;

        case 12:
            cout << "December ";
            break;
        }

        cout << *day << ", 20" << *year << endl;
    }
};

void processing(char* text)
{
    int day;
    int month;
    int year;
    char* s1;
    char* s2;
    char* s3;
    bool error = false;

    s1 = strtok_s(text, "/", &s2);
    if (strlen(s1) > 2)
    {
        cout << "Incorrect values\n\n";
        error = true;
    }
    else
		day = (s1[0] - 48) * 10 + s1[1] - 48;

    strtok_s(s2, "/", &s3);
    if (strlen(s2) > 2 && !error)
    {
        cout << "Incorrect values\n\n";
        error = true;
    }
    else
        month = (s2[0] - 48) * 10 + s2[1] - 48;
    
    if (strlen(s2) > 2 && !error)
    {
        cout << "Incorrect values\n\n";
        error = true;
    }
    else
        year = (s3[0] - 48) * 10 + s3[1] - 48;

    if (!error) convert(&day, &month, &year);
};

int main()
{
    setlocale(LC_ALL, "Russian");
    
    char txt[30];

    while (true)
    {
		cin.getline(txt, 30, '\n');
		processing(txt);
    }
        
    





    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}