#include <stdio.h>

#include "SpellCast.h"
#include "Hero.h"

void castSpells(Hero *Archmage, Hero *DeathKnight, Hero *Drawranger, int spellType)
{
    castArchmageSpell(Archmage, spellType);
    castDeathKnightSpell(DeathKnight, spellType);
    castDrawRangerSpell(Drawranger, spellType);
}

void castArchmageSpell(Hero *hero, int spellType)
{
    bool successfullCast = false;
    int manaCost = 0;

    switch (spellType)
    {
        case BASIC:
            manaCost = hero->spells[BASIC].manaCost;
            successfullCast = castBasicSpell(hero, spellType, manaCost);
            break;

        case ULTIMATE:
            manaCost = hero->spells[ULTIMATE].manaCost;
            successfullCast = castUltimateSpell(hero, spellType, manaCost);

            if (successfullCast)
            {
                hero->regenerateMana(hero);
            }
            break;

        case REGENERATE_MANA:
            hero->regenerateMana(hero);
            break;

        default:
            INVALID_ACTION;
            break;
    }
}


void castDeathKnightSpell(Hero *hero, int spellType)
{
    bool successfullCast = false;
    int manaCost = 0;

    switch (spellType)
    {
        case BASIC:
            manaCost = hero->spells[BASIC].manaCost;
            successfullCast = castBasicSpell(hero, spellType, manaCost);
            break;

        case ULTIMATE:
            manaCost = hero->spells[ULTIMATE].manaCost;
            successfullCast = castUltimateSpell(hero, spellType, manaCost);

            if (successfullCast)
            {
                manaCost = 0;
                spellType = BASIC;

                successfullCast = castBasicSpell(hero, spellType, manaCost);
            }
            break;

        case REGENERATE_MANA:
            hero->regenerateMana(hero);
            break;

        default:
            INVALID_ACTION;
            break;
    }
}

void castDrawRangerSpell(Hero *hero, int spellType)
{
    bool successfullCast = false;
    int manaCost = 0;

    switch (spellType)
    {
        case BASIC:
            manaCost = hero->spells[BASIC].manaCost;
            successfullCast = castBasicSpell(hero, spellType, manaCost);

            if (successfullCast)
            {
                manaCost = 0;
                spellType = BASIC;

                successfullCast = castBasicSpell(hero, spellType, manaCost);
            }
            break;

        case ULTIMATE:
            manaCost = hero->spells[ULTIMATE].manaCost;
            successfullCast = castUltimateSpell(hero, spellType, manaCost);
            break;

        case REGENERATE_MANA:
            hero->regenerateMana(hero);
            break;

        default:
            INVALID_ACTION;
            break;
    }
}


bool castUltimateSpell(Hero *hero, int spellType, int manaCost)
{
    int currentMana = getCurrentMana(hero);
    int difference = 0;

    if (manaCost > currentMana)
    {
        NOT_ENOUGH_MANA;
        return false;
    } else
    {
        SUCCESSFULL_ULTIMATE;
        difference = currentMana - manaCost;
        setCurrentMana(hero, difference);
        return true;
    }
}


bool castBasicSpell(Hero *hero, int spellType, int manaCost)
{
    int currentMana = getCurrentMana(hero);
    int difference = 0;

    if (manaCost > currentMana)
    {
        NOT_ENOUGH_MANA;
        return false;
    } else if (manaCost == 0)
    {
        manaCost = 0;
        SUCCESSFULL_BASIC;
        return true;
    } else
    {
        difference = currentMana - manaCost;
        setCurrentMana(hero, difference);
        SUCCESSFULL_BASIC;
        return true;
    }
}


void castManaRegenSpell(Hero *hero)
{
    int manaToRegen = 0;

    manaToRegen = (hero->regenModifier) * (hero->manaRegenRate);

    if ((manaToRegen + (hero->currMana)) >= (hero->maxMana))
    {
        setCurrentMana(hero, (hero->maxMana));
    } else
    {
        (hero->currMana) += manaToRegen;
    }
}
