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

using namespace std;

//void virtualViaPointer(const Employee*);
void virtualViaReference(const Employee&);

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2);

    Boss b("John", "Smith", 800.00);
    b.print();
    cout << " salary $" << b.earnings();
    //virtualViaPointer(&b);
    virtualViaReference(b);

    CommissionWorker c("Sue", "Jones", 200.0, 3.0, 150);
    c.print();
    cout << " salary $" << c.earnings();
    //virtualViaPointer(&c);
    virtualViaReference(c);

    PieceWorker p("Bob", "Lewis", 2.5, 200);
    p.print();
    cout << " salary $" << p.earnings();
    //virtualViaPointer(&p);
    virtualViaReference(p);

    HourlyWorker h("Karen", "Price", 13.75, 40);
    h.print();
    cout << " salary $" << h.earnings();
    //virtualViaPointer(&h);
    virtualViaReference(h);




    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

//void virualViaPointer(const Employee* baseClassPtr)
//{
    //baseClassPtr->print();
   // cout << " salary $" << baseClassPtr->earnings();
//}

void virtualViaReference(const Employee& baseClassRef)
{
    baseClassRef.print();
    cout << " salary $" << baseClassRef.earnings();
}