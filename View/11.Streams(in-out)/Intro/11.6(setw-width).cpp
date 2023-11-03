#include <iostream>


using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int w = 4;
	char string[10];

	cout << "Enter the line:\n";
	cin.width(5);

	while (cin >> string) {
		cout.width(w++);
		cout << string << endl;
		cin.width(5);
	}








	cout << "\n\n\n\n\n\n\n\n\n\n";
}