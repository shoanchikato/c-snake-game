#include "position.h"
#include "include/raylib.h"
#include "snake.h"
#include "constants.h"
#include "util.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

Snake *SnakeInit() {
  size_t *bodyLen = malloc(sizeof(size_t));
  if(bodyLen == NULL) {
    printf("Error allocating memory for bodyLen");
    exit(1);
    return NULL;
  }
  *bodyLen = 0;

  bool canGrow = false;
  Position **body = NULL;

  Position *position1 = PositionInit(6, 9);
  Position *position2 = PositionInit(5, 9);
  Position *position3 = PositionInit(4, 9);
  
  AppendElement((void**)&body, bodyLen, &position1, sizeof(Position));
  AppendElement((void**)&body, bodyLen, &position2, sizeof(Position));
  AppendElement((void**)&body, bodyLen, &position3, sizeof(Position));

  Position *direction = PositionInit(1, 0);

  Snake *snake = (Snake*) malloc(sizeof(Snake));
  if(snake == NULL) {
    printf("Error allocating memory for snake");
    exit(1);
    return NULL;
  }

  float *lastUpdatedTime = malloc(sizeof(size_t));
  *lastUpdatedTime = 0;

  snake->body = body;
  snake->bodyLen = bodyLen;
  snake->direction = direction;
  snake->canGrow = canGrow;
  snake->lastUpdatedTime = lastUpdatedTime;


  return snake;
}

void SnakeDraw(Snake *snake) {
  for(size_t i = 0; i < *snake->bodyLen; i++) {
    DrawRectangleRounded(
      (Rectangle) {
        snake->body[i]->x*CELLSIZE,
        snake->body[i]->y*CELLSIZE,
        CELLSIZE,
        CELLSIZE
      }, 
      0.5, 
      6, 
      DARKGREEN_N
      );
  }
}

void SnakeGetDirection(Snake *snake) {
  if (IsKeyPressed(KEY_UP) && snake->direction->y != 1) {
    snake->direction->x = 0;
    snake->direction->y = -1;
  } else if (IsKeyPressed(KEY_DOWN) && snake->direction->y != -1) {
    snake->direction->x = 0;
    snake->direction->y = 1;
  } else if (IsKeyPressed(KEY_LEFT) && snake->direction->x != 1) {
    snake->direction->x = -1;
    snake->direction->y = 0;
  } else if (IsKeyPressed(KEY_RIGHT) && snake->direction->x != -1) {
    snake->direction->x = 1;
    snake->direction->y = 0;
  }
}


void SnakeMovement(Snake *snake) {
  if (EventTriggered(SNAKESPEED, snake->lastUpdatedTime)) {
    Position *cell = PositionAdd(snake->body[0], snake->direction);
    AppendElement(
      (void**)snake->body, 
      snake->bodyLen, 
      cell, 
      sizeof(Position)
    );

    if (snake->canGrow) {
      snake->canGrow = false;
      return;
    }

    RemoveFromBack((void**)snake->body, snake->bodyLen, sizeof(Position));
  }
}

void SnakeUpdate(Snake *snake) {
    SnakeGetDirection(snake);
    SnakeMovement(snake);
}