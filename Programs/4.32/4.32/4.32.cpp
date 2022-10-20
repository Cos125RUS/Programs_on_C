#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

bool test_polindrome(char[], int, int);

int main()
{
    setlocale(LC_ALL, "Russian");

    char text[5] = { 'r','a','d','a','r' };
    
          
    cout << test_polindrome(text, 5, 0);
    

    char txt;
    cout << "Enter text: ";
    cin >> txt;
    cout << "\n\ntxt: " << txt[2];



    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

bool test_polindrome(char text[], int size, int a)
{
    if (a == (size / 2))
        return true;
    else
    {
        if (text[a] == text[size - 1 - a]) return test_polindrome(text, size, a + 1);
        else return false;        
    }
}