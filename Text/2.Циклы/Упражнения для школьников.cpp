#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int sum(int, int);

int sub(int, int);

int com(int, int);

int priv(int, int);

int ever(int, int);

void respons(int);

int grade(int);

int main()
{
    setlocale(LC_ALL, "Russian");

    srand(time(0));

    int chois, order,
        back = 1,
        menu = 1;

    while (back > 0)
    {
        cout << "Ок, шкет, что будем тренировать?\n"
            << "1 - сложение\n"
            << "2 - вычитание\n"
            << "3 - умножение\n"
            << "4 - деление\n"
            << "5 - всё сразу\n";
        cin >> chois;

        while (chois < 0 || chois > 5)
        {
            cout << "\n\nТы что, даже по клавишам не попадаешь?"
                << "\nНу, попробуй ещё раз: ";
            cin >> chois;
        }

        cout << "\nЧисла какого порядка?\n"
            << "1 - однозначные\n"
            << "2 - двузначные\n"
            << "3 - трёхзначные\n"
            << "4 - дохерачные\n";
        cin >> order;

        while (order < 0 || order > 4)
        {
            cout << "\n\nТы что, даже по клавишам не попадаешь?"
                << "\nНу, попробуй ещё раз: ";
            cin >> order;
        }

        cout << endl;

        order = grade(order);

        while (menu == 1)
        {
            switch (chois)
            {
            case 1:
                back = sum(order, 10);
                break;

            case 2:
                back = sub(order, 10);
                break;

            case 3:
                back = com(order, 10);
                break;

            case 4:
                back = priv(order, 10);
                break;

            case 5:
                back = ever(order, 15);
                break;
            }

            cout << "\n\nПродолжим или всё, выдохся? (y/n)   ";
            if (back = cin.get() != EOF);

            cout << endl;

            while (back != 121 && back != 110)
            {
                cout << "\n\nТы что, даже по клавишам не попадаешь?"
                    << "\nНу, попробуй ещё раз: ";
                if (back = cin.get() != EOF);
            }

            if (back == 110)
                back = 0;
            else
            {
                cout << "То же самое или попробуешь что-то ещё?\n"
                    << "1 - то же самое\n2 - что-то ещё\n";
                cin >> menu;

                while (menu < 1 || back >2)
                {
                    cout << "\n\nТы что, даже по клавишам не попадаешь?"
                        << "\nНу, попробуй ещё раз: ";
                    cin >> menu;
                }
                cout << endl;
            }
        }





    }











    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

int sum(int x, int n)
{
    int i = 0,
        a, b, res, answer;

    while (i < n)
    {
        a = 1 + rand() % (9 * x);
        b = 1 + rand() % (9 * x);
        res = a + b;

        cout << a << " + " << b << " = ";
        cin >> answer;

        if (res == answer)
        {
            respons(1);
            i++;
        }
        else
        {
            respons(2);
            i--;
        }
    }

    return 1;
}

int sub(int x, int n)
{
    int i = 0,
        a, b, c, res, answer;

    while (i < n)
    {
        a = 1 + rand() % (9 * x);
        b = 1 + rand() % (9 * x);

        if (a < b)
        {
            c = b;
            b = a;
            a = c;
        }

        res = a - b;

        cout << a << " - " << b << " = ";
        cin >> answer;

        if (res == answer)
        {
            respons(1);
            i++;
        }
        else
        {
            respons(2);
            i--;
        }
    }
    return 1;

}

int com(int x, int n)
{
    int i = 0,
        a, b, res, answer;

    while (i < n)
    {
        a = 1 + rand() % (9 * x);
        b = 1 + rand() % (9 * x);
        res = a * b;

        cout << a << " * " << b << " = ";
        cin >> answer;

        if (res == answer)
        {
            respons(1);
            i++;
        }
        else
        {
            respons(2);
            i--;
        }
    }

    return 1;

}

int priv(int x, int n)
{
    int i = 0,
        a, b, c, res, answer;

    while (i < n)
    {
        a = 1 + rand() % (9 * x);
        b = 1 + rand() % (9 * x);

        while (a % b != 0 && b % a != 0)
        {
            a = 1 + rand() % (9 * x);
            b = 1 + rand() % (9 * x);
        }

        if (a < b)
        {
            c = b;
            b = a;
            a = c;
        }

        res = a / b;

        cout << a << " / " << b << " = ";
        cin >> answer;

        if (res == answer)
        {
            respons(1);
            i++;
        }
        else
        {
            respons(2);
            i--;
        }
    }

    return 1;
}

int ever(int z, int n)
{
    int j,
        i = 0;

    while (i < n)
    {
        j = 1 + rand() % 4;

        switch (j)
        {
        case 1:
            i += sum(z, 1);
            break;

        case 2:
            i += sub(z, 1);
            break;

        case 3:
            i += com(z, 1);
            break;

        case 4:
            i += priv(z, 1);
            break;
        }
    }

    return 1;

}

void respons(int y)
{
    int i;
    i = 1 + rand() % 4;

    if (y == 1)
    {
        switch (i)
        {
        case 1:
            cout << "Повезло.\n\n";
            break;

        case 2:
            cout << "Угадал, да?)\n\n";
            break;

        case 3:
            cout << "Хм...\n\n";
            break;

        case 4:
            cout << "Ладно, допустим...\n\n";
            break;
        }
    }
    else
    {
        switch (i)
        {
        case 1:
            cout << "Пф...\n\n";
            break;

        case 2:
            cout << "Чего и следовало ожидать.\n\n";
            break;

        case 3:
            cout << "Да уж...\n\n";
            break;

        case 4:
            cout << "Ничтожество!\n\n";
            break;
        }
    }
}

int grade(int x)
{
    switch (x)
    {
    case 1:
        return 1;
        break;

    case 2:
        return 11;
        break;

    case 3:
        return 111;
        break;

    case 4:
        return (1 + rand());
        break;
    }
}