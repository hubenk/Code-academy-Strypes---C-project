#ifndef BATTLEFIELD_H_
#define BATTLEFIELD_H_

#include "Vector.h"
#include <stdbool.h>

typedef struct Vector* BattleField;

BattleField* initGame(const char *terranFleetStr, const char* protossFleetStr);
void generateTerranFleet(BattleField *, const char *);
void generateProtossFleet(BattleField *, const char *);

void startBattle(BattleField *);

void deinit(BattleField *);


#endif /* BATTLEFIELD_H_ */
