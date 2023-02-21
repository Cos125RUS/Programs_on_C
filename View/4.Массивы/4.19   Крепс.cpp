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
    int sum, my_point, 
        counter = 0,
        total_won = 0,
        total_lost = 0,
        winner[21] = { 0 },
        losser[21] = { 0 };
    double probability_won = 0,
        probability_lost = 0,
        average = 0,
        ratio[21] = { 0 };
    Status game_status;

    srand(time(0));

    for (int i = 0; i < 1000; i++)
    {
        sum = roll_dice();
        counter = 0;

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
            counter++;

            if (sum == my_point)
                game_status = WON;
            else
                if (sum == 7)
                    game_status = LOST;
        }

        if (counter > 20)
            counter = 20;

        if (game_status == WON)
        {
            cout << "Player is WON!" << endl << endl;
            ++winner[counter];
        }
        else
        {
            cout << "Player is LOST" << endl << endl;
            ++losser[counter];
        }
    }

    for (int i = 0; i < 21; i++)
    {
        total_won += winner[i];
        total_lost += losser[i];
        average += (winner[i] + losser[i]) * (i + 1);
        ratio[i] = (0.00001 + winner[i]) / (0.00001 + losser[i]);
    }

    cout << endl << endl << setw(4) << '№' << setw(9) << "Winner" << setw(13) << "Losser" << setw(10) << "Ratio" << endl;

    for (int i = 0; i < 20; i++)
        cout << setw(4) << i + 1 << setw(8) << winner[i] << setw(12) << losser[i] 
        << setw(12) << setprecision(2) << ratio[i] << endl;
    cout << setw(5) << "21+" << setw(7) << winner[20] << setw(11) << losser[20] 
        << setw(11) << setprecision(2) << ratio[20] << endl;

    probability_won = static_cast<double>(total_won) / 1000;
    probability_lost = static_cast<double>(total_lost) / 1000;

    cout << endl << endl << "Winners - " << total_won << endl
        << "Lossers - " << total_lost << endl
        << "Probability Won - " << probability_won * 100 << "%" << endl
        << "Probability Lost - " << probability_lost * 100 << "%" << endl 
        << "Average nomber of the game - " << average/1000 << endl
        << endl << endl;





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