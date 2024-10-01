#include "position.h"
#include "food.h"
#include "snake.h"
#include "game.h"
#include "util.h"
#include <stdlib.h>
#include <stdio.h>

Game *game_init(Snake *snake, Food *food) {
  Game *game = (Game*) calloc(1, sizeof(Game));
  if(game == NULL) {
    printf("Error allocating memory for game");
    exit(1);
  }

  game->food = food;
  game->snake = snake;

  return game;
}

void game_update(Game *g) {
  snake_update(g->snake);
  game_check_collision(g);
}

void game_draw(Game *g) {
  snake_draw(g->snake);
  food_draw(g->food);
}

void game_check_collision(Game *g) {
  Position *a = g->snake->body[0];
  Position b = g->food->position;
  if (position_equal(a, &b)) {
    Position *pos = get_random_pos_avoid_collision(g->snake->body, &g->snake->body_len);
    g->food->position = *pos;
    g->snake->can_grow = true;
  }
}