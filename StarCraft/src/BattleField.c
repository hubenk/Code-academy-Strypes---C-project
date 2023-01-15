#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BattleField.h"
#include "Defines.h"
#include "Ships.h"
#include "TerranBCruiser.h"
#include "TerranViking.h"
#include "ProtossCarrier.h"
#include "ProtossPhoenix.h"
#include "Game.h"

struct BattleField{
    Vector* Fleets;
};

Ship *(*new[SHIP_TYPES])() = {(Ship *(*)()) newBCruiserShip, (Ship *(*)()) newVikingShip,
                              (Ship *(*)()) newCarrierShip, (Ship *(*)()) newPhoenixShip};

BattleField* initGame(const char *terranFleetStr, const char* protossFleetStr){
    BattleField* bf = malloc(NUMBER_OF_FLEETS * sizeof(Vector*));
    if(bf == NULL)
        return NULL;
    for(int i = 0; i < NUMBER_OF_FLEETS; ++i){
        bf[i] =  malloc(sizeof(Vector));
        if(bf[i] == NULL)
            return NULL;
    }
    generateTerranFleet(bf, terranFleetStr);
    generateProtossFleet(bf, protossFleetStr);
    return bf;
}
void generateTerranFleet(BattleField *battleField, const char *terranFleetStr)
{
    size_t maxLengthTerran = 0;
    void *item = NULL;
    maxLengthTerran = strlen(terranFleetStr);

    vectorInit((Vector *) battleField[TERRAN_FLEET], maxLengthTerran);

    for (int i = 0; i < (int) maxLengthTerran; i++)
    {
        if (terranFleetStr[i] == 'b')
        {
            item = (void *) new[BATTLE_CRUISER]();
            if(item == NULL)
                return;
            vectorPush((Vector *) battleField[TERRAN_FLEET], item);
        } else if (terranFleetStr[i] == 'v')
        {
            item = (void *) new[VIKING]();
            vectorPush((Vector *) battleField[TERRAN_FLEET], item);
        } else
        {
            fprintf(stderr, "Invalid Battleship type!\n");
        }
    }
}

void generateProtossFleet(BattleField *battleField, const char *protossFleetStr)
{
    size_t maxLengthProtos = 0;
    maxLengthProtos = strlen(protossFleetStr);
    void *item = NULL;
    vectorInit((Vector *) battleField[1], maxLengthProtos);

    for (int i = 0; i < (int) maxLengthProtos; i++)
    {
        if (protossFleetStr[i] == 'p')
        {
            item = (void *) new[PHOENIX]();
            vectorPush((Vector *) battleField[PROTOS_FLEET], item);
        } else if (protossFleetStr[i] == 'c')
        {
            item = (void *) new[CARRIER]();
            vectorPush((Vector *) battleField[PROTOS_FLEET], item);
        } else
        {
            fprintf(stderr, "Invalid Battleship type!\n");
        }
    }
}

void startBattle(BattleField *battleField)
{
    while (true)
    {
        if (processTerranTurn(battleField))
        {
            printf("TERRAN has won!\n");
            break;
        }
        if (processProtossTurn(battleField))
        {
            printf("PROTOSS has won!\n");
            break;
        }
    }
}

void deinit(BattleField *battleField)
{
    vectorErase((Vector*)battleField[TERRAN_FLEET],BEGIN);
    vectorFree((Vector*)battleField[TERRAN_FLEET]);
    vectorErase((Vector*)battleField[PROTOS_FLEET],BEGIN);
    vectorFree((Vector*)battleField[PROTOS_FLEET]);
    for(int i  = 0; i< 2; ++i){
        free(battleField[i]);
        battleField[i] = NULL;
    }
    free(battleField);
    battleField = NULL;
}

