#include <stdio.h>

#include "Ships.h"
#include "Defines.h"

typedef struct Special Special;
struct Special{
    int yamato;
    int shield;
};
struct ship {
    int type;
    int health;
    Special special;
};
int sizeOfShip(){
    return sizeof(Ship);
}
int getShipType(Ship *currentShip)
{
    return currentShip->type;
}

int getDamage(Ship *attackingShip, Ship* enemyShip)
{
    int damage = SHIP_DAMAGE[attackingShip->type];
    int attackingShipType = getShipType(attackingShip);
    int enemyShipType = getShipType(enemyShip);
    if(attackingShipType == BATTLE_CRUISER){
        if(getYamatoTurns(attackingShip) == 0)
            damage = BATTLE_CRUISER_YAMATO_DAMAGE;
    }
    else if(attackingShipType == VIKING){
        if(enemyShipType == PHOENIX)
            damage = VIKING_DAMAGE_VS_PHOENIX;
    }
    else{
        damage = SHIP_DAMAGE[attackingShipType];
    }
    return damage;
}

void initShipVitalData(Ship * ship, int type){
    ship->type = type;
    ship->health = SHIP_HEALTH[type];
}
void initShield(Ship * ship, int type){
    ship->special.shield = PROTOS_SHIP_SHIELD[type];
}
void initYamato(Ship* ship){
    ship->special.yamato = YAMATO_CANNON_LOADING_TURNS;
}
void regenShield(Ship *ship)
{
    ship->special.shield +=PROTOS_SHIP_REGENERATION[ship->type];
    if(ship->special.shield > PROTOS_SHIP_SHIELD[ship->type])
        ship->special.shield = PROTOS_SHIP_SHIELD[ship->type];
}
int getShield(Ship *currentShip)
{
    return currentShip->special.shield;
}
void setShield(Ship* ship, int shield){
    ship->special.shield = shield;
}
int getHealth(Ship *currentShip)
{
    return currentShip->health;
}
void setHealth(Ship *ship, int health)
{
    ship->health = health;
}

void printKillLog(Ship *ship, int round, size_t lastShipIndex)
{
    if (ship->type == BATTLE_CRUISER)
        printf("BattleCruser with ID: %d killed enemy airship with ID: %zu\n",
               round, lastShipIndex);
    if (ship->type == VIKING)
        printf("Viking with ID: %d killed enemy airship with ID: %zu\n",
               round, lastShipIndex);
    if (ship->type == PHOENIX)
        printf("Phoenix with ID: %d killed enemy airship with ID: %zu\n",
               round, lastShipIndex);
    if (ship->type == CARRIER)
        printf("Carrier with ID: %d killed enemy airship with ID: %zu\n",
               round, lastShipIndex);
}

void setYamato(Ship *ship)
{
    if (ship->special.yamato == 0)
        ship->special.yamato = YAMATO_CANNON_LOADING_TURNS;
    else
        ship->special.yamato--;
}

int getYamatoTurns(Ship *attackingShip)
{
    return attackingShip->special.yamato;
}