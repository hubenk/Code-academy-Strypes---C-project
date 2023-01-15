#include <stdlib.h>
#include "Ships.h"
#include "Defines.h"


Ship *newPhoenixShip()
{
    int size = sizeOfShip();
    Ship *phoenix = malloc(size);
    if(phoenix == NULL)
        return NULL;

    initShipVitalData((Ship*)phoenix,PHOENIX);
    initShield(phoenix,PHOENIX);

    return phoenix;
}

