#include <stdlib.h>

#include "BattleField.h"

int main()
{
    BattleField battleField;
    createTeams(&battleField);
    startBattle(&battleField);
    endGame(&battleField);

    return EXIT_SUCCESS;
}
