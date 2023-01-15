#include <stdlib.h>
#include "Defines.h"
#include "Ships.h"

Ship *newCarrierShip()
{
    Ship *carrier = NULL;
    int size = sizeOfShip();
    carrier = malloc(size);
    if(carrier == NULL)
        return NULL;

    initShipVitalData((Ship*)carrier,CARRIER);
    initShield(carrier,CARRIER);

    return carrier;
}

