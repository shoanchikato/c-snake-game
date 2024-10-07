#ifndef POSITION_H
#define POSITION_H

#include <stdbool.h>

typedef struct {
  int x;
  int y;
} Position;

Position *position_init(int x, int y);

Position *position_add(Position *a, Position *b);

bool position_equal(Position a, Position b);

void position_print(Position p);

#endif
