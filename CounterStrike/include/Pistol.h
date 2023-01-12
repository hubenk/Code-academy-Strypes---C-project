#ifndef COUNTERSTRIKE_PISTOL_H
#define COUNTERSTRIKE_PISTOL_H

#include "Player.h"

typedef struct Pistol Pistol;
typedef struct Player Player;

struct Weapons initPistol(int NrOfWeapons);

Pistol *newPistol(void);

void reloadPistol(Pistol *pistol);

void initialLoadWeapon(Pistol *pistol);

int getWeaponType(Pistol *pistol);

void updateClipAfterShoot(Pistol *pistol);

Pistol *getWeapon(Player *player);

int getWeaponDamage(Pistol *pistol);

bool pistolShoot(Player *attacker, Player *enemy);

void printRemainingAmmoLog(Pistol *pistol);


#endif //COUNTERSTRIKE_PISTOL_H
