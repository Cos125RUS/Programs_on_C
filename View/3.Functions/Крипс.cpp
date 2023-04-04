#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int roll_dice(void);
int main()
{
    setlocale(LC_ALL, "Russian");

    enum Status {CONTINUE, WON, LOST};
    int sum, my_point;
    Status game_status;

    srand(time(0));

    sum = roll_dice();

    switch (sum)
    {
    case 7:
    case 11:
        game_status = WON;
        break;

    case 2:
    case 3:
    case 12:
        game_status = LOST;
        break;

    default:
        game_status = CONTINUE;
        my_point = sum;
        cout << "Points: " << my_point << endl;
        break;
    }

    while (game_status == CONTINUE)
    {
        sum = roll_dice();

        if (sum == my_point)
            game_status = WON;
        else
            if (sum == 7)
                game_status = LOST;
    }

    if (game_status == WON)
        cout << "Player is WON!" << endl;
    else
        cout << "Player is LOST" << endl;

    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}
int roll_dice(void)
{
    int die1, die2, work_sum;

    die1 = 1 + rand() % 6;
    die2 = 1 + rand() % 6;
    work_sum = die1 + die2;
    cout << die1 << " + " << die2 << " = " << work_sum << endl;

    return work_sum;
}