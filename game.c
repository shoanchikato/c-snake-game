#include "position.h"
#include "food.h"
#include "snake.h"
#include "game.h"
#include "util.h"
#include <stdlib.h>
#include <stdio.h>

Game *GameInit(Snake *snake, Food *food) {
  Game *game = (Game*) malloc(sizeof(Game));
  if(game == NULL) {
    printf("Error allocating memory for game");
    exit(1);
    return NULL;
  }

  game->food = food;
  game->snake = snake;

  return game;
}

void GameUpdate(Game *g) {
  SnakeUpdate(g->snake);
  GameCheckCollision(g);
}

void GameDraw(Game *g) {
  SnakeDraw(g->snake);
  FoodDraw(g->food);
}

void GameCheckCollision(Game *g) {
  Position *a = g->snake->body[0];
  Position *b = g->food->position;
  if (PositionEqual(a, b)) {
    g->food->position = GetRandomPosAvoidCollision(g->snake->body, g->snake->bodyLen);
    g->snake->canGrow = true;
  }
}