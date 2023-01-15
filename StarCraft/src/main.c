#include <stdio.h>
#include <stdlib.h>

#include "BattleField.h"
#include "Ships.h"

int main()
{

    const int buffSize = 50;
    char terranFleet[buffSize];
    char protossFleet[buffSize];
    scanf("%s %s", terranFleet, protossFleet);

    BattleField* battleField = initGame(terranFleet, protossFleet);

    startBattle(battleField);
    deinit(battleField);


    return EXIT_SUCCESS;
}
