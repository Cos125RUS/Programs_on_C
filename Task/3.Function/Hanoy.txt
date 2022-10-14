#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void hanoi(int, int, int);

void move(int, int);

int buf(int, int);

int degree(int);

int main()
{
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "n = ";
    cin >> n;
    cout << endl;

    hanoi(n, 1, 3);



    int departure = 1,
        target = 3,
        buffer = 2,
        final = pow(2, n) - 1,
        middle = pow(2, n - 1);

    
        
    if (n <= 1)
        move(departure, target);
    else
    {
        if (n % 2 == 1)
        {
            target = buffer;
            buffer = buf(departure, target);
            cout << "departure = " << departure << " target = " << target << " buffer = " << buffer << endl;
        }


        for (int i = 1; i <= final; i++)
        {
            if (middle % i == 0)
            {
                departure = 1;

                if ((degree(middle) % 2) == (degree(i) % 2))
                {
                    target = 3; 
                    buffer = buf(departure, target);
                }
                else
                {
                    target = 2;
                    buffer = buf(departure, target);
                }
            }

            cout << "i = " << i << " departure = " << departure << " target = " << target << " buffer = " << buffer << endl;

            switch (i % 4)
            {
            case 1:
                move(departure, buffer);
                break;

            case 2:
                move(departure, target);
                break;

            case 3:
                move(buffer, target);
                target = buffer;
                buffer = buf(departure, target);
                break;

            case 0:
                move(departure, target);
                departure = buffer;
                buffer = buf(departure, target);
                break;
            }

        }
    }
        

    




    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}


void hanoi(int n, int departure, int target)
{
    int buffer;
        
    if (n == 1)
    {
        switch (departure)
        {
        case 1:
            if (target == 2)
                cout << "1->2\n";
            else
                cout << "1->3\n";
            break;

        case 2:
            if (target == 1)
                cout << "2->1\n";
            else
                cout << "2->3\n";
            break;

        case 3:
            if (target == 1)
                cout << "3->1\n";
            else
                cout << "3->2\n";
            break;
        }
    }
    else
    {
        switch (departure)
        {
        case 1:
            if (target == 2)
                buffer = 3;
            else
                buffer = 2;
            break;

        case 2:
            if (target == 1)
                buffer = 3;
            else
                buffer = 1;
            break;

        case 3:
            if (target == 1)
                buffer = 2;
            else
                buffer = 1;
            break;
        }

        hanoi(n - 1, departure, buffer);
        hanoi(1, departure, target);
        hanoi(n - 1, buffer, target);
    }
    
        

}

void move(int departure, int target)
{
    switch (departure)
    {
    case 1:
        if (target == 2)
            cout << "1->2\n";
        else
            cout << "1->3\n";
        break;

    case 2:
        if (target == 1)
            cout << "2->1\n";
        else
            cout << "2->3\n";
        break;

    case 3:
        if (target == 1)
            cout << "3->1\n";
        else
            cout << "3->2\n";
        break;
    }
}

int buf(int departure, int target)
{
    switch (departure)
    {
    case 1:
        if (target == 2)
            return 3;
        else
            return 2;
        break;

    case 2:
        if (target == 1)
            return 3;
        else
            return 1;
        break;

    case 3:
        if (target == 1)
            return 2;
        else
            return 1;
        break;
    }
}

int degree(int e)
{
    int res = 0;
    while (e > 1)
    {
        e /= 2;
        res++;
    }

    if (res > 0)
        return res;
    else
        return 1;
}


