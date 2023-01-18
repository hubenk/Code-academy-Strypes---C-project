#include <stdlib.h>
#include <string.h>
#include "Hero.h"
#include "Defines.h"
#include "SpellCast.h"


Hero *makeArchmage(const char *inputName, int inputMaxMana, int inputManaRegenRate, int manaRegenModifier)
{
    Hero *hero = malloc(sizeof(Hero));
    strcpy(hero->name, inputName);
    hero->maxMana = inputMaxMana;
    hero->currMana = inputMaxMana;
    hero->manaRegenRate = inputManaRegenRate;
    hero->regenModifier = manaRegenModifier;

    heroSpellsInit(hero, ARCHMAGE_BASIC_SPELL_NAME, ARCHMAGE_BASIC_SPELL_MANA_COST,
                   ARCHMAGE_ULTIMATE_SPELL_NAME, ARCHMAGE_ULTIMATE_SPELL_MANA_COST);

    return hero;
}

Hero *makeNonArchmage(const char *inputName, int inputMaxMana, int inputManaRegenRate, int heroNum)
{
    Hero *hero = malloc(sizeof(Hero));
    strcpy(hero->name, inputName);
    hero->maxMana = inputMaxMana;
    hero->currMana = inputMaxMana;
    hero->manaRegenRate = inputManaRegenRate;
    hero->regenModifier = 1;

    if (heroNum == 1)
    {
        heroSpellsInit(hero, DEATH_KNIGHT_BASIC_SPELL_NAME, DEATH_KNIGHT_BASIC_SPELL_MANA_COST,
                       DEATH_KNIGHT_ULTIMATE_SPELL_NAME, DEATH_KNIGHT_ULTIMATE_SPELL_MANA_COST);
    } else if (heroNum == 2)
    {
        heroSpellsInit(hero, DRAW_RANGER_BASIC_SPELL_NAME, DRAW_RANGER_BASIC_SPELL_MANA_COST,
                       DRAW_RANGER_ULTIMATE_SPELL_NAME, DRAW_RANGER_ULTIMATE_SPELL_MANA_COST);
    }

    return hero;
}


void heroSpellsInit(Hero *hero, const char *basicSpellName, int basicSpellManaCost, const char *ultimateSpellName,
                    int ultimateSpellManaCost)
{
    strcpy(hero->spells[BASIC].name, basicSpellName);
    hero->spells[BASIC].manaCost = basicSpellManaCost;
    strcpy(hero->spells[ULTIMATE].name, ultimateSpellName);
    hero->spells[ULTIMATE].manaCost = ultimateSpellManaCost;
    hero->regenerateMana = &castManaRegenSpell;
    hero->expellHero = &heroDeInit;
}


void setCurrentMana(Hero *hero, int newManaValue)
{
    (hero->currMana) = newManaValue;
}


int getCurrentMana(Hero *hero)
{
    return (hero->currMana);
}


void heroDeInit(Hero *hero)
{
    free(hero);
}
