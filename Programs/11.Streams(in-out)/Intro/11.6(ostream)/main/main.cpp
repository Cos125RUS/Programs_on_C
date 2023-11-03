#include <iostream>

using namespace std;

ostream& bell(ostream& output) { return output << '\a'; }
ostream& ret(ostream& output) { return output << '\r'; }
ostream& tab(ostream& output) { return output << '\t'; }
ostream& endLine(ostream& output) { return output << '\n' << flush; }

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Test" << endLine << tab << "test" << endLine << "........";
	cout << bell;
	cout << ret << "----------" << endLine;






	cout << "\n\n\n\n\n\n\n\n\n\n";
}