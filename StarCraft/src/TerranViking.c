#include <stdlib.h>
#include "Defines.h"
#include "Ships.h"

Ship *newVikingShip()
{
    int size = sizeOfShip();
    Ship *viking = malloc(size);
    if(viking == NULL)
        return NULL;
    initShipVitalData((Ship*)viking,VIKING);

    return viking;
}

