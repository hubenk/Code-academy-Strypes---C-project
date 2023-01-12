#include <stdlib.h>
#include "Defines.h"
#include "Pistol.h"

struct Pistol {
    int type;
    int damagePerRound;
    int clipSize;
    int currClipBullets;
    int remainingAmmo;
};

int weaponNrOfShoots[WEAPON_COUNT] = {GLOCK_ROUNDS_PER_FIRE, DESERT_EAGLE_ROUNDS_PER_FIRE};

void initialLoadWeapon(Pistol *pistol)
{
    pistol->currClipBullets = pistol->clipSize;
}

int getWeaponType(Pistol *pistol)
{
    return pistol->type;
}

int getWeaponDamage(Pistol *pistol)
{
    return pistol->damagePerRound;
}

void reloadPistol(Pistol *pistol)
{
    if (pistol->remainingAmmo <= 0)
    {
        NO_AMMO;
    } else
    {
        RELOAD;
        if (pistol->remainingAmmo > pistol->clipSize)
        {
            (pistol->currClipBullets) = (pistol->clipSize);
            (pistol->remainingAmmo) -= (pistol->clipSize);
        } else
        {
            (pistol->currClipBullets) = (pistol->remainingAmmo);
            pistol->remainingAmmo = 0;
        }
        printRemainingAmmoLog(pistol);
    }
}

Pistol *newPistol()
{

    int pistolId = 0;
    int pistolDamagePerRound = 0;
    int pistolClipSize = 0;
    int pistolRemainingAmmo = 0;
    int sizeOFAttributes = scanf("%d %d %d %d", &pistolId, &pistolDamagePerRound, &pistolClipSize,
                                 &pistolRemainingAmmo);

    Pistol *gun = NULL;
    if (sizeOFAttributes == PISTOL_ATTRIB)
    {
        gun = malloc(sizeof(Pistol));
    } else
    {
        fprintf(stderr, "Invalid Input!\n");
        return gun;
    }
    gun->type = pistolId;
    gun->damagePerRound = pistolDamagePerRound;
    gun->clipSize = pistolClipSize;
    gun->remainingAmmo = pistolRemainingAmmo;

    return gun;
}

bool clipIsEmpty(Pistol* pistol){
    if(pistol->currClipBullets <= 0) {
        return true;
    }
    else
        return false;
}
void updateClipAfterShoot(Pistol *pistol)
{
        pistol->currClipBullets--;
}

void printRemainingAmmoLog(Pistol *pistol)
{
    printf("currClipBullets: %d, remainingAmmo: %d\n", pistol->currClipBullets, pistol->remainingAmmo);
}

int pistolDamage(Pistol *attacker)
{
    return attacker->damagePerRound;
}

int pistolShots(Pistol *attacker){
    return weaponNrOfShoots[attacker->type];
}
void freePistol(Pistol* pistol){
    if(pistol ==NULL)
        return;
    else{
        free(pistol);
        pistol = NULL;
    }
}