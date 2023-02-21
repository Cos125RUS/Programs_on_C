#include <iostream>
#include <locale>

using namespace std;

class Rational {
public:
	Rational(int = 0, int = 1);
	void set(int, int);
	void printFraction();
	void printDouble();
	void numerator(int);
	void denominator(int);
	void sum(Rational, Rational);
	void dif(Rational, Rational);
	void multy(Rational, Rational);
	void div(Rational, Rational);
private:
	int numer;
	int denom;
	int findNod(int, int);
	void reduction(int, int);
};

Rational::Rational(int a, int b)
{
	numer = a;
	denom = b;
}

void Rational::set(int a, int b)
{
	numer = a;
	denom = b;
}

void Rational::printFraction()
{
	cout << numer << '/' << denom;
}

void Rational::printDouble()
{
	double res = static_cast<double>(numer)  / denom;
	cout << res;
}

void Rational::numerator(int a)
{
	numer = a;
}

void Rational::denominator(int b)
{
	denom = b;
}

int Rational::findNod(int a, int b)
{
	int num1, num2;
	if (a < b)
	{
		num1 = a;
		num2 = b;
	}
	else
	{
		num1 = b;
		num2 = a;
	}

	int nod = 1;
	for (int i = 2, n = num1; i <= num1; i++, num1 = n)
		while (n % i == 0 && num2 % i == 0)
		{
			n /= i;
			num2 /= i;
			nod *= i;
		}

	return nod;
}

void Rational::reduction(int n, int d)
{
	int nod = findNod(n, d);
	numer = n / nod;
	denom = d / nod;
}

void Rational::sum(Rational num1, Rational num2)
{
	if (num1.denom == num2.denom)
	{
		numer = num1.numer + num2.numer;
		denom = num1.denom;
	}
	else
	{
		int nod = findNod(num1.denom, num2.denom);
		denom = num1.denom / nod * num2.denom;
		numer = num1.numer * (num2.denom / nod) + num2.numer * (num1.denom / nod);
	}

	reduction(numer, denom);
}

void Rational::dif(Rational num1, Rational num2)
{
	if (num1.denom == num2.denom)
	{
		numer = num1.numer - num2.numer;
		denom = num1.denom;
	}
	else
	{
		int nod = findNod(num1.denom, num2.denom);
		denom = num1.denom / nod * num2.denom;
		numer = num1.numer * (num2.denom / nod) - num2.numer * (num1.denom / nod);
	}

	reduction(numer, denom);
}

void Rational::multy(Rational num1, Rational num2)
{
	numer = num1.numer * num2.numer;
	denom = num1.denom * num2.denom;

	reduction(numer, denom);
}

void Rational::div(Rational num1, Rational num2)
{
	numer = num1.numer * num2.denom;
	denom = num1.denom * num2.numer;

	reduction(numer, denom);
}



int main()
{
	setlocale(LC_ALL, "Russian");

	Rational a(2, 5);
	a.printFraction();
	cout << endl;
	a.printDouble();
	cout << endl;
	Rational b(1, 6);
	b.printFraction();
	cout << endl;
	b.printDouble();
	cout << endl;
	Rational c;
	c.sum(a, b);
	c.printFraction();
	cout << endl;
	c.printDouble();
	cout << endl;
	c.dif(a, b);
	c.printFraction();
	cout << endl;
	c.printDouble();
	cout << endl;
	c.multy(a, b);
	c.printFraction();
	cout << endl;
	c.printDouble();
	cout << endl;
	c.div(a, b);
	c.printFraction();
	cout << endl;
	c.printDouble();
	cout << endl;


	cout << "\n\n\n\n\n\n\n\n\n\n";

	return 0;
}