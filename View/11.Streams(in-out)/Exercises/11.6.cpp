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

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    /*
    cout.setf(ios::left, ios::adjustfield);
    cout.fill('*');
    cout.width(15);
    cout << 40000 << endl;
    
    char line[40];
    cin.getline(line, 40);
    cout.write(line, cin.gcount());

    cout << setiosflags(ios::internal | ios::showpos) << 200 << endl;

    cout << setiosflags(ios::showbase) << hex << 100 << endl;

    char s[10];
    cin.get(s, 10, 'p');
    cout.write(s, cin.gcount());

    cout.precision(9);
    cout << setiosflags(ios::fixed) << 1.234 << endl;
    */

    char s[50];
    char c;
    for (int i = 0; i < 50; ) {
        if ((c = cin.get()) != '"') 
            s[i++] = c;
    }
    cout.write(s, 50);




    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}