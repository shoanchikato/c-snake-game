#include "include/raylib.h"
#include "position.h"
#include "food.h"
#include <stdlib.h>
#include <sys/_types/_null.h>
#include "constants.h"
#include "util.h"
#include <stdio.h>

Food* FoodInit(Position** s, size_t *len) {
  Texture2D t = GetTexture("assets/graphics/food.png");
  Position *p = GetRandomPos();

  Food* food = (Food*)malloc(sizeof(Food*));
  if(food == NULL) {
    printf("Error allocating memory for food");
    exit(1);
    return NULL;
  }


  food->position = p;
  food->texture = t;
  food->snakeBodyLen = len;
  food->snakeBody = s;

  return food;
}

void FoodDraw(Food* food) {
  DrawTexture(
    food->texture,
    food->position->x*CELLSIZE,
    food->position->y*CELLSIZE,
    WHITE
  );
}

void FoodUpdate(Food* food) {
  food->position = GetRandomPosAvoidCollision(food->snakeBody, food->snakeBodyLen);
}
