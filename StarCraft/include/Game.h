//
// Created by x on 10.08.22.
//

#ifndef STARCRAFT_GAME_H
#define STARCRAFT_GAME_H

#include "Ships.h"

void protossAttack(Ship* attackingShip, Ship* defendingShip, int round, Vector* enemyFleet);
void terranAttack (Ship* attackingShip, Ship* enemyShip, int round, Vector* enemyFleet);

bool processTerranTurn(BattleField *);
bool processProtossTurn(BattleField *);

#endif //STARCRAFT_GAME_H
