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
#include "Boss.h"
#include "CommissionWorker.h"
#include "Employee.h"
#include "Hourly.h"
#include "PieceWorker.h"
#include "Date.h"

using namespace std;

void virtualViaReference(Employee&, int);

int main()
{
    setlocale(LC_ALL, "Russian");


    cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2);

    Boss b("John", "Smith", new Date(12, 27, 1992), 1, 800.00);
    CommissionWorker c("Sue", "Jones", new Date(11, 12, 1990), 2, 200.0, 3.0, 150);
    PieceWorker p("Bob", "Lewis", new Date(5, 10, 1989), 3, 2.5, 200);
    HourlyWorker h("Karen", "Price", new Date(1, 1, 1993), 4, 13.75, 40);

    Employee* employeers[4] = { &b, &c, &p, &h };
    for (int j = 1; j < 13; j++)
    {
        cout << "---------------- month: " << j << " ----------------";
        for (int i = 0; i < sizeof(*employeers); i++)
            virtualViaReference(*employeers[i], j);
        cout << '\n';
    }






    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

void virtualViaReference(Employee& baseClassRef, int month)
{
    baseClassRef.print();
    cout << " salary $" << baseClassRef.earnings(month);
}