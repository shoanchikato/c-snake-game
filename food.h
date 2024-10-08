#ifndef FOOD_H
#define FOOD_H

#include "position.h"
#include <stddef.h>
#include "include/raylib.h"

typedef struct {
  Position position;
  Texture2D texture;
  size_t snake_body_len;
  Position *snake_body;
} Food;

Food *food_init(
  Position *snake_body, 
  size_t *snake_body_len
);

void food_draw(Food *food);

void food_update(Food *food);

void free_food(Food *food);

#endif