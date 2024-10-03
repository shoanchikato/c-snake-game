#include "position.h"
#include "include/raylib.h"
#include "snake.h"
#include "constants.h"
#include "util.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "include/array_op.h"

Snake *snake_init() {
  size_t body_len = 0;
  bool can_grow = false;
  Position *body = NULL;
  
  array_op_push_front((void**)&body, &body_len, position_init(6, 9),  sizeof(Position*));
  array_op_push_front((void**)&body, &body_len, position_init(5, 9),  sizeof(Position*));
  array_op_push_front((void**)&body, &body_len, position_init(4, 9),  sizeof(Position*));

  Position *direction = position_init(1, 0);

  Snake *snake = (Snake*) calloc(1, sizeof(Snake));
  if(snake == NULL) {
    printf("Error allocating memory for snake");
    exit(1);
  }

  clock_t last_updated_time = clock();

  snake->body = body;
  snake->body_len = body_len;
  snake->direction = *direction;
  snake->can_grow = can_grow;
  snake->last_updated_time = last_updated_time;

  return snake;
}

void snake_draw(Snake *snake) {
  for(size_t i = 0; i < snake->body_len; i++) {
    DrawRectangleRounded(
      (Rectangle) {
        snake->body[i].x*CELLSIZE,
        snake->body[i].y*CELLSIZE,
        CELLSIZE,
        CELLSIZE
      }, 
      0.5, 
      6, 
      DARKGREEN_N
      );
  }
}

void snake_get_direction(Snake *snake) {
  if (IsKeyPressed(KEY_UP) && snake->direction.y != 1) {
    snake->direction.x = 0;
    snake->direction.y = -1;
  } else if (IsKeyPressed(KEY_DOWN) && snake->direction.y != -1) {
    snake->direction.x = 0;
    snake->direction.y = 1;
  } else if (IsKeyPressed(KEY_LEFT) && snake->direction.x != 1) {
    snake->direction.x = -1;
    snake->direction.y = 0;
  } else if (IsKeyPressed(KEY_RIGHT) && snake->direction.x != -1) {
    snake->direction.x = 1;
    snake->direction.y = 0;
  }
}


void snake_movement(Snake *snake) {
  if (event_triggered(SNAKESPEED, &snake->last_updated_time)) {
    Position cell = *position_add(&snake->body[0], &snake->direction);

    array_op_push_front((void**)&snake->body,  &snake->body_len, &cell, sizeof(Position*));

    if (snake->can_grow) {
      snake->can_grow = false;
      return;
    }

    array_op_pop_back((void**)&snake->body, &snake->body_len, sizeof(Position*));
  }
}

void snake_update(Snake *snake) {
    snake_get_direction(snake);
    snake_movement(snake);
}

void free_snake(Snake *snake) {
  if(snake == NULL) return;

  free(snake->body);
  snake->body = NULL;

  free(snake);
  snake = NULL;
}