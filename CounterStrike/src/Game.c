#include "BattleField.h"
#include "Player.h"
#include "Team.h"
#include "Game.h"
#include "PrintLogs.h"
#include "Pistol.h"

typedef struct BattleField BattleField;

void prepareBattle(BattleField *bf)
{
    Vector *terrorists = getTeamTerrorist(bf);
    Vector *counterTerrorists = getTeamCounterTerrorist(bf);
    int sizeTerorrists = (int) vectorGetSize(terrorists),
            sizeConters = (int) vectorGetSize(counterTerrorists);

    for (int i = 0; i < sizeTerorrists; ++i)
    {
        Pistol *weapon = getWeapon(vectorGet(terrorists, i));
        initialLoadWeapon(weapon);
    }
    for (int i = 0; i < sizeConters; ++i)
    {
        Pistol *weapon = getWeapon(vectorGet(counterTerrorists, i));
        initialLoadWeapon(weapon);
    }
}

bool fire(Vector *teamAttacker, Vector *teamDefender)
{

    bool result = 0;
    int sizeAttacker = vectorGetSize(teamAttacker);
    int sizeDefender = vectorGetSize(teamDefender);

    for (int i = 0, j = 0; i < sizeAttacker && j < sizeDefender; ++i, ++j)
    {
        Player *teamMemAttacker = (Player *) vectorGet(teamAttacker, 0);
        Player *teamMemDefender = (Player *) vectorGet(teamDefender, 0);
        printGameLog(teamMemAttacker);

        result = pistolShoot(teamMemAttacker, teamMemDefender);

        vectorSet(teamAttacker, 0, teamMemAttacker);
        vectorSet(teamDefender, 0, teamMemDefender);
    }

    return result;
}



