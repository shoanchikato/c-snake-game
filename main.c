#include "constants.h"
#include "food.h"
#include "game.h"
#include "include/raylib.h"
#include "include/raymath.h"
#include "position.h"
#include "snake.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This is a port from
// https://github.com/educ8s/Cpp-Retro-Snake-Game-with-raylib

int main() {
  // Seed the random number generator
  srand(time(NULL));

  InitWindow(
    WIDTH + (2 * OFFSET), 
    HEIGHT + (2 * OFFSET), 
    "Retro Snake");
  SetTargetFPS(30);

  Snake *snake = snake_init();
  Food *food = food_init(snake->body, &snake->body_len);

  Game *game = game_init(snake, food);

  while (!WindowShouldClose()) {
    BeginDrawing();

    // Update
    game_update(game);

    // Restart game
    game_restart(game);

    // Draw
    ClearBackground(GREEN_N);
    DrawRectangleLinesEx(
      (Rectangle) {
        (float) OFFSET - 5,
        (float) OFFSET - 5,
        (float) WIDTH + 10,
        (float) HEIGHT + 10,
      }, 
      (float) BORDER_THICKNESS, 
      DARKGREEN_N
    );
    DrawText(
      "Retro Snake",
      OFFSET - 5,
      GAME_TITLE_Y,
      FONT_SIZE,
      DARKGREEN_N
    );
    DrawText(
      TextFormat("%i", game->score),
      OFFSET - 5,
      OFFSET + HEIGHT + 10,
      FONT_SIZE,
      DARKGREEN_N
    );
    game_draw(game);

    EndDrawing();
  }

  CloseWindow();

  free_game(game);

  return 0;
}