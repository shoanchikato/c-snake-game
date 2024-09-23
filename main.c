#include "game.h"
#include "include/raylib.h"
#include "position.h"
#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "snake.h"
#include "food.h"

// int main() {
//     Position* a = PositionInit(2, 3);
//     Position* b = PositionInit(1, 1);

//     Position* c = PositionAdd(a, b);


//     PositionPrint(c);
//     size_t len = 0;
//     Position** arr = NULL;

//     AppendElement((void**)&arr, &len, &a, sizeof(Position));
//     AppendElement((void**)&arr, &len, &b, sizeof(Position));
//     AppendElement((void**)&arr, &len, &c, sizeof(Position));

//     printf("LENGTH %zu\n", len);

//     for (size_t i = 0; i < len; i++) {
//         PositionPrint(arr[i]);
//     }


//     free(a);
//     free(b);
//     free(c);

//     return 0;
// }

int main() {
    InitWindow(WIDTH, HEIGHT, "Retro Snake");
    SetTargetFPS(60);

    Snake *snake = SnakeInit();
    Food *food = FoodInit(snake->body, snake->bodyLen);

    Game *game = GameInit(snake, food);

    while (!WindowShouldClose()) {
        BeginDrawing();

            // Update
            GameUpdate(game);
            
            // Draw
            ClearBackground(GREEN_N);
            GameDraw(game);

        EndDrawing();
    }

    CloseWindow();

    // free(snake);
    // free(food);
    // free(game);

    return 0;
}