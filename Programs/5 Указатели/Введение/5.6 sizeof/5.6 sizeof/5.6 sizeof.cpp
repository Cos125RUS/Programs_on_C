#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

size_t getSize(float*);

int main()
{
    setlocale(LC_ALL, "Russian");

    float array[20];

    cout << "Число байтов в массиве: "
        << sizeof(array)
        << "\nЧисло байтов в массиве, возвращаемое функцией getSize: "
        << getSize(array) << endl << endl << endl;


    bool b;
    char c;
    short s;
    int i;
    long l;
    float f; 
    double d;
    long double ld;
    int arr[20], * ptr = arr;

    cout << "sizeof b = " << sizeof b
        << "\tsizeof bool = " << sizeof(bool) 
        << "\nsizeof c = " << sizeof c
        << "\tsizeof char = " << sizeof(char)
        << "\nsizeof s = " << sizeof s
        << "\tsizeof short = " << sizeof(short)
        << "\nsizeof i = " << sizeof i
        << "\tsizeof int = " << sizeof(int)
        << "\nsizeof l = " << sizeof l
        << "\tsizeof long = " << sizeof(long)
        << "\nsizeof f = " << sizeof f
        << "\tsizeof float = " << sizeof(float)
        << "\nsizeof d = " << sizeof d
        << "\tsizeof double = " << sizeof(double)
        << "\nsizeof ld = " << sizeof ld
        << "\tsizeof long double = " << sizeof(long double)
        << "\nsizeof arr = " << sizeof arr
        << "\nsizeof ptr = " << sizeof ptr;







    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

size_t getSize(float* ptr)
{
    return sizeof (ptr);
}