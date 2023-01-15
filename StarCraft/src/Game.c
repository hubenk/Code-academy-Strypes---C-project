
#include <stdio.h>
#include "Ships.h"

void protossAttack(Ship *attackingShip, Ship * defendingShip, int round, Vector *enemyFleet)
{
    size_t lastShipIndex = vectorGetSize(enemyFleet) - 1;

    int attackDamage = getDamage(attackingShip,defendingShip);
    int enemyHealth = getHealth(defendingShip);

    int shipType = getShipType( attackingShip);

    regenShield(attackingShip);

    if (shipType == CARRIER)
    {
        int attackerHealth = getHealth(attackingShip);
        int interceptors = MAX_INTERCEPTORS;
        if (attackerHealth < CARRIER_HEALTH)
        {
            interceptors = DAMAGED_STATUS_INTERCEPTORS;
        }

        for (int i = 0; i < interceptors; i++)
        {
            enemyHealth -= attackDamage;

            if (enemyHealth <= 0)
            {
                printKillLog(attackingShip, round, lastShipIndex);
                vectorPop(enemyFleet);
                defendingShip = (Ship *) vectorBack(enemyFleet);
                lastShipIndex = (size_t) vectorGetSize(enemyFleet) - 1;
                if (enemyFleet->size == 0)
                {
                    return;
                }
                enemyHealth = getHealth(defendingShip);
            }
        }
        setHealth(defendingShip, enemyHealth);
    }
    else if (shipType == PHOENIX)
    {
        enemyHealth -= attackDamage;

        if (enemyHealth <= 0)
        {
            printKillLog(attackingShip, round, lastShipIndex);
            vectorPop(enemyFleet);
            return;
        }
        setHealth(defendingShip, enemyHealth);
    }
}
void terranAttack(Ship *attackingShip, Ship *defendingShip, int round, Vector *enemyFleet)
{
    size_t lastShipIndex = vectorGetSize(enemyFleet) - 1;
    int attackerShipType = getShipType(attackingShip);
    int remainingDamage = 0;
    int enemyHealth = getHealth(defendingShip);
    int enemyShieldLeft = getShield(defendingShip);
    int attackDamage = getDamage(attackingShip,defendingShip);
    if (attackerShipType == BATTLE_CRUISER)
    {
        setYamato(attackingShip);
    }


    if (attackDamage >= enemyShieldLeft)
    {
        remainingDamage = attackDamage - enemyShieldLeft;
        enemyShieldLeft = 0;
        setShield( defendingShip, enemyShieldLeft);
        enemyHealth -= remainingDamage;
    } else
    {
        enemyShieldLeft -= attackDamage;
        setShield(defendingShip, enemyShieldLeft);
    }

    if (enemyHealth <= 0)
    {
        printKillLog(attackingShip, round, lastShipIndex);
        vectorPop(enemyFleet);

        return;
    }
    setHealth(defendingShip, enemyHealth);
}
bool processTerranTurn(BattleField *battleField)
{
    int round = 0;
    size_t lastShipIndex = (size_t) vectorGetSize((Vector*)battleField[PROTOS_FLEET]) - 1;

    Ship *attackingShip = (Ship *) vectorGet((Vector*)battleField[TERRAN_FLEET], round);
    Ship *enemyShip = (Ship *) vectorBack((Vector*)battleField[PROTOS_FLEET]);

    while (true)
    {
        terranAttack(attackingShip, enemyShip, round, (Vector*)battleField[PROTOS_FLEET]);

        round++;

        attackingShip = (Ship *) vectorGet((Vector*)battleField[TERRAN_FLEET], round);
        enemyShip = (Ship *) vectorBack((Vector*)battleField[PROTOS_FLEET]);
        lastShipIndex = (size_t) vectorGetSize((Vector*)battleField[PROTOS_FLEET]) - 1;

        if (vectorGetSize((Vector*)battleField[PROTOS_FLEET]) == 0)
        {
            return true;
        }
        if (attackingShip == NULL)
        {
            break;
        }
    }
    printf("Last Protoss AirShip with ID: %zu has %d health and %d shield left\n",
           lastShipIndex, getHealth(enemyShip), getShield( enemyShip));

    return false;
}

bool processProtossTurn(BattleField *battleField)
{
    int round = 0;
    size_t lastShipIndex = (size_t) vectorGetSize((Vector*)battleField[TERRAN_FLEET]) - 1;

    Ship *attackingShip = (Ship *) vectorGet((Vector*)battleField[PROTOS_FLEET], round);
    Ship *enemyShip = (Ship *) vectorBack((Vector*)battleField[TERRAN_FLEET]);

    while (true)
    {
        protossAttack(attackingShip, enemyShip, round, (Vector*)battleField[TERRAN_FLEET]);

        round++;

        attackingShip = (Ship *) vectorGet((Vector*)battleField[PROTOS_FLEET], round);
        enemyShip = (Ship *) vectorBack((Vector*)battleField[TERRAN_FLEET]);
        lastShipIndex = (size_t) vectorGetSize((Vector*)battleField[TERRAN_FLEET]) - 1;

        if (vectorGetSize((Vector*)battleField[TERRAN_FLEET]) == 0)
        {
            return true;
        }

        if (attackingShip == NULL)
        {
            break;
        }
    }
    printf("Last Terran AirShip with ID: %zu has %d health left\n",
           lastShipIndex, getHealth(enemyShip));

    return false;
}