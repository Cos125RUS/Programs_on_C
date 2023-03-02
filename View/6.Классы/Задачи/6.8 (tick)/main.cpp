#include <iostream>
#include <locale>
#include "time.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Time t(23,59,21);

    
    for (int i = 0; i < 200; i++) {
        t.tick();
        t.printStandard();
        cout << endl;
    }




    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

