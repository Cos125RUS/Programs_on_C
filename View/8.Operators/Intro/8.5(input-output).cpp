// 8.5(input).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>

using namespace std;

class PhoneNumber {
    friend ostream& operator<<(ostream&, const PhoneNumber&);
    friend istream& operator>>(istream&, PhoneNumber&);

private:
    char areaCode[4];
    char exchange[5];
    char line[5];
};

ostream& operator<<(ostream& output, const PhoneNumber& num)
{
    output << "(" << num.areaCode << ") " << num.exchange << "-" << num.line;
    return output;
}

istream& operator>>(istream& input, PhoneNumber& num)
{
    input.ignore();
    input >> setw(4) >> num.areaCode;
    input.ignore(2);
    input >> setw(4) >> num.exchange;
    input.ignore();
    input >> setw(5) >> num.line;
    return input;
}

int main()
{
    PhoneNumber phone;

    cout << "Enter the phone number: ";
    cin >> phone;
    cout << "Phone number: " << phone << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
