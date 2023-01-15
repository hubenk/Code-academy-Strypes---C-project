#include <stdlib.h>
#include "Defines.h"
#include "Ships.h"

Ship *newBCruiserShip()
{
    int size = sizeOfShip();
    Ship *bcruser = malloc(size);
    if(bcruser == NULL)
        return NULL;
    initShipVitalData((Ship*)bcruser,BATTLE_CRUISER);
    initYamato(bcruser);

    return bcruser;
}

