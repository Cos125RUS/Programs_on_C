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
#include "string.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    String s1("happy"), s2(" birthday"), s3;

    cout << "s1 is\"" << s1 << "\"; s2 is \"" << s2 << "\"; s3 is \"" << s3 << '\"'
        << "\nThe results of comparing s2 and s1: "
        << "\ns2 == s1 yields " << (s2 == s1 ? "true" : "false")
        << "\ns2 != s1 yields " << (s2 != s1 ? "true" : "false")
        << "\ns2 > s1 yields " << (s2 > s1 ? "true" : "false")
        << "\ns2 < s1 yields " << (s2 < s1 ? "true" : "false")
        << "\ns2 >= s1 yields " << (s2 >= s1 ? "true" : "false")
        << "\ns2 <= s1 yields " << (s2 <= s1 ? "true" : "false");

    cout << "\nTesting !s3:\n";
    if (!s3) {
        cout << "s3 is empty; assigning s1 to s3;\n";
        s3 = s1;
        cout << "s3 is \"" << s3 << "\"";
    }

    cout << "\n\ns1 += s2 yields s1 = ";
    s1 += s2;
    cout << s1;

    cout << "\n\ns1 += \" to you\" take result\n";
    s1 += " to you";
    cout << "s1 = " << s1 << "\n\n";

    cout << "The substring of s1 starting at\n"
        << "location 0 for 14 characters, s1(0, 14), is:\n"
        << s1(0, 14) << "\n\n";

    cout << " The substring of s1 starting at \n"
        << " location 15, s1(15, 0), is: "
        << s1(15, 0) << "\n\n";

    String* s4Ptr = new String(s1);
    cout << "*s4Ptr = " << *s4Ptr << "\n\n";

    cout << "assigning *s4Ptr to *s4Ptr\n";
    *s4Ptr = *s4Ptr;
    cout << "*s4Ptr = " << *s4Ptr << endl;
    delete s4Ptr;

    s1[0] = 'H';
    s1[6] = 'B';
    cout << "\ns1 after s1[0] = 'H' and s1[6] = 'B' is : " << s1 << "\n\n";

    //cout << "Attempt to assign 'd' to s1[30] yields: \n";
    //s1[30] = 'd';






    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}