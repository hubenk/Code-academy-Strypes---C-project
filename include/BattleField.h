#ifndef BATTLEFIELD_H_
#define BATTLEFIELD_H_

#include "Vector.h"
#include "Team.h"

typedef struct BattleField BattleField;
typedef struct Vector Vector;

struct BattleField {
    Vector teamTerrorist;
    Vector teamCounterTerrorist;
};

void createTeams(BattleField *bf);

void startBattle(BattleField *bf);

void endGame(BattleField *bf);

Vector *getTeamTerrorist(BattleField *bf);

Vector *getTeamCounterTerrorist(BattleField *bf);

#endif /* BATTLEFIELD_H_ */