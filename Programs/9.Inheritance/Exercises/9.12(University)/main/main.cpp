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
#include <cstring>
#include "Member.h"
#include "Student.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Student s1("Матфак", "Иван", "Иванов", 20);
    cout << s1 << endl;

    s1.newEvaluation(4);
    s1.newEvaluation(5);
    s1.newEvaluation(3);
    s1.printEvaluation();




    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}