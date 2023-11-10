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

void print(int x) {
    cout << dec << x << endl;
    cout << oct << x << endl;
    cout << hex << x << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int x = 0;
    char buffer[20];
    char c;
    int i = 0;
    cout << "Enter: ";
    while ((c = cin.get()) != '\n' && i < 20) {
        buffer[i++] = c;
    }
    //cin.getline(buffer, 20, '\n');
    cout << setiosflags(ios::showbase);
    if (buffer[0] == '0') {
        if (buffer[1] == 'x') {
            for (int j = i - 1, k = 0; j > 1; j--, k++) {
                switch (buffer[j])
                {
                case 'a':
                    x += 10 * pow(16, k);

                    break;
                case 'b':
                    x += 11 * pow(16, k);
                    break;
                case 'c':
                    x += 12 * pow(16, k);
                    break;
                case 'd':
                    x += 13 * pow(16, k);
                    break;
                case 'e':
                    x += 14 * pow(16, k);
                    break;
                case 'f':
                    x += 15 * pow(16, k);
                    break;
                default:
                    x += (buffer[j] - '0') * pow(16, k);
                    break;
                }
            }
            print(x);
        }
        else {
            for (int j = i - 1, k = 0; j > 0; j--, k++) {
                x += (buffer[j] - '0') * pow(8, k);
            }
            print(x);
        }
    }
    else {
        for (int j = i-1, k = 0; j >= 0; j--, k++) {
            x += (buffer[j] - '0') * pow(10, k);
        }
        print(x);
    }








    cout << "\n\n\n\n\n\n\n\n\n\n";
}