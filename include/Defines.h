#ifndef DEFINES_H_
#define DEFINES_H_

#include <stdio.h>
#include <stdbool.h>

#define NEW_LINE printf("\n");
#define RELOAD printf("Reloading...\n");
#define NO_AMMO printf("No ammo left\n");
#define TEAM_SIZE 1
#define INVENTORY_SIZE 1
#define PLAYERS_ATTRIB 2
#define DAMAGE_BODY (float[]){0.5 , 0.75}
#define DAMAGE_ARMOUR (float[]){0.5 , 0.25}
#define WEAPON_TYPE (int[]){GLOCK , DESERT_EAGLE}
#define PLAYER_INDEX 0

enum PlayerDefines {
    PLAYER_ONE,
    PLAYER_TWO,
    PLAYERS_COUNT
};

//In future development could be included in WeaponType
enum PistolType {
    GLOCK,
    DESERT_EAGLE,
    WEAPON_COUNT
};

enum GlockDefines {
    GLOCK_ROUNDS_PER_FIRE = 3
};
enum Desert_EagleDefines {
    DESERT_EAGLE_ROUNDS_PER_FIRE = 1
};

enum PistolAttriburtes {
    DAMAGE_ROUND,
    CLIP_SIZE,
    CURR_CLIP_BULLETS,
    REMAINING_AMMO,
    PISTOL_ATTRIB
};


#endif /* DEFINES_H_ */
