#ifndef GAME_H
#define GAME_H

#include "position.h"
#include "food.h"
#include "snake.h"

typedef struct Game {
  Snake *snake;
  Food *food;
} Game;

Game *GameInit(Snake *snake, Food *food);

void GameUpdate(Game *g);

void GameDraw(Game *g);

void GameCheckCollision(Game *g);

#endif