#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


bool test_polindrome(char[], int, int);

int string_length(char[], int);

int main()
{
    setlocale(LC_ALL, "Russian");


    const int length = 20;

    char text[length];

    cout << "Enter the text: ";
    cin >> text;
    cout << endl;

    int high = string_length(text, length);
    
          
    if (test_polindrome(text, high, 0) == true) 
        cout << "Text is polindrom!";
    else
        cout << "Text is not polindrom!";

    

    



    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

bool test_polindrome(char text[], int size, int a)
{
    if (a >= size)
        return true;
    else
    {
        if (text[a] == text[size - 1]) 
            return test_polindrome(text, size - 1, a + 1);
        else 
            return false;        
    }
}

int string_length(char text[], int length)
{
    int count = 0;

    for (int i = 0; i < length; i++)
        if (text[i] != 0)
            count++;
        else
            return count;
}