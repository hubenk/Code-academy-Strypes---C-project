#include <stdio.h>
#include <stdlib.h>

#include "BattleField.h"
#include "Pistol.h"
#include "Player.h"
#include "Team.h"
#include "Vector.h"
#include "Game.h"

void createTeams(BattleField *bf)
{
    vectorInit(&bf->teamTerrorist, (size_t) TEAM_SIZE);
    vectorInit(&bf->teamCounterTerrorist, (size_t) TEAM_SIZE);
    int number = 0;
    for (int i = 0; i < TEAM_SIZE; ++i)
    {
        Player *teamMemTerrorist = initPlayer(number);
        number++;
        Player *teamMemCounter = initPlayer(number);
        Pistol *pistolTerrorist = newPistol();
        Pistol *pistolCounter = newPistol();
        takeWeapon(teamMemTerrorist, pistolTerrorist);
        takeWeapon(teamMemCounter, pistolCounter);
        setWeaponInUse(teamMemTerrorist, pistolTerrorist);
        setWeaponInUse(teamMemCounter, pistolCounter);
        vectorPush(&bf->teamTerrorist, teamMemTerrorist);
        vectorPush(&bf->teamCounterTerrorist, teamMemCounter);
    }
}

void startBattle(BattleField *bf)
{
    bool play = true;
    prepareBattle(bf);

    while (play)
    {
        play = fire(&bf->teamTerrorist, &bf->teamCounterTerrorist);
        NEW_LINE;

        if (play == false)
        {
            break;
        }
        play = fire(&bf->teamCounterTerrorist, &bf->teamTerrorist);
        NEW_LINE;
    }
}

Vector *getTeamTerrorist(BattleField *bf)
{

    return &bf->teamTerrorist;
}

Vector *getTeamCounterTerrorist(BattleField *bf)
{
    return &bf->teamCounterTerrorist;
}

void endGame(BattleField *battleField)
{

    int sizeTerrorists = vectorGetSize(&battleField->teamTerrorist);
    int sizeCounterTerrorists = vectorGetSize(&battleField->teamCounterTerrorist);

    for (int i = 0; i < sizeTerrorists; ++i)
    {
        Player *player = vectorGet(&battleField->teamTerrorist, i);
        Pistol *pistol = getWeapon(player);
        free(pistol);
        pistol = NULL;
        free(player);
        player = NULL;
    }
    vectorFree(&battleField->teamTerrorist);

    for (int i = 0; i < sizeCounterTerrorists; ++i)
    {
        Player *player = vectorGet(&battleField->teamCounterTerrorist, i);
        Pistol *pistol = getWeapon(player);
        free(pistol);
        pistol = NULL;
        free(player);
        player = NULL;
    }
    vectorFree(&battleField->teamCounterTerrorist);
}
