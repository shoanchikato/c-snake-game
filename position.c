#include "position.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

Position *position_init(int x, int y) {
  Position* position = (Position*) malloc(sizeof(Position));
  if(position == NULL) {
    printf("Error allocating memory for position\n");
    exit(1);
  }
  
  position->x = x;
  position->y = y;

  return position;
}

void position_print(Position* p) {
  if (p != NULL) {
    printf("{x: %d, y:%d}\n", p->x, p->y);
  }
}

bool position_equal(Position* a, Position* b) {
  return a->x == b->x && a->y == b->y;
}

Position* position_add(Position* a, Position* b) {
  Position* p = (Position*) malloc(sizeof(Position));
  if(p == NULL) {
    printf("Error allocating memory for position");
    exit(1);
  }
  
  p->x = a->x + b->x;
  p->y = a->y + b->y;

  return p;
}
