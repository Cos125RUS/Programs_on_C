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
#include "Emply.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Количество служащих: " << Employee::getCount() << endl;

    Employee* e1Ptr = new Employee("Susan", "Baker");
    Employee* e2Ptr = new Employee("Bob", "Jones");

    cout << "Количество служащих: " << e1Ptr->getCount() << endl;

    cout << "\n\nСлужащий 1: " << e1Ptr->getFirstName() << " " << e1Ptr->getLastName() <<
        "\nСлужащий 2: " << e2Ptr->getFirstName() << " " << e2Ptr->getLastName() << "\n\n";

    delete e1Ptr;
    e1Ptr = 0;
    delete e2Ptr;
    e2Ptr = 0;

    cout << "Количество служащих: " << Employee::getCount() << endl;



    cout << "\n\n\n\n\n\n\n\n\n\n";
    return 0;
}