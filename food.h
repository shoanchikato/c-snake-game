#ifndef FOOD_H
#define FOOD_H

#include "position.h"
#include "include/raylib.h"

typedef struct Food {
  Position *position;
  Texture2D texture;
  size_t *snakeBodyLen;
  Position **snakeBody;
} Food;

Food* FoodInit(
  Position** snakeBody, 
  size_t *snakeBodyLen
);

void FoodDraw(Food* food);

void FoodUpdate(Food* food);

#endif