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
#include "IntegerSet.h"

using namespace std;

int* generate(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        arr[i] = rand() % 100;
    return arr;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    int len1 = rand() % 100;
    int len2 = rand() % 100;
    int *a1 = new int[rand() % 100];
    int *a2 = new int[rand() % 100];

    IntegerSet *set1 = new IntegerSet(generate(a1, len1), len1);
    IntegerSet* set2 = new IntegerSet(generate(a2, len2), len2);
    set1->print();
    set2->print();
    cout << endl;

    set1->unionOfIntegerSet(*set2);
    set1->print();
    cout << endl;

    set1->intersectionOfIntegerSet(*set2);
    set1->print();
    cout << endl;

    cout << set1->isEqualTo(*set2);
    cout << endl;

    set1->insertElement(87);
    set1->deletElement(5);
    set1->print();
    cout << endl;

    cout << set1->isEqualTo(*set2);





    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}