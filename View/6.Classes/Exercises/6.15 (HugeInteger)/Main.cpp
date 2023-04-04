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
#include "HugeInteger.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

//    HugeInteger n("16541684313541551313546");
//    n.outputHugeInteger();
    HugeInteger n("120");
    HugeInteger n2("122");
//    n.addHugeInteger(n2);
//    n.outputHugeInteger();
    n.substractHugeInteger(n2);
    n.outputHugeInteger();




    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}