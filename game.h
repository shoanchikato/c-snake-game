#ifndef GAME_H
#define GAME_H

#include "position.h"
#include "food.h"
#include "snake.h"

typedef struct {
  Snake *snake;
  Food *food;
  bool running;
} Game;

Game *game_init(Snake *snake, Food *food);

void game_update(Game *g);

void game_draw(Game *g);

void game_check_collision(Game *g);

void game_check_collision_with_edges(Game *g);

void game_check_collision_with_body(Game *g);

void game_restart(Game *g);

void game_over(Game *g);

void free_game(Game *game);

#endif