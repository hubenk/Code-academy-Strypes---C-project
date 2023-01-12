#ifndef COUNTERSTRIKE_VECTOR_H
#define COUNTERSTRIKE_VECTOR_H

#include <stdbool.h>
#include <stddef.h>

typedef struct BattleField BattleField;
typedef struct Vector Vector;
struct Vector {
    void **items;
    size_t capacity;
    size_t size;
};

void vectorInit(Vector *vec, size_t initialCapacity);

size_t vectorGetSize(Vector *vec);

bool vectorIsEmpty(Vector *vec);

void vectorResize(Vector *vec, size_t newSize);

void vectorPush(Vector *vec, void *elem);

void vectorSet(Vector *vec, size_t idx, void *elem);

void *vectorGet(Vector *vec, size_t idx);

void *vectorBack(Vector *vec);

void vectorDelete(Vector *vec, size_t idx);

void vectorPop(Vector *vec);

void vectorFree(Vector *vec);

void vectorFree1(Vector vec);

Vector *getTeamCounterTerrorist(BattleField *bf);

Vector *getTeamTerrorist(BattleField *bf);

#endif //COUNTERSTRIKE_VECTOR_H
