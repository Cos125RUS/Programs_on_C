#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int field_size = 20;

enum Compass { N, S, W, E };
enum Whell{ R,L };
Compass direction = E;

void print(int[][field_size]);

void turn(Whell);

void move(int[][field_size], int[], int);

void steps(int[], int);

void view_direction();

void matrix( int [][field_size]);

int main()
{
    setlocale(LC_ALL, "Russian");

    

    int floor[field_size][field_size] = { 0 },
        turtle[2] = { 0,0 },
        stylus = 0,
        x = 0,
        length = 0;

    cout << "Instruction:\n1 - stylus up\n2 - stylus down\n"
        "3 - turn right\n4 - turn left\n5 - moving forward\n"
        "6 - print the way\n7 - view direction\n"
        "8 - view matrix\n9 - end of programe\n\n";

    while (x != 9)
    {
        cout << "Enter command: ";
        cin >> x;

        switch (x)
        {
        case 1:
            stylus = 0;
            cout << "Stylus up\n";
            break;

        case 2:
            stylus = 1;
            cout << "Stylus down\n";
            break;

        case 3:
            turn(R);
            cout << "Turn right\n";
            break;

        case 4:
            turn(L);
            cout << "Turn left\n";
            break;

        case 5:
            cout << "length = ";
            cin >> length;
            if (stylus == 1)
                move(floor, turtle, length);
            steps(turtle, length);
            //cout << "\n turtle in " << turtle[0] << ':' << turtle[1] << endl;
            break;

        case 6:
            print(floor);
            break;

        case 9:
            cout << "\nThe program is over.";
            break;

        case 7:
            view_direction();
                break;

        case 8:
            matrix(floor);
            break;

        default:
            cout << "\nError! Enter another command.\n";
            break;
        }
    }

        



    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}

void print(int way[][field_size])
{
    for (int i = 0; i < field_size; i++)
    {
        for (int j = 0; j < field_size; j++)
        {
            if (way[i][j] == 1)
                cout << '*';
            else
                cout << ' ';
        }
        cout << endl;
    }
}

void turn(Whell side)
{
    if (side == R)
        switch (direction)
        {
        case N:
            direction = E;
            break;

        case E:
            direction = S;
            break;

        case S:
            direction = W;
            break;

        case W:
            direction = N;
            break;
        }
    else
        switch (direction)
        {
        case N:
            direction = W;
            break;

        case E:
            direction = N;
            break;

        case S:
            direction = E;
            break;

        case W:
            direction = S;
            break;
        }
}

void move(int path[][field_size], int turtle[], int length)
{
    int i = turtle[0],
        j = turtle[1];

    //cout << endl << i << ':' << j << endl;
    //view_direction();

    switch (direction)
    {
    case E:
        if ((turtle[1] + length) > field_size)
            length = field_size;
        for (j; j < length; j++)
            path[i][j] = 1;
        break;

    case S:
        if ((turtle[0] + length) > field_size)
            length = field_size;
        for (i; i < length; i++)
            path[i][j] = 1;
        break;

    case W:
        if ((turtle[1] - length) < 0)
            length = -1;
        for (j; j > length; j--)
            path[i][j] = 1;
        break;

    case N:
        if ((turtle[0] - length) < 0)
            length = -1;
        for (i; i > length; i--)
            path[i][j] = 1;
        break;
    }
}

void steps(int turtle[], int length)
{
    switch (direction)
    {
    case E:
        if ((turtle[1] + length) > field_size - 1)
        {
            cout << "\nThe turtle can't go outside the field.\n";
            turtle[1] = field_size - 1;
        }
        else
            turtle[1] += length;
        break;

    case S:
        if ((turtle[0] + length) > field_size - 1)
        {
            cout << "\nThe turtle can't go outside the field.\n";
            turtle[0] = field_size - 1;
        }
        else
            turtle[0] += length;
        break;

    case W:
        if ((turtle[1] - length) < 0)
        {
            cout << "\nThe turtle can't go outside the field.\n";
            turtle[1] = 0;
        }
        else
            turtle[1] -= length;
        break;

    case N:
        if ((turtle[0] - length) < 0)
        {
            cout << "\nThe turtle can't go outside the field.\n";
            turtle[0] = 0;
        }
        else
            turtle[0] -= length;
        break;
    }
}

void view_direction()
{
    switch (direction)
    {
    case E:
        cout << "East\n";
        break;

    case S:
        cout << "South\n";
        break;

    case W:
        cout << "West\n";
        break;

    case N:
        cout << "North\n";
        break;
    }
}
void matrix(int floor[][field_size])
{
    cout << endl;
    for (int i = 0; i < field_size; i++)
    {
        for (int j = 0; j < field_size; j++)
            cout << floor[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
}