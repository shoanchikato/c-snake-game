#include "include/raylib.h"
#include "position.h"
#include "food.h"
#include <stdlib.h>
#include "constants.h"
#include "util.h"
#include <stdio.h>


Food* food_init(Position *snake_body, size_t *len) {
    Texture2D t = get_texture("assets/graphics/food.png");
    Position *p = get_random_pos();

    // Allocate memory for the Food structure
    Food* food = (Food*) calloc(1, sizeof(Food));
    if(food == NULL) {
        printf("error allocating memory for food\n");
        exit(1);
    }

    // Set food properties
    food->position = *p;
    food->texture = t;
    food->snake_body_len = *len;
    food->snake_body = snake_body;

    return food;
}

void food_draw(Food* food) {
  DrawTexture(
    food->texture,
    OFFSET + food->position.x * CELLSIZE,
    OFFSET + food->position.y * CELLSIZE,
    WHITE
  );
}

void food_update(Food* food) {
  Position *pos = get_random_pos_avoid_collision(
    food->snake_body, 
    &food->snake_body_len
  );
  food->position = *pos;
}

void free_food(Food *food) {
  if(food == NULL) return;

  free(food);
  food = NULL;
}