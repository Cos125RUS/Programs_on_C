#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");


    int v[10] = { 0,1,2,99,4,5,6,7,8,9 };
	int* vPtr;

    vPtr = &v[0];
	cout << *vPtr << " - " << vPtr << endl;

    vPtr += 2;
    cout << *vPtr << " - " << vPtr << endl;

    vPtr--;
    cout << *vPtr << " - " << vPtr << endl;

    int* v2Ptr = &v[4],
		* v4Ptr = &v[1];
    int x = v2Ptr - v4Ptr;
    cout << *v2Ptr << " - " << v2Ptr << endl;
    cout << *v4Ptr << " - " << v4Ptr << endl;
	cout << x << " - " << &x << endl;

    int* v3Ptr = &v[3];
    cout << *v3Ptr << " - " << v3Ptr << endl;




    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}