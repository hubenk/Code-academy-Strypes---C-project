#ifndef WARCRAFT_SPELLCAST_H
#define WARCRAFT_SPELLCAST_H

#define NOT_ENOUGH_MANA printf("%s - not enough mana to cast %s\n", hero->name, hero->spells[spellType].name)
#define INVALID_ACTION printf("Invalid action!\n")
#define SUCCESSFULL_ULTIMATE printf("%s casted %s for %d mana\n", hero->name, hero->spells[ULTIMATE].name, hero->spells[ULTIMATE].manaCost)
#define SUCCESSFULL_BASIC printf("%s casted %s for %d mana\n", hero->name, hero->spells[BASIC].name, manaCost);

#include "Hero.h"

void castSpells(Hero *Archmage, Hero *DeathKnight, Hero *Drawranger, int spellType);

void castArchmageSpell(Hero *hero, int spellType);

void castDeathKnightSpell(Hero *hero, int spellType);

void castDrawRangerSpell(Hero *hero, int spellType);

void castManaRegenSpell(Hero *hero);

bool castUltimateSpell(Hero *hero, int spellType, int manaCost);

bool castBasicSpell(Hero *hero, int spellType, int manaCost);

#endif//WARCRAFT_SPELLCAST_H
