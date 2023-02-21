#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    const int plane_size = 10;
    int plane[plane_size] = { 0 },
        smoking, tickets, answer, 
        i = 10,        
        smok_counter = 0,
        non_smok_counter = 0;

    while (i > 0)
    {
        cout << setw(12) << ' ' << " [1][2][3][4][5]" << endl
            << setw(12) << "Smoking";
        for (int seats = 0; seats < plane_size-5; seats++)
        {
            cout << setw(3) << plane[seats];
        }
        cout << endl << setw(12) << "Non-smoking";
        for (int seats = 5; seats < plane_size; seats++)
        {
            cout << setw(3) << plane[seats];
        }
                
        cout << "\n\n1- smoking salon / 2 - non-smoking salon : ";
        cin >> smoking;
        
        while (smoking != 1 && smoking != 2)
        {
            cout << "Error!\nEnter only 1 or 2: ";
            cin >> smoking;
        }

        if (smoking == 1)
            if (smok_counter < 5)
            {
                ++plane[smok_counter];
                smok_counter++;
                tickets = smok_counter;
                cout << endl << "Your seat in the ";
                if (tickets < 5)
                    cout << "smoking";
                else
                    cout << "non-smoking";
                cout << " lounge.\nSeat number - " << tickets << endl << endl;
            }
            else
            {
                cout << "Seats in the smoking lounge are over\n"
                    "If you agree to purchase a seat in a non-smoking salon, enter 1, if you do not agree, enter 2 : ";
                cin >> answer;
                while (answer != 1 && answer != 2)
                {
                    cout << "Error!\nEnter only 1 or 2: ";
                    cin >> answer;
                }
                if (answer == 1)
                {
                    ++plane[non_smok_counter + 5];
                    non_smok_counter++;
                    tickets = non_smok_counter;
                    cout << endl << "Your seat in the ";
                    if (tickets < 5)
                        cout << "smoking";
                    else
                        cout << "non-smoking";
                    cout << " lounge.\nSeat number - " << tickets << endl << endl;
                }
                else
                {
                    cout << "\nThe next plane departs in 3 hours.\n\n";
                    i++;
                }
            }
        else
        {
            if (non_smok_counter < 5)
            {
                ++plane[non_smok_counter + 5];
                non_smok_counter++;
                tickets = non_smok_counter;
                cout << endl << "Your seat in the ";
                if (tickets < 5)
                    cout << "smoking";
                else
                    cout << "non-smoking";
                cout << " lounge.\nSeat number - " << tickets << endl << endl;
            }
            else
            {
                cout << "Seats in the non-smoking lounge are over\n"
                    "If you agree to purchase a seat in a smoking salon, enter 1, if you do not agree, enter 2";
                cin >> answer;
                while (answer != 1 && answer != 2)
                {
                    cout << "Error!\nEnter only 1 or 2: ";
                    cin >> answer;
                }
                if (answer == 1)
                {
                    ++plane[smok_counter];
                    smok_counter++;
                    tickets = smok_counter;
                    cout << endl << "Your seat in the ";
                    if (tickets < 5)
                        cout << "smoking";
                    else
                        cout << "non-smoking";
                    cout << " lounge.\nSeat number - " << tickets << endl << endl;
                }
                else
                {
                    cout << "\nThe next plane departs in 3 hours.\n\n";
                    i++;
                }                    
            }
        }        
        i--;
    }
    
    cout << "Seats on the flight ran out.\nThe next plane departs in 3 hours.";




    cout << "\n\n\n\n\n\n\n\n\n\n";

    return 0;
}
