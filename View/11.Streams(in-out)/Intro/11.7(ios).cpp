#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout.setf(ios::showpoint);
    cout << 9.90000 << endl;
    cout << setw(10) << 10 << setw(10) << 10;
    cout.setf(ios::left, ios::adjustfield);
    cout << "\nbase\n";
    cout.unsetf(ios::left);
    cout << "\nbase\n";
    cout << setw(10) << setiosflags(ios::left) << 10 << endl << setw(10) << resetiosflags(ios::left) << 10 << endl;
    cout << setiosflags(ios::internal | ios::showpoint) << setw(10) << 123 << endl;

    cout << endl << endl;
    int x = 10000;
    cout << x << endl;
    cout.setf(ios::showbase);
    cout << setw(10) << x << endl;
    cout.setf(ios::left, ios::adjustfield);
    cout << setw(10) << x << endl;
    cout.setf(ios::internal, ios::adjustfield);
    cout << setw(10) << hex << x << endl;
    cout.setf(ios::right, ios::adjustfield);
    cout.fill('*');
    cout << setw(10) << dec << x << endl;
    cout.setf(ios::left, ios::adjustfield);
    cout << setw(10) << setfill('%') << x << endl;
    cout.setf(ios::internal, ios::adjustfield);
    cout << setw(10) << setfill('^') << hex << x << endl;

    cout << endl << endl;
    cout << setiosflags(ios::showbase) << dec << x << endl << setiosflags(ios::uppercase) << oct << x << endl << hex << x << endl;

    cout << endl << endl;
    double a = .001234567, b = 1.946e9;
    cout << a << '\t' << b << endl;
    cout.setf(ios::scientific, ios::floatfield);
    cout << a << '\t' << b << endl;
    cout.unsetf(ios::scientific);
    cout << a << '\t' << b << endl;
    cout.setf(ios::fixed, ios::floatfield);
    cout << a << '\t' << b << endl;

    cout << endl << endl << setiosflags(ios::showbase) << dec;
    int i = 1000;
    double d = 0.0947628;
    cout << cout.flags() << endl << i << '\t' << d << endl;
    long originalFormat = cout.flags(ios::oct | ios::scientific);
    cout << cout.flags() << endl << i << '\t' << d << endl;
    cout.flags(originalFormat);
    cout << cout.flags() << endl << i << '\t' << d << endl;









    cout << "\n\n\n\n\n\n\n\n\n\n";
}