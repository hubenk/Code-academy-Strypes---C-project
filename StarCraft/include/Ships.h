#ifndef STARCRAFT_SHIP_H
#define STARCRAFT_SHIP_H

#include "BattleField.h"
#include "Defines.h"

typedef struct ship Ship;

int sizeOfShip(void);
void initShipVitalData(Ship * ship, int type);
void initShield(Ship * ship, int type);
void initYamato(Ship* ship);
void printKillLog(Ship* ship, int round, size_t lastShipIndex);
int getShield(Ship *currentShip);

void setYamato(Ship *ship);
int getYamatoTurns(Ship *attackingShip);

int   getShipType(Ship* currentShip);
int   getHealth(Ship*  currentShip);
int getDamage(Ship *attackingShip, Ship* enemyShip);
void  setHealth(Ship* ship, int health);
void setShield(Ship* ship, int shield);
void regenShield(Ship *ship);

//void  setDamage(Ship* attackingShip, Ship* defendingShip);

#endif //STARCRAFT_SHIP_H
