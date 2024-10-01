#ifndef SNAKE_H
#define SNAKE_H

#include "include/raylib.h"
#include "position.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
typedef struct {
  Position *body;
  size_t body_len;
  Position direction;
  clock_t last_updated_time;
  bool can_grow;
} Snake;

Snake *snake_init();

void snake_draw(Snake *snake);

void snake_get_direction(Snake *snake);

void snake_movment(Snake *snake);

void snake_update(Snake *snake);

#endif
