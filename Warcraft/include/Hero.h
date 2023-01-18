#ifndef HERO_H_
#define HERO_H_

#include "Defines.h"

#include <stdbool.h>

#define MAX_SPELL_NAME_SIZE 20
#define MAX_HERO_NAME_SIZE 20
#define MAX_SPELLS 2

typedef struct Hero Hero;

typedef struct {
    char name[MAX_SPELL_NAME_SIZE];
    int manaCost;
} Spell;

struct Hero {
    Spell spells[MAX_SPELLS];
    char name[MAX_HERO_NAME_SIZE];
    int maxMana;
    int currMana;
    int manaRegenRate;
    int regenModifier;

    void (*regenerateMana)(Hero *hero);

    void (*expellHero)(Hero *hero);
};

void heroSpellsInit(Hero *hero, const char *basicSpellName, int basicSpellManaCost, const char *ultimateSpellName,
                    int ultimateSpellManaCost);

void setCurrentMana(Hero *hero, int newManaValue);

int getCurrentMana(Hero *hero);

void heroDeInit(Hero *hero);

Hero *makeArchmage(const char *inputName, int inputMaxMana, int inputManaRegenRate, int manaRegenModifier);

Hero *makeNonArchmage(const char *inputName, int inputMaxMana, int inputManaRegenRate, int heroNum);

#endif /* HERO_H_ */
