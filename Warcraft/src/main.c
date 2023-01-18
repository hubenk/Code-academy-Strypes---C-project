#include <stdio.h>
#include <stdlib.h>
#include "Hero.h"
#include "SpellCast.h"


int main()
{
    char name[MAX_HERO_NAME_SIZE + 1];
    int maxMana = 0;
    int baseManaRegenRate = 0;
    int manaRegenModifier = 0;
    Hero *Heroes[HEROES_COUNT] = {(Hero *) ARCHMAGE, (Hero *) DEATH_KNIGHT, (Hero *) DRAWRANGER};


    for (int i = 0; i < HEROES_COUNT; i++)
    {
        if (i == 0)
        {
            scanf("%s %d %d %d", name, &maxMana, &baseManaRegenRate, &manaRegenModifier);
            Heroes[i] = makeArchmage(name, maxMana, baseManaRegenRate, manaRegenModifier);
        } else
        {
            scanf("%s %d %d", name, &maxMana, &baseManaRegenRate);
            Heroes[i] = makeNonArchmage(name, maxMana, baseManaRegenRate, i);
        }
    }


    int commandsCount = 0;
    int currAction = 0;
    scanf("%d", &commandsCount);

    for (int i = 0; i < commandsCount; ++i)
    {
        scanf("%d", &currAction);
        castSpells(Heroes[ARCHMAGE], Heroes[DEATH_KNIGHT], Heroes[DRAWRANGER], currAction);
    }


    for (int i = 0; i < HEROES_COUNT; i++)
    {
        Heroes[i]->expellHero(Heroes[i]);
    }

    return EXIT_SUCCESS;
}
