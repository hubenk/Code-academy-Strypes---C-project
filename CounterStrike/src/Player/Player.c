#include <stdlib.h>
#include "Player.h"
#include "PrintLogs.h"

typedef struct {
    int health;
    int armor;
} PlayerVitalData;

struct Player {
    PlayerVitalData playerData;
    int playerId;
    int weaponInUse;
    Pistol *pistol;
};


Player *initPlayer(int i)
{
    int playerHealth = 0,
            playerArmor = 0;
    int vitalAttrib = scanf("%d %d", &playerHealth, &playerArmor);
    Player *player = NULL;

    if (vitalAttrib == PLAYERS_ATTRIB)
    {
        player = malloc(sizeof(Player));
        if (player == NULL)
        {
            fprintf(stderr, "Invalid memory allocation!\n");
        }
    } else
    {
        fprintf(stderr, "Invalid vital data input!\n");
    }

    player->playerData.health = playerHealth;
    player->playerData.armor = playerArmor;
    player->playerId = i;

    return player;
}
void buyWeapon(Player* player){
    player->pistol = newPistol();
}
void preparePlayerForBattle(Player* player){
    initialLoadWeapon(player->pistol);
}

bool hasHealth(Player *enemy)
{
    if (enemy->playerData.health > 0)
        return true;
    else
        return false;
}

int getHealth(Player *player)
{
    return player->playerData.health;
}

int getPlayerID(Player *player)
{
    return player->playerId;
}

int getArmour(Player *player)
{
    return player->playerData.armor;
}

void setVitalData(Player *player, int health, int armour)
{
    player->playerData.health = health;
    player->playerData.armor = armour;
}

Pistol *getWeapon(Player *player)
{
    return player->pistol;
}

bool takeDamage(Player *attacker, Player *enemy)
{
    int enemyHealth = getHealth(enemy);
    int enemyArmour = getArmour(enemy);
    int damage = pistolDamage(attacker->pistol);
    int weapon_type = getWeaponType(attacker->pistol);
    int DamageToArmour = (int) (damage * DAMAGE_ARMOUR[weapon_type]);
    int DamageToBody = (int) (damage * DAMAGE_BODY[weapon_type]);
    int NrOfShots = pistolShots(attacker->pistol);

    for (int i = 0; i < NrOfShots; ++i){

        if (enemyArmour > 0)
        {
            if (DamageToArmour >= enemyArmour)
            {
                enemyHealth -= DamageToArmour - enemyArmour;
                enemyArmour = 0;

            } else
            {
                enemyArmour -= DamageToArmour;
            }
            enemyHealth -= DamageToBody;
        }
        else{
            enemyHealth -= damage;
        }


        if(!clipIsEmpty(attacker->pistol)){

            updateClipAfterShoot(attacker->pistol);
            setVitalData(enemy, enemyHealth, enemyArmour);
            printEnemyLog(enemy);
        }

        else{
            reloadPistol(attacker->pistol);
            break;
        }
        if (enemy->playerData.health <= 0)
        {
            NEW_LINE;
            printWinnerLog(attacker);
            return false;
        }
    }

    return true;
}
void freePlayer(Player* player){
    if(player == NULL)
        return;
    else{
        freePistol(player->pistol);
        free(player);
        player = NULL;
    }
}