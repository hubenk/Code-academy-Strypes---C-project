#ifndef PLAYER_H_
#define PLAYER_H_

#include <stdbool.h>
#include "Defines.h"
#include "Pistol.h"
#include "Vector.h"


typedef struct Player Player;
typedef struct Vector Weapons;

Player *initPlayer(int i);

bool hasHealth(Player *enemy);

int getHealth(Player *player);

int getPlayerID(Player *player);

int getArmour(Player *player);

void setVitalData(Player *player, int health, int armour);

void takeDamage(Player *attacker, Player *enemy);

void takeWeapon(Player *player, void *weapon);

void setWeaponInUse(Player *player, Pistol *pistol);

#endif /* PLAYER_H_ */
