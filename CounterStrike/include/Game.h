#ifndef COUNTERSTRIKE_GAME_H
#define COUNTERSTRIKE_GAME_H

#include "Player.h"

typedef struct BattleField BattleField;

void initGame(Player **bf);

bool fire(Vector *teamAttacker, Vector *teamDefender);

void prepareBattle(BattleField *bf);

#endif //COUNTERSTRIKE_GAME_H
