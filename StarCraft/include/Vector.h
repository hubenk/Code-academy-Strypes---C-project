#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdbool.h>
#include <stddef.h>


typedef struct {
    void **items;
    size_t capacity;
    size_t size;
} Vector;

void vectorInit(Vector *vec, size_t initialCapacity);
size_t vectorGetSize(Vector *vec);
bool vectorIsEmpty(Vector *vec);
void vectorResize(Vector *vec, size_t newSize);
size_t vectorGetCapacity(Vector *v);
void vectorPush(Vector *vec, void *elem);
void vectorSet(Vector *vec, size_t idx, void *elem);
void *vectorGet(Vector *vec, size_t idx);
void *vectorBack(Vector *vec);
void vectorDelete(Vector *vec, size_t idx);
void vectorPop(Vector *vec);
void vectorFree(Vector *vec);
void vectorFree1(Vector vec);

void vectorErase(Vector *vec, size_t idx);
#endif /* VECTOR_H_ */
