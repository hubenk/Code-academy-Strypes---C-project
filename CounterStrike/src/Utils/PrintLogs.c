#include "PrintLogs.h"

void printGameLog(Player *player)
{
    int playerLog = getPlayerID(player);
    printf("PlayerID %d turn:\n", playerLog);
}

void printEnemyLog(Player *player)
{
    int enemyHealth = getHealth(player);
    int enemyArmour = getArmour(player);
    printf("Enemy left with: %d health and %d armor\n", enemyHealth, enemyArmour);
}

void printWinnerLog(Player *player)
{
    int playerLog = getPlayerID(player);
    printf("Player with ID: %d wins!\n", playerLog);
}