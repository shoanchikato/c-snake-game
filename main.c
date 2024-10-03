#include "game.h"
#include "include/raylib.h"
#include "position.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "snake.h"
#include "food.h"
#include <stdbool.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    InitWindow(WIDTH, HEIGHT, "Retro Snake");
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
            game_draw(game);

        EndDrawing();
    }

    CloseWindow();

    free_game(game);

    return 0;
}