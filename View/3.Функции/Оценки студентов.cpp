#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int student = 3;
const int exams = 4;

int minimum(int[][exams], int, int);
int maximum(int[][exams], int, int);
double average(int[], int);
void printArray(int[][exams], int, int);

int main()
{
    setlocale(LC_ALL, "Russian");

    int studentGrades[student][exams] = { {77,68,86,73},
                                          {96,87,89,78},
                                          {70,90,86,81} };

    cout << "Array:\n";
    printArray(studentGrades, student, exams);
    cout << "\n\nMinimum exams: " << minimum(studentGrades, student, exams)
        << "\nMaximum exams: " << maximum(studentGrades, student, exams) << '\n';

    for (int person = 0; person < student; person++)
        cout << "Average exams student " << person << " = "
        << setiosflags(ios::fixed | ios::showpoint) << setprecision(2)
        << average(studentGrades[person], exams) << endl;








    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

int minimum(int grades[][exams], int pupils, int tests)
{
    int lowGrade = 100;

    for (int i = 0; i < pupils; i++)
        for (int j = 0; j < tests; j++)
            if (grades[i][j] < lowGrade)
                lowGrade = grades[i][j];

    return lowGrade;
}

int maximum(int grades[][exams], int pupils, int tests)
{
    int highGrade = 100;

    for (int i = 0; i < pupils; i++)
        for (int j = 0; j < tests; j++)
            if (grades[i][j] > highGrade)
                highGrade = grades[i][j];

    return highGrade;
}

double average(int setOfGrades[], int tests)
{
    int total = 0;

    for (int i = 0; i < tests; i++)
        total += setOfGrades[i];

    return static_cast<double>(total) / tests;
}

void printArray(int grades[][exams], int pupils, int tests)
{
    cout << "                  [0]  [1]  [2]  [3]";

    for (int i = 0; i < pupils; i++)
    {
        cout << "\nGrade student [" << i << "] ";

        for (int j = 0; j < tests; j++)
            cout << setiosflags(ios::left) << setw(5) << grades[i][j];
    }
}
