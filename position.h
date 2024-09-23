#ifndef POSITION_H
#define POSITION_H

#include <stdbool.h>
#include <stddef.h>

typedef struct Position {
  int x;
  int y;
} Position;

Position* PositionInit(int x, int y);

Position* PositionAdd(Position* a, Position* b);

bool PositionEqual(Position* a, Position* b);

void PositionPrint(Position* p);

void AppendElement(void** arr, size_t *len, void* element, size_t elementSize);

void AppendPosition(Position** arr, size_t *len, Position* element, size_t elementSize);

void *RemoveFromBack(void **arr, size_t *len, size_t elementSize);

Position* RemovePositionFromBack(Position **arr, size_t *len, size_t elementSize);

#endif