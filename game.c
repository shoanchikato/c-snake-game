#include "constants.h"
#include "include/array_op.h"
#include "include/raylib.h"
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
  game->running = true;
  game->score = 0;

  InitAudioDevice();
  game->eat_sound = LoadSound("assets/sounds/eat.mp3");
  game->wall_sound = LoadSound("assets/sounds/wall.mp3");

  return game;
}

void game_update(Game *g) {
  if (g->running) {
    snake_update(g->snake);
    game_check_collision(g);
    game_check_collision_with_edges(g);
    game_check_collision_with_body(g);
  }
}

void game_draw(Game *g) {
  snake_draw(g->snake);
  food_draw(g->food);
}

void game_check_collision(Game *g) {
  Position a = g->snake->body[0];
  Position b = g->food->position;
  if (position_equal(a, b)) {
    Position *pos = get_random_pos_avoid_collision(g->snake->body, &g->snake->body_len);
    g->food->position = *pos;
    g->snake->can_grow = true;
    g->score++;
    PlaySound(g->eat_sound);
  }
}

void game_check_collision_with_edges(Game *g) {
  bool collision_x = g->snake->body[0].x >= CELLCOUNT ||
  g->snake->body[0].x <= -1;

  if (collision_x) {
    game_over(g);
  }

  bool collision_y = g->snake->body[0].y >= CELLCOUNT ||
  g->snake->body[0].y <= -1;

  if (collision_y) {
    game_over(g);
  }
}

void game_check_collision_with_body(Game *g) {
  bool collision = element_in_body(g->snake->body[0], &g->snake->body[1], g->snake->body_len-1);

  if (collision) {
    game_over(g);
  }
}

void game_restart(Game *g) {
  if (IsKeyPressed(KEY_UP) && g->snake->direction.y != 1) {
    g->snake->direction = *position_init(0, -1);
    g->running = true;
  } else if (IsKeyPressed(KEY_DOWN) && g->snake->direction.y != -1) {
    g->snake->direction = *position_init(0, 1);
    g->running = true;
  } else if (IsKeyPressed(KEY_LEFT) && g->snake->direction.x != 1) {
    g->snake->direction = *position_init(-1, 0);
    g->running = true;
  } else if (IsKeyPressed(KEY_RIGHT) && g->snake->direction.x != -1) {
    g->snake->direction = *position_init(1, 0);
    g->running = true;
  }
}

void game_over(Game *g) {
  snake_reset(g->snake);
  g->food->position = *get_random_pos_avoid_collision(g->snake->body, &g->snake->body_len);
  g->running = false;
  g->score = 0;
  PlaySound(g->wall_sound);
}

void free_game(Game *game) {
  if (game == NULL) return;

  UnloadSound(game->eat_sound);
  UnloadSound(game->wall_sound);
  CloseAudioDevice();

  free_food(game->food);
  free_snake(game->snake);
  free(game);

  game = NULL;
}