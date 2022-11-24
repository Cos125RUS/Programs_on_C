#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stdio.h>

using namespace std;

const int student = 3;
const int exams = 4;

int printMenu();
void minimum(int[][exams], const int*, const int*);
void maximum(int[][exams], const int*, const int*);
void average(int[][exams], const int*, const int*);
void printArray(int[][exams], const int*, const int*);
void exit(int[][exams], const int*, const int*);
void (*processGrades[5])(int[][exams], const int*, const int*) = { printArray ,minimum ,maximum ,average,exit };

int main()
{
    setlocale(LC_ALL, "Russian");

    int studentGrades[student][exams] = { {77,68,86,73},
                                          {96,87,89,78},
                                          {70,90,86,81} };

    
	//void* processGrades[5](int[][exams], const int*, const int*) = { printArray ,minimum ,maximum ,average };

    int chois;
    do {
        chois = printMenu();
        (*processGrades[chois])(studentGrades, &student, &exams);
    } while (chois != 4);



    
    
    
    






    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

int printMenu()
{
    cout << "\n\n0  Print Array\n"
         << "1  Minimum\n"
         << "2  Maximum\n"
         << "3  Average\n"
         << "4  Exit\n";

    int chois;
    cout << "\nYour chois: ";
    cin >> chois;

    return chois;
}

void minimum(int grades[][exams], const int* pupils, const int* tests)
{
    int lowGrade = 100;

    for (int i = 0; i < *pupils; i++)
        for (int j = 0; j < *tests; j++)
            if (grades[i][j] < lowGrade)
                lowGrade = grades[i][j];

    cout << "\n\nMinimum exams: " << lowGrade;
}

void maximum(int grades[][exams], const int* pupils, const int* tests)
{
    int highGrade = 0;

    for (int i = 0; i < *pupils; i++)
        for (int j = 0; j < *tests; j++)
            if (grades[i][j] > highGrade)
                highGrade = grades[i][j];

    cout << "\nMaximum exams: " << highGrade;
}

void average(int grades[][exams], const int* pupils, const int* tests)
{
    int totalGrades[student] = { 0 };
    cout << endl; 

    for (int person = 0; person < student; person++)
    {
        for (int i = 0; i < *tests; i++)
            totalGrades[person] += grades[person][i];

        cout << "Average exams student " << person << " = "
            << setiosflags(ios::fixed | ios::showpoint) << setprecision(2)
            << static_cast<double>(totalGrades[person]) / *tests << endl;
    }
}

void printArray(int grades[][exams], const int* pupils, const int* tests)
{
    cout << "Array:\n";
    cout << "                  [0]  [1]  [2]  [3]";

    for (int i = 0; i < *pupils; i++)
    {
        cout << "\nGrade student [" << i << "] ";

        for (int j = 0; j < *tests; j++)
            cout << setiosflags(ios::left) << setw(5) << grades[i][j];
    }
}

void exit(int grades[][exams], const int* pupils, const int* tests)
{
    cout << "\nEXIT OF PROGRAME";
}