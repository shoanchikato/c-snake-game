#ifndef GAME_H
#define GAME_H

#include "position.h"
#include "food.h"
#include "snake.h"

typedef struct {
  Snake *snake;
  Food *food;
} Game;

Game *game_init(Snake *snake, Food *food);

void game_update(Game *g);

void game_draw(Game *g);

void game_check_collision(Game *g);

void free_game(Game *game);

#endif