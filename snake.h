#include "position.h"
#include "include/raylib.h"
#include <stdbool.h>
#include <stdlib.h>

#ifndef SNAKE_H
#define SNAKE_H

typedef struct Snake {
  Position **body;
  size_t *bodyLen;
  Position *direction;
  float *lastUpdatedTime;
  bool canGrow;
} Snake;

Snake *SnakeInit();

void SnakeDraw(Snake *snake);

void SnakeGetDirection(Snake *snake);

void SnakeMovement(Snake *snake);

void SnakeUpdate(Snake *snake);

#endif
