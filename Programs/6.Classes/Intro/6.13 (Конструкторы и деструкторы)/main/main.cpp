#include <iostream>
#include <locale>
#include "create.h"

using namespace std;

void create(void);

CreateAndDestroy first(1);

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "   (глобально созданный до main)\n";

    CreateAndDestroy second(2);
    cout << "   (локальный автоматический в main)\n";

    static CreateAndDestroy third(3);
    cout << "   (локальный статический в main)\n";

    create();

    CreateAndDestroy fourth(4);
    cout << "   (локальный автоматический в main)\n";


    return 0;
}

void create(void)
{
    CreateAndDestroy fifth(5);
    cout << "   (локальный автоматический в create)\n";

    static CreateAndDestroy sixth(6);
    cout << "   (локальный статический в create)\n";

    CreateAndDestroy seventh(7);
    cout << "   (локальный автоматический в create)\n";
}